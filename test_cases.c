#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <arm_neon.h>

int8x8_t MuLawCompress(int16x8_t in);
int16x8_t MuLawDecompress(int8x8_t sample);

int test_comp(int8_t expected[8], int16_t input[8], int test_case)
{
    int8_t actual[8];
    vst1_s8(actual, MuLawCompress(vld1q_s16(input)));

    int errors;
    for(int i = 0; i < 8; i++)
    {
        if(expected[i] != actual[i])
        {
            printf("Test case %d failed.\nExpected Actual\n", test_case);
            for(int j = 0; j< 8; j++)
            {
                printf("%d        %d\n", expected[j], actual[j]);
            }
            return 1;
        }
    }
    printf("Test case %d passed!\n", test_case);
    return 0;
}

int test_decomp(int16_t expected[8], int8_t input[8], int test_case)
{
    int16_t actual[8];
    vst1q_s16(actual, MuLawDecompress(vld1_s8(input)));

    int errors;
    for(int i = 0; i < 8; i++)
    {
        if(expected[i] != actual[i])
        {
            printf("Test case %d failed.\nExpected Actual\n", test_case);
            for(int j = 0; j< 8; j++)
            {
                printf("%d        %d\n", expected[j], actual[j]);
            }
            return 1;
        }
    }
    printf("Test case %d passed!\n", test_case);
    return 0;
}

int main()
{

    printf("Compression tests\n");

    // Test 1: values that get compressed to zero
    int16_t input[8] = 
    { 
        0,
        1,
        2,
        4,
        8,
        10,
        12,
        15
    };
    int8_t expected[8] = 
    {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
    };
    test_comp(expected, input, 1);
    
    // Test 2: Values with a chord of zero
    int16_t i2[8] =
    {
        0x000f,
        0x0010,
        0x0020,
        0x0040,
        0x0068,
        0x0080,
        0x00A0,
        0x00FF
    };
    int8_t e2[8] = 
    {
        0x00,
        0x01,
        0x02,
        0x04,
        0x06,
        0x08,
        0x0A,
        0x0F
    };
    test_comp(e2, i2, 2);

    // Test 3: Min and max values of chord 0-3
    int16_t i3[8] = 
    {
        0x0010,
        0x00F0,
        0x0100,
        0x01F0,
        0x0200,
        0x03E0,
        0x0400,
        0x07C0
    };
    int8_t e3[8] =
    {
        0x01,
        0x0F,
        0x10,
        0x1F,
        0x20,
        0x2F,
        0x30,
        0x3F  
    };
    test_comp(e3, i3, 3);

    // Test 4: Min and max values of chords 4-7
    int16_t i4[8] = 
    {
        0x0800,
        0x0F80,
        0x1000,
        0x1F00,
        0x2000,
        0x3E00,
        0x4000,
        0x7C00
    };
    int8_t e4[8] =
    {
        0x40,
        0x4F,
        0x50,
        0x5F,
        0x60,
        0x6F,
        0x70,
        0x7F  
    };
    test_comp(e4, i4, 4);

    // Test 5: Negative values match positive values
        int16_t i5[8] = 
    {
        2048,
        -2048,
        3968,
        -3968,
        4096,
        -4096,
        7936,
        -7936,
    };
    int8_t e5[8] =
    {
        0x40,
        0xC0,
        0x4F,
        0xCF,
        0x50,
        0xD0,
        0x5F,
        0xDF,
    };
    test_comp(e5, i5, 5);

    // ------------------------------------------
    printf("Decompression tests\n");

    // 
}