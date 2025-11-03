#ifndef FUNCS
#define FUNCS

#include <stdlib.h>
#include <stdio.h>

char* dec_to_base2r(int number, int r);
void free_string(char* string);

int validate_parameters(int r);
int custom_abs(int number);
int count_digits(int number, int base);
char get_digit_char(int value);

#endif