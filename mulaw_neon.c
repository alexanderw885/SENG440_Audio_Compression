#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <arm_neon.h>

void printvec(int16x8_t out)
{
        int16_t temp_out[8];
        vst1q_s16(temp_out, out);
        for(int i = 0; i < 8; i++)
        {
            printf("%x\n", temp_out[i]);
        }
        printf("\n");
}

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

int main()
{
    int16_t temp[8] = { 0x7FFF,  
                        0x7C00, 
                        0x7CFF, 
                        0x7C0F, 
                        0x00F8, 
                        0x00FF, 
                        0x00FA, 
                        0x00FC};
    int16x8_t in = vld1q_s16(temp); // puts each value from array temp into vector in
    mulaw_neon(in);
    
    int16_t temp2[8] = { 0x000F,
                        0x0000,
                        0x0008,
                        0x0004,
                        0x0002,
                        0x0001,
                        0x000A,
                        0x0005,
    };
    in = vld1q_s16(temp2); // puts each value from array temp into vector in
    //mulaw_neon(in);
 
}