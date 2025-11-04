#ifndef FUNCS
#define FUNCS

#include <stdlib.h>
#include <stdio.h>

typedef enum {
    SUCCESS = 0,
    ERROR_NULL_POINTER,
    ERROR_MEMORY_ALLOCATION,
    ERROR_INVALID_PARAMETER,
    ERROR_OVERFLOW
} StatusCode;

StatusCode dec_to_base2r(int number, int r, char** result);
void free_string(char* string);

int validate_parameters(int r);
int custom_abs(int number);
int count_digits(int number, int base);
char get_digit_char(int value);

#endif