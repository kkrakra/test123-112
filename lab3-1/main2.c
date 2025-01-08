# include <stdio.h>
# include <stdlib.h>


void make_array(int** array, int capacity) {
    printf("Memory address of array - %p\n", &*array);
    *array = (int*)malloc(capacity * sizeof(int));
    if (*array == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

int* add_capacity(int** arrayPtr, int* capacity_p) {
    // Calculate new size (double the old size)
    (*capacity_p) = (*capacity_p) * 2;

    // Reallocate memory
    *arrayPtr = realloc(*arrayPtr, (*capacity_p) * sizeof(int));

    // Check if allocation was successful
    if (*arrayPtr == NULL) {
        printf("Memory reallocation failed\n");
        return NULL; // Return NULL to indicate failure
    }

    printf("New capacity - %d\n", *capacity_p);

    // If we got here, the reallocation succeeded
    return *arrayPtr;
}

void check_fix_capacity(int*array, int* size_p, int* capacity_p) {
    if (*size_p > *capacity_p - 1) {
        add_capacity(&array, capacity_p);
    }
}

void add_item(int* array, int* size_p, int* capacity_p, int position, int item) {

    if (position < 0 || position > (*capacity_p) - 1) {
        printf("Invalid index - %d\n", position);
        // exit(1);
        add_capacity(&array, capacity_p);
    }

    array[position] = item;

    (*size_p)++;
    printf("New size - %d\n", *size_p);
    printf("Element added, Array[%d] - %d\n", position, array[position]);
} 


void insertItemAtIndex(int* array, int* size_p, int index, int newItem) {
    // Check if the index is valid
    if (index < 0 || index > *size_p-1) {
        printf("Invalid index\n");
        return;
    }

    // Shift elements to the right
    for (int i = *size_p; i > index; i--) {
        // printf("a[%d] = a[%d]\n", i, i-1);
        array[i] = array[i - 1];
        // printf("%d\n", array[i]);
    }

    // Insert the new item
    array[index] = newItem;

    (*size_p)++;
    printf("New size - %d\n", *size_p);
    printf("Element added, Array[%d] - %d\n", index, array[index]);
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


void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void display_menu() {

    printf("Меню:\n");
    printf("1. Инициализация массива\n");
    printf("2. Вставка элемента\n");
    printf("3. Удаление элемента\n");
    printf("4. Индивидуальное задание\n");
    printf("5. Вывод массива\n");
    printf("0. Выход\n");
    printf("Ваш выбор: ");

}

int main() {


    int* array = NULL; //array
    int size = 0; //number of actual elements
    int* size_p = &size;
    
    int capacity = 3; //number of allocated memory cells
    int* capacity_p = &capacity;


    int choice; // cli inputs choice


    while (1) {
        display_menu();
        
        int result = scanf("%d", &choice);

        if (result == EOF) {
            printf("Обнаружен EOF\n");
            return 0;
        }        

        if (result != 1) {
            printf("Invalid input. Please enter a number.\n");
            // while (getchar() != '\n');
            fflush(NULL); 
            // choice = NULL;
            // result = 0;
            continue;
        }

        switch (choice) {
            case 1:
                printf("1. Инициализация массива\n");

                make_array(&array, capacity);
    
                printf("Sizeof - %ld\n", sizeof(array));
                
                add_item(array, size_p, capacity_p, 0, 7);
                add_item(array, size_p, capacity_p, 1, 10);
                add_item(array, size_p, capacity_p, 2, 12);

                break;
            case 2:
                printf("2. Вставка элемента\n");
                insertItemAtIndex(array, size_p, 2, 122);
                check_fix_capacity(array, size_p, capacity_p);

                insertItemAtIndex(array, size_p, 2, 123);
                check_fix_capacity(array, size_p, capacity_p);

                insertItemAtIndex(array, size_p, 2, 124);
                check_fix_capacity(array, size_p, capacity_p);

                insertItemAtIndex(array, size_p, 2, 125);
                check_fix_capacity(array, size_p, capacity_p);

                break;
            case 3:
                printf("3. Удаление элемента\n");
                
                removeItemAtIndex(array, size_p, 1);

                check_fix_capacity(array, size_p, capacity_p);
    
                break;
            case 4:
                printf("4. Индивидуальное задание\n");
                break;
            case 5:
                printf("5. Вывод массива\n");
                printf("Memory address of array - %p\n", &array);

                print_array(array, size);

                printf("Size - %d\n", size);
                printf("Capacity - %d\n", capacity);


                // print_array(array, size, capacity);
                break;
            case 0:
                printf("Quitting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        // Clear input buffer after each operation
        while (getchar() != '\n');
        // fflush(NULL);
    }

    free(array);

}



