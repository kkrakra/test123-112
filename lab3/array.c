#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int input_natural_number(const char* prompt) {
    int number;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &number) == 1 && number > 0) {
            return number;
        } else {
            printf("Ошибка: введите натуральное число (целое число больше 0).\n");
            while (getchar() != '\n');
        }
    }
}

int* initialize_array(int* size, int* capacity) {
    *size = input_natural_number("Введите размер массива: ");
    *capacity = *size;

    int* array = (int*)malloc(*capacity * sizeof(int));
    if (!array) {
        printf("Ошибка выделения памяти.\n");
        return NULL;
    }

    // for (int i = 0; i < *size; i++) {
    //     array[i] = input_natural_number("Введите элемент массива: ");
    // }
    for (int i = 0; i < *size; i++) {
        printf("Введите элемент массива.\n");
        scanf("%d", &array[i]);
    }
    return array;
}


int* insert_element(int* array, int* size, int* capacity, int index, int value) {
    if (*size >= *capacity) {
        *capacity *= 2;
        array = (int*)realloc(array, *capacity * sizeof(int));
        if (!array) {
            printf("Ошибка выделения памяти.\n");
            return NULL;
        }
    }

    if (index > *size) index = *size;

    for (int i = *size; i > index; i--) {
        array[i] = array[i - 1];
    }
    array[index] = value;
    *size++;
    return array;
}


int* delete_element(int* array, int* size, int* capacity, int index) {
    if (index >= *size) {
        printf("Ошибка: индекс вне диапазона.\n");
        return array;
    }

    for (int i = index; i < *size - 1; i++) {
        array[i] = array[i + 1];
    }
    (*size)--;

    if (*size < *capacity / 2 && *capacity > 1) {
        *capacity /= 2;
        array = (int*)realloc(array, *capacity * sizeof(int));
        if (!array && *size > 0) {
            printf("Ошибка выделения памяти.\n");
            return NULL;
        }
    }
    return array;
}

void print_array(int* array, int size, int capacity) {
    if (size == 0) {
        printf("Массив пуст. Емкость: %d\n", capacity);
        return;
    }

    printf("Массив (размер: %d, емкость: %d): ", size, capacity);
    for (int i = 0; i < size; i++) {
        printf("[%d]=%d ", i, array[i]);
    }
    printf("\n");
}