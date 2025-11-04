#include "funcs.h"

int main() {
    int test_numbers[] = {0, 1, 15, 16, 255, 1024, -1, -15, -255};
    int test_r[] = {1, 2, 3, 4, 5};
    
    int num_count = sizeof(test_numbers) / sizeof(test_numbers[0]);
    int r_count = sizeof(test_r) / sizeof(test_r[0]);
    
    for (int i = 0; i < num_count; i++) {
        for (int j = 0; j < r_count; j++) {
            char* result = NULL;
            StatusCode status = dec_to_base2r(test_numbers[i], test_r[j], &result);
            if (status == SUCCESS) {
                printf("Decimal: %d -> Base 2^%d (%d): %s\n", test_numbers[i], test_r[j], (1 << test_r[j]), result);
                free_string(result);
            }
            else {
                printf("Error: %d for number %d with base 2^%d\n", status, test_numbers[i], test_r[j]);
            }
        }
        printf("\n");
    }
    
    int additional_numbers[] = {42, 42, 42, 42, 42};
    int additional_r[] = {1, 2, 3, 4, 5};
    
    for (int i = 0; i < 5; i++) {
        char* result = NULL;
        StatusCode status = dec_to_base2r(additional_numbers[i], additional_r[i], &result);
        if (status == SUCCESS) {
            printf("Decimal: %d -> Base 2^%d (%d): %s\n", additional_numbers[i], additional_r[i], (1 << additional_r[i]), result);
            free_string(result);
        }
        else {
            printf("Error: %d for number %d with base 2^%d\n", status, additional_numbers[i], additional_r[i]);
        }
    }
    
    int boundary_numbers[] = {0, 1, -1, 2147483647};
    int boundary_r = 3;
    
    for (int i = 0; i < 4; i++) {
        char* result = NULL;
        StatusCode status = dec_to_base2r(boundary_numbers[i], boundary_r, &result);
        if (status == SUCCESS) {
            printf("Decimal: %d -> Base 2^%d (%d): %s\n", boundary_numbers[i], boundary_r, (1 << boundary_r), result);
            free_string(result);
        }
        else {
            printf("Error: %d for number %d with base 2^%d\n", status, boundary_numbers[i], boundary_r);
        }
    }
    return SUCCESS;
}