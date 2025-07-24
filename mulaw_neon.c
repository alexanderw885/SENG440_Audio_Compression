#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <arm_neon.h>

int8x8_t mulaw_neon(int16x8_t in)
{

    int16x8_t constant = vdupq_n_s16(0x8000);
    int16x8_t signs = vandq_s16(in, constant); // save the signs, 0=positive
    in = vabsq_s16(in);                         // get absolute value

    // Some values are too small, and need to be removed. We can do this by setting them to the smallest value
    // that we can handle, that we map to zero
    constant = vdupq_n_s16(0x0080);
    in = vmaxq_s16(in, constant);

    // Get right shift amount
    int16x8_t clz = vclzq_s16(in);
    constant = vdupq_n_s16(11);
    clz = vsubq_s16(constant, clz);
    clz = vnegq_s16(clz);//negate for a right shift

    // Shift
    int16x8_t out = vshlq_s16(in, clz);

    // Add in chord
    // First, remove bit in position 5
    constant = vdupq_n_s16(0x000F);
    out = vandq_s16(out, constant);
    // Get chord value
    clz = vabsq_s16(clz);
    constant = vdupq_n_s16(3);
    clz = vsubq_s16(clz, constant);
    clz = vshlq_n_s16(clz, 4);
    // add in chord
    out = vorrq_s16(out, clz);


    // add back sign
    signs = vshrq_n_s16(signs, 8);
    out = vorrq_s16(out, signs);

    return vmovn_s16(out);
}