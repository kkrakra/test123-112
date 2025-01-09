#include <stdio.h>
#include <stdlib.h>


int is_decreased(int b) {
    // 0 - если не уменьшается
    // 1 - если уменьшается
    int pred_digit = 0;
    while (b > 0) {
        int sled_digit = b % 10;
        if (sled_digit <= pred_digit) {
            return 0;
        }
        pred_digit = sled_digit;
        b /= 10;
    }

    return 1;
}


void removeItemAtIndex(int* array, int* size_p, int index) {
    // Check if the index is valid
    if (index < 0 || index >= *size_p) {
        printf("Invalid index\n");
        return;
    }

    // Shift elements to the left
    for (int i = index; i < *size_p - 1; i++) {
        array[i] = array[i + 1];
    }

    // Decrement the size
    (*size_p)--;
}


int main() {


    int* a1_ptr = NULL;
    int capacity = 4;
    int* size_p = &capacity;
    int size_of_item = sizeof(int);

    a1_ptr = malloc(capacity*size_of_item);

    a1_ptr[0] = 123;
    a1_ptr[1] = 121;
    a1_ptr[2] = 321;
    a1_ptr[3] = 221;

    // #Блок для нового массива
    //посчитаем длину нового массива
    int new_array_size = 0;

    for (int i=0; i<capacity; i++) {
        printf("%d\n", a1_ptr[i]);
        if (is_decreased(a1_ptr[i]) == 1) {
            printf("%d - is_decreased\n", a1_ptr[i]);
            new_array_size++;
        }

    }
    printf("\n");

    printf("Длина нового массива будет - %d\n", new_array_size);
    int* a2_ptr = NULL;
    a2_ptr = malloc(new_array_size*size_of_item);
    int j = 0;
    for (int i=0; i<capacity; i++) {
        printf("%d\n", a1_ptr[i]);
        if (is_decreased(a1_ptr[i]) == 1) {
            printf("%d - добавлено в новый массив\n", a1_ptr[i]);
            a2_ptr[j] = a1_ptr[i];
            
        }
    }

    for (int i=0; i<capacity; i++) {
        printf("%d\n", a1_ptr[i]);
        if (is_decreased(a1_ptr[i]) == 1) {
            printf("%d - удалено из старого массива\n", a1_ptr[i]);
            removeItemAtIndex(a1_ptr, size_p, i);
            
        }
    }



    // посмотрим новый массив
    printf("Новый массив - ");
    for (int i=0; i<new_array_size; i++) {
        printf("%d ", a2_ptr[i]);
    }
    printf("\n");

    // посмотрим измененный старый массив
    printf("Старый массив - ");
    for (int i=0; i<capacity; i++) {
        printf("%d ", a1_ptr[i]);
    }
    printf("\n");


    return 0;
}
