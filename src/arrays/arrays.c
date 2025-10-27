//
// Created by Carlos José Requena Jiménez on 16/10/25.
//

#include "arrays.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define  MAX_CAPACITY 100
#define  DECK_SIZE 52

/**
 * @brief Prints the values and memory addresses of elements in a local integer array.
 *
 * This function demonstrates how arrays are stored in contiguous memory locations in C.
 * It defines a local integer array of 10 elements, calculates its size dynamically,
 * and prints each element’s value along with its corresponding memory address.
 *
 * @note The array is allocated on the stack, not on the heap. Its lifetime ends when the function returns.
 * @note This function is primarily for educational or debugging purposes to visualize
 *       how array elements are laid out in memory.
 *
 * @return void This function does not return a value.
 */
void printArrayAddresses(void) {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(array) / sizeof(int);
    for (int i = 0; i < size; i++) {
        printf("array[%d] = %d :: address = %p\n", i, array[i], array + i);
    }
}

/**
 * @brief Allocates and initializes an integer array on the heap.
 *
 * This function dynamically allocates memory for an integer array of a fixed size (10 elements),
 * initializes each element with its index value (i.e., array[i] = i),
 * and returns a pointer to the first element of the array.
 *
 * In C, you cannot return an array directly from a function (e.g., int[] returnArray(void)).
 * However, you can return a pointer to an array element (e.g., int *returnArray(void)).
 *
 * Important notes:
 * @note 1. You must not return a pointer to a local (stack) array, as its memory is released when the function exits.
 * @note 2. To safely return an array, allocate it dynamically using malloc() or calloc(), which reserves memory on the heap.
 * @note 3. The caller of the function is responsible for freeing the allocated memory after use.
 * @note This function is primarily for educational.
 *
 * @return int* Pointer to the allocated integer array.
 * @retval NULL If memory allocation fails.
 */
int *returnAnArrayFromAfunction(void) {
    int size = 10;
    int *arrayPtr = calloc(size, sizeof(int));
    if (arrayPtr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        arrayPtr[i] = i;
    }

    return arrayPtr;
}

void mergeTwoSortedArrays(const int a[], const size_t n, const int b[], size_t m, int c[]) {
    if (a == NULL  || b == NULL || c == NULL || n <= 0 || m <= 0) {
        printf("Error: invalid array or size.\n");
        return;
    }

    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            c[k] = a[i];
            k++;
            i++;
        } else {
            c[k] = b[j];
            k++;
            j++;
        }
    }
    while (i < n) {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j < m) {
        c[k] = b[j];
        k++;
        j++;
    }
}

int* mergeTwoSortedArraysV2(const int a[], const size_t n, const int b[], size_t m) {
    size_t size = n + m;
    int* c = calloc(size, sizeof(int));
    if (c == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
    }
    mergeTwoSortedArrays(a,n,b,m,c);
    return c;
}

int findTheMinimum(const int a[], int size) {
    if (a == NULL || size <= 0) {
        printf("Error: invalid array or size.\n");
        return INT_MIN;  // indicate an error
    }

    int min = a[0];
    printf("Array size: %d\n", size);
    printf("Initial min: %d\n", min);

    for (int i = 1; i < size; i++) {
        printf("Checking element a[%d] = %d\n", i, a[i]);
        if (a[i] < min) {
            min = a[i];
            printf("New min found: %d\n", min);
        }
    }
    return min;
}

int findTheMaximum(const int a[], int size) {
    if (a == NULL || size <= 0) {
        printf("Error: invalid array or size.\n");
        return INT_MIN;  // indicate an error
    }

    int max = a[0];
    printf("Array size: %d\n", size);
    printf("Initial max: %d\n", max);

    for (int i = 1; i < size; i++) {
        printf("Checking element a[%d] = %d\n", i, a[i]);
        if (a[i] > max) {
            max = a[i];
            printf("New max found: %d\n", max);
        }
    }

    printf("Final max: %d\n", max);
    return max;
}

int insertIntoArray(int a[], int size, int atIndex, int value) {
    if (atIndex < 0 || atIndex >= size) {
        printf("Error: Index out of range.\n");
        return 1;
    }
    for (int i = size; i > atIndex; i--) {
        a[i] = a[i - 1];
    }
    a[atIndex] = value;
    return 0;
}

void basicSort(int a[], int size, bool ascending) {
    if (a == NULL || size <= 0) {
        printf("Error: invalid array or size.\n");
        return;
    }
    int counter = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if ((ascending && a[j] > a[j + 1]) || (!ascending && a[j] < a[j + 1])) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
            counter++;
        }
    }
    printf("Counter Loops: %d\n", counter);
}

/**
 * @brief Sorts an integer array using the bubble sort algorithm.
 *
 * The function repeatedly steps through the array, compares adjacent elements,
 * and swaps them if they are in the wrong order. The process continues until
 * no swaps are needed, meaning the array is sorted.
 *
 * If the `ascending` flag is set to `true`, the function sorts the array in
 * ascending order; if set to `false`, it sorts in descending order.
 *
 * Additionally, after each pass, the function prints which element has been
 * placed in its correct position for visualization and learning purposes.
 *
 * @param a          The array of integers to sort.
 * @param size       The number of elements in the array.
 * @param ascending  Boolean flag indicating sorting order:
 *                   - `true` for ascending order
 *                   - `false` for descending order
 *
 * @note The sorting is done in place; no additional array is created.
 * @note The function uses the do-while loop to continue until no swaps occur.
 *
 *
 * @return None
 *
 * @see https://en.wikipedia.org/wiki/Bubble_sort
 *
 * @example
 * // Example usage:
 * #include <stdio.h>
 * #include <stdbool.h>
 *
 * int main(void) {
 *     int arr[] = {5, 3, 8, 4, 2};
 *     int size = sizeof(arr) / sizeof(arr[0]);
 *
 *     // Sort array in ascending order
 *     bubbleSort(arr, size, true);
 *
 *     printf("Sorted array: ");
 *     for (int i = 0; i < size; i++)
 *         printf("%d ", arr[i]);
 *     printf("\n");
 *
 *     return 0;
 * }
 */
void bubbleSort(int a[], int size, bool ascending) {
    if (a == NULL || size <= 0) {
        printf("Error: invalid array or size.\n");
        return;
    }
    bool swapped=false;
    int i=0;
    int counter = 0;
    do {
        swapped = false;
        for (int j = 0; j < size - 1 - i; j++) {
            if ((ascending && a[j] > a[j + 1]) || (!ascending && a[j] < a[j + 1])) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = true;
            }
            counter++;
        }
        printf("After pass %d, last element is a[%d] = %d\n",i + 1, size - 1 - i, a[size - 1 - i]);
        i++;
    } while (swapped);
    printf("Counter Loops: %d\n", counter);
}

void shuffle(int a[], int size) {
    srand(  time(NULL)  );
    for (int i = 0; i < size; i++) {
        int swapIndex = rand() % size;
        int temp = a[i];
        a[i] = a[swapIndex];
        a[swapIndex] = temp;
    }
}

// int main(void) {
//
//     printArrayAddresses();
//     int* arrayPtr = returnAnArrayFromAfunction();
//     for (int i = 0; i < 10; i++) {
//         printf("array[%d] = %d\n", i, arrayPtr[i]);
//     }
//     free(arrayPtr);
//
//     const int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 50,51,52};
//     const int n = sizeof(a) / sizeof(int);
//     int b[] = {21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
//     const int m = sizeof(b) / sizeof(int);
//     int k = n + m;
//     int c[k];
//     mergeTwoSortedArrays(a, n, b, m, c);
//     for (int i = 0; i < k; i++) {
//         printf("%d\n", c[i]);
//     }
//
//     printf("=========================\n");
//
//     int* d = mergeTwoSortedArraysV2(a, n, b, m);
//     for (int i = 0; i < k; i++) {
//         printf("%d\n", d[i]);
//     }
//     free(d);
//
//     printf("=========================\n");
//     int e[] = {500,2, 3, 4, 5, 6, 7, -369,800, 8, 9, 10, 369,50,51,52,600};
//     int size = sizeof(e) / sizeof(int);
//     int min = findTheMinimum(e,size);
//     printf("The min is: %d\n", min);
//     int max = findTheMaximum(e,size);
//     printf("The max is: %d\n", max);
//
//     printf("=========================\n");
//     int f[] = {500,2, 3, 4, 5, 6, 7, -369,800, 8, 9, 10, 369,50,51,52,600};
//     size = sizeof(f) / sizeof(int);
//     insertIntoArray(f,size,0,100);
//     for (int i = 0; i < size; i++) {
//         printf("f[%d]= %d\n",i, f[i]);
//     }
//
//
//     int g[] = {500,2, 3, 4, 5, 6, 7, -369,800, 8};
//     size = sizeof(g) / sizeof(int);
//     bubbleSort(g,size, true);
//
//     printf("=========================\n");
//     for (int i = 0; i < size; i++) {
//         printf("f[%d]= %d\n",i, g[i]);
//     }
//
//     printf("=========================\n");
//     int h[DECK_SIZE];
//     for (int i = 0; i < DECK_SIZE; i++) {
//         h[i] = i+1;
//     }
//     size = sizeof(h) / sizeof(int);
//     shuffle(h,size);
//     for (int i = 0; i < DECK_SIZE; i++) {
//         printf("%d\n", h[i]);
//     }
//
//     return 0;
// }
