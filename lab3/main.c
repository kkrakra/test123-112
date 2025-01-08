#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "task.h"




int input_non_negative_number(const char* prompt) {
    int number;
    while (1) {
        printf("%s", prompt);

        // if (scanf("%d", &number) == EOF) {
        //     printf("\nОбнаружен EOF. Завершение программы.\n");
        //     return EOF;
        // }

        if (scanf("%d", &number) == 1 && number >= 0) {
            return number; 
        } else {
            printf("Ошибка: введите неотрицательное число (0 или больше).\n");
            while (getchar() != '\n'); 
        }


        // if (&number == NULL) {
        //     // EOF reached, exit the loop
        //     break;
        // } 
        
        
    }
}

void menu() {
    int* array = NULL;
    int size = 0;
    int capacity = 0;
    int choice;

    do {
        printf("\nМеню:\n");
        printf("1. Инициализация массива\n");
        printf("2. Вставка элемента\n");
        printf("3. Удаление элемента\n");
        printf("4. Индивидуальное задание\n");
        printf("5. Вывод массива\n");
        printf("0. Выход\n");
        printf("Ваш выбор: ");

        if (scanf("%d", &choice) == EOF) {
            printf("\nОбнаружен EOF. Завершение программы.\n");
            break;
        }



        switch (choice) {
            case 1:
                if (array) {
                    free(array);
                    array = NULL;
                    // size = 0;
                    // capacity = 0;
                }
                array = initialize_array(&size, &capacity);
                print_array(array, size, capacity);
                break;
            case 2: {
                int index = input_non_negative_number("Введите индекс для вставки: ");
                // if (index == EOF) {
                //     printf("\nОбнаружен EOF. Завершение программы.\n");
                //     break;
                // }
                int value = input_natural_number("Введите значение для вставки: ");
                array = insert_element(array, &size, &capacity, index, value);
                print_array(array, size, capacity);
                break;
            }
            case 3: {
                int index = input_non_negative_number("Введите индекс для удаления: ");
                array = delete_element(array, &size, &capacity, index);
                print_array(array, size, capacity);
                break;
            }
            case 4: {
                int new_size;
                int* new_array = process_array(array, &size, &capacity, &new_size);
                printf("Новый массив (убывающие числа): ");
                print_array(new_array, new_size, capacity);
                printf("Текущий массив после обработки: ");
                print_array(array, size, capacity);
                free(new_array);
                break;
            }

            case 5:
                print_array(array, size, capacity);
                break;
            case 0:
                break;
            default:
                printf("Неверный выбор.\n");
        }
    
        // if (scanf("%d", &choice) == EOF) {
        //     printf("\nОбнаружен EOF. Завершение программы.\n");
        //     break;
        // }
    
    } while (choice != 0 || &choice != NULL);

    free(array);
}


int main() {
    menu(); 
    return 0;
}