//
// Created by Carlos José Requena Jiménez on 16/10/25.
//

#include "arrays.h"
#include <stdio.h>

void printArrayAddresses(void) {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(array) / sizeof(int);
    for (int i = 0; i < size; i++) {
        printf("array[%d] = %d :: address = %p\n", i, array[i], array + i);
    }
}

// int main(void) {
//     printArrayAddresses();
// }