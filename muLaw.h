#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <arm_neon.h>

static inline int8x8_t MuLawCompress(int16x8_t in)
{
    int16x8_t constant = vdupq_n_s16(0x8000);
    int16x8_t signs = vandq_s16(in, constant); // save the signs, 0=positive
    in = vabsq_s16(in);                         // get absolute value

    // Get right shift amount
    int16x8_t clz = vclzq_s16(in);

    constant = vdupq_n_s16(11);
    int16x8_t shift = vsubq_s16(constant, clz);
    // the minimum shift is 4, so we clamp the value
    constant = vdupq_n_s16(4);
    shift = vmaxq_s16(constant, shift);
    shift = vnegq_s16(shift);//negate for a right shift

    // Shift
    int16x8_t out = vshlq_s16(in, shift);

    // Add in chord
    // First, all but the 4 least significant bits
    constant = vdupq_n_s16(0x000F);
    out = vandq_s16(out, constant);

    // Get chord value
    constant = vdupq_n_s16(8);
    clz = vsubq_s16(constant, clz);
    // clamp to 0, shift into place to add to result
    constant = vdupq_n_s16(0);
    clz = vmaxq_s16(clz, constant);
    clz = vshlq_n_s16(clz, 4);
    // add in chord
    out = vorrq_s16(out, clz);


    // add back sign
    signs = vshrq_n_s16(signs, 8);
    out = vorrq_s16(out, signs);
    int8x8_t out8x8 = vmovn_s16(out);
    return out8x8;
}

static inline int16x8_t MuLawDecompress(int8x8_t sample)
{
    int8x8_t chord_mask = vdup_n_s8(0x70);
    int8x8_t step_mask = vdup_n_s8(0x0f);

    int8x8_t chord = vand_s8(sample, chord_mask);
    chord = vshr_n_s8(chord, 4); // sets chord range to [0,7]
    int8x8_t sign = vshr_n_s8(sample, 7); // arithmetic shift, not logical. It returns -1 if negative, 0 otherwise
    int16x8_t out = vmovl_s8(sample);

    // Remove all extra bits from the step value
    int16x8_t constant = vdupq_n_s16(0x000F);
    out = vandq_s16(out, constant);


    // add left 3, add bias, and shift left by clz
    out = vshlq_n_s16(out, 3);
    constant = vdupq_n_s16(0x0084);
    out = vaddq_s16(out, constant);
    int16x8_t temp = vmovl_s8(chord);

    // Shift left
    temp = vmovl_s8(chord);
    out = vshlq_s16(out, temp);

    // To add back the sign, I'm going to make a vector with the following rules:
    // if sign = 0, set that value to 1
    // if sign = 1, set that value to -1.
    // We accomplish that by inverting all negative values, and then adding 1
    temp = vmovl_s8(sign);
    out = veorq_s16(out, temp);
    out = vsubq_s16(out, temp);

    return out;
}