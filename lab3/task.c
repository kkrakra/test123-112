#include <stdlib.h>
#include <stdio.h>
#include "task.h"
#include "array.h"

int is_decreasing(int number) {
    int prev_digit = 0;  
    while (number > 0) { 
        int current_digit = number % 10;
        if (current_digit <= prev_digit) return 0;  
        prev_digit = current_digit;
        number /= 10;
    }
    return 1;  
}

int* process_array(int* array, int* size, int* capacity, int* new_size) {
    int* new_array = NULL;  
    *new_size = 0;         

    for (int i = 0; i < *size; i++) {
        if (is_decreasing(array[i])) {
            new_array = (int*)realloc(new_array, (*new_size + 1) * sizeof(int));
            if (!new_array) {
                printf("Ошибка выделения памяти.\n");
                return NULL;
            }
            new_array[*new_size] = array[i];
            (*new_size)++;


            array = delete_element(array, size, capacity, i);
            i--;
        }
    }
    return new_array;
}