#include "funcs.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test_validate_parameters() {
    printf("Testing validate_parameters...\n");
    
    assert(validate_parameters(1) == 1);
    assert(validate_parameters(3) == 1);
    assert(validate_parameters(5) == 1);
    
    assert(validate_parameters(0) == 0);
    assert(validate_parameters(6) == 0);
    assert(validate_parameters(-1) == 0);
    
    printf("validate_parameters tests passed!\n");
}

void test_custom_abs() {
    printf("Testing custom_abs...\n");
    
    assert(custom_abs(0) == 0);
    assert(custom_abs(5) == 5);
    assert(custom_abs(-5) == 5);
    assert(custom_abs(100) == 100);
    assert(custom_abs(-100) == 100);
    assert(custom_abs(2147483647) == 2147483647);
    
    printf("custom_abs tests passed!\n");
}

void test_count_digits() {
    printf("Testing count_digits...\n");
    
    assert(count_digits(0, 1) == 1);
    assert(count_digits(0, 3) == 1);
    
    assert(count_digits(1, 1) == 1);
    assert(count_digits(2, 1) == 2);
    assert(count_digits(15, 4) == 1);
    assert(count_digits(16, 4) == 2);
    
    assert(count_digits(-1, 1) == 1);
    assert(count_digits(-15, 4) == 1);
    
    printf("count_digits tests passed!\n");
}

void test_get_digit_char() {
    printf("Testing get_digit_char...\n");
    
    assert(get_digit_char(0) == '0');
    assert(get_digit_char(5) == '5');
    assert(get_digit_char(9) == '9');
    
    assert(get_digit_char(10) == 'A');
    assert(get_digit_char(15) == 'F');
    assert(get_digit_char(20) == 'K');
    assert(get_digit_char(31) == 'V');
    
    printf("get_digit_char tests passed!\n");
}

void test_dec_to_base2r_basic() {
    printf("Testing dec_to_base2r basic functionality...\n");
    
    char* result = NULL;
    StatusCode status;
    
    status = dec_to_base2r(0, 3, &result);
    assert(status == SUCCESS);
    assert(strcmp(result, "0") == 0);
    free_string(result);
    
    status = dec_to_base2r(5, 1, &result);
    assert(status == SUCCESS);
    assert(strcmp(result, "101") == 0);
    free_string(result);
    
    status = dec_to_base2r(-5, 1, &result);
    assert(status == SUCCESS);
    assert(strcmp(result, "-101") == 0);
    free_string(result);
    
    printf("dec_to_base2r basic tests passed!\n");
}

void test_dec_to_base2r_different_bases() {
    printf("Testing dec_to_base2r with different bases...\n");
    
    char* result = NULL;
    StatusCode status;
    
    status = dec_to_base2r(42, 1, &result);
    assert(status == SUCCESS);
    assert(strcmp(result, "101010") == 0);
    free_string(result);
    
    status = dec_to_base2r(42, 2, &result);
    assert(status == SUCCESS);
    assert(strcmp(result, "222") == 0);
    free_string(result);
    
    status = dec_to_base2r(42, 3, &result);
    assert(status == SUCCESS);
    assert(strcmp(result, "52") == 0);
    free_string(result);
    
    status = dec_to_base2r(42, 4, &result);
    assert(status == SUCCESS);
    assert(strcmp(result, "2A") == 0);
    free_string(result);
    
    status = dec_to_base2r(42, 5, &result);
    assert(status == SUCCESS);
    assert(strcmp(result, "1A") == 0);
    free_string(result);
    
    printf("dec_to_base2r different bases tests passed!\n");
}

void test_dec_to_base2r_boundary_values() {
    printf("Testing dec_to_base2r boundary values...\n");
    
    char* result = NULL;
    StatusCode status;
    
    status = dec_to_base2r(1000000000, 3, &result);
    assert(status == SUCCESS);
    assert(result != NULL);
    assert(result[0] != '\0');
    free_string(result);
    
    status = dec_to_base2r(-1000000000, 3, &result);
    assert(status == SUCCESS);
    assert(result != NULL);
    assert(result[0] == '-');
    free_string(result);
    
    printf("dec_to_base2r boundary values tests passed!\n");
}

void test_dec_to_base2r_error_cases() {
    printf("Testing dec_to_base2r error cases...\n");
    
    char* result = NULL;
    StatusCode status;
    
    status = dec_to_base2r(10, 0, &result);
    assert(status == ERROR_INVALID_PARAMETER);
    assert(result == NULL);
    
    status = dec_to_base2r(10, 6, &result);
    assert(status == ERROR_INVALID_PARAMETER);
    assert(result == NULL);
    
    status = dec_to_base2r(10, -1, &result);
    assert(status == ERROR_INVALID_PARAMETER);
    assert(result == NULL);
    
    status = dec_to_base2r(10, 2, NULL);
    assert(status == ERROR_NULL_POINTER);
    
    printf("dec_to_base2r error cases tests passed!\n");
}

void test_free_string() {
    printf("Testing free_string...\n");
    
    free_string(NULL);
    
    char* str = malloc(10);
    strcpy(str, "test");
    free_string(str);
    
    printf("free_string tests passed!\n");
}

int main() {
    printf("Running all number conversion tests...\n\n");
    
    test_validate_parameters();
    test_custom_abs();
    test_count_digits();
    test_get_digit_char();
    test_dec_to_base2r_basic();
    test_dec_to_base2r_different_bases();
    test_dec_to_base2r_boundary_values();
    test_dec_to_base2r_error_cases();
    test_free_string();
    
    printf("\nAll tests completed successfully!\n");
    return SUCCESS;
}