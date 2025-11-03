#include "funcs.h"

int validate_parameters(int r) {
    return (r >= 1 && r <= 5);
}

int custom_abs(int number) {
    int mask = number >> (sizeof(int) * 8 - 1);
    return (number + mask) ^ mask;
}

int count_digits(int number, int base) {
    int count = 0;
    int temp = custom_abs(number);

    if (temp == 0) {
        return 1;
    }

    while (temp != 0) {
        count++;
        temp = temp >> base;
    }
    return count;
}

char get_digit_char(int value) {
    if (value < 10) {
        return '0' + value;
    }
    else {
        return 'A' + (value - 10);
    }
}

char* dec_to_base2r(int number, int r) {
    if (!validate_parameters(r)) {
        return NULL;
    }

    int base_shift = r;
    int base = 1 << r;
    int mask = base - 1;

    if (number == 0) {
        char* result = (char*)malloc(2 * sizeof(char));
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    int is_negative = (number >> (sizeof(int) * 8 - 1)) & 1;
    int abs_number = custom_abs(number);
    int digit_count = count_digits(number, base_shift);

    int sign_length = 0;
    if (is_negative) {
        sign_length = 1;
    }
    
    int length = digit_count + sign_length + 1;
    char* result = (char*)malloc(length * sizeof(char));

    if (result == NULL) {
        return NULL;
    }

    int index = digit_count + sign_length;
    result[index] = '\0';
    index--;
    int temp = abs_number;
    
    while (temp != 0) {
        int digit = temp & mask;
        result[index] = get_digit_char(digit);
        index--;
        temp = temp >> base_shift;
    }

    if (is_negative) {
        result[0] = '-';
    }
    return result;
}

void free_string(char* string) {
    if (string != NULL) {
        free(string);
    }
}