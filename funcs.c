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