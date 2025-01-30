#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#define CLEAR_CIN 1


extern int CHAR_NAME_LIMIT;
extern int CHAR_INPUT_LIMIT;


char* sil_Cin(char* input, int input_len, _Bool clear_cin);
