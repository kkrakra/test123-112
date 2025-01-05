#ifndef ARRAY_H
#define ARRAY_H

int* initialize_array(int* size, int* capacity);
int* insert_element(int* array, int* size, int* capacity, int index, int value);
int* delete_element(int* array, int* size, int* capacity, int index);
void print_array(int* array, int size, int capacity);

int input_natural_number(const char* prompt);
int input_non_negative_number(const char* prompt);

#endif