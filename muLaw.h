#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <arm_neon.h>

int8x8_t MuLawCompress(int16x8_t in);
int16x8_t MuLawDecompress(int8x8_t sample);