/**
 * @file memory_allocation.c
 * @brief Demonstrates all major types of memory allocation in C.
 *
 * This program shows how different kinds of memory are used by a C program:
 * - **Text segment**: where compiled instructions (functions) reside.
 * - **Data segment (.data)**: stores initialized global and static variables.
 * - **BSS segment (.bss)**: stores uninitialized global and static variables.
 * - **Heap**: used for dynamically allocated memory (malloc, calloc, realloc).
 * - **Stack**: used for local (automatic) variables and function call frames.
 *
 * Each variable and function in this program is used to illustrate
 * where it resides in memory, and its address is printed for inspection.
 *
 * @author
 * @date    2025-10-12
 */
#include "memory_allocation.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @var global_init
 * @brief Initialized global variable stored in the **.data** segment.
 */
int global_init = 10;

/**
 * @var global_uninit
 * @brief Uninitialized global variable stored in the **.bss** segment.
 */
int global_uninit;

/**
 * @var static_init
 * @brief Initialized static variable stored in the **.data** segment.
 */
static int static_init = 20;

/**
 * @var static_uninit
 * @brief Uninitialized static variable stored in the **.bss** segment.
 */
static int static_uninit;

/**
 * @brief Simple function used to demonstrate the **text segment**.
 *
 * The compiled machine code of this function resides in the **text segment**,
 * which is typically marked as read-only and contains executable instructions.
 */
void show_memory_regions(void) {
    printf("Inside show_memory_regions() function\n");
}

/**
 * @brief Program entry point.
 *
 * The `printMemoryAllocation()` function declares a local (stack) variable and performs several
 * heap allocations using `malloc()`, `calloc()`, and `realloc()`.
 * It then prints out the memory addresses of:
 * - Text segment (function)
 * - Data segment (.data)
 * - BSS segment (.bss)
 * - Stack (local variable)
 * - Heap (dynamically allocated memory)
 *
 * Finally, it frees all heap memory before exiting.
 *
 * @return 0 on successful execution.
 */
int printMemoryAllocation(void) {
    /** Local (stack) variable. Stored in the **stack segment**. */
    int stack_var = 30;

    /** Pointer to heap memory allocated using malloc(). */
    int *heap_malloc = (int *)malloc(sizeof(int));
    *heap_malloc = 40;

    /** Pointer to heap memory allocated using calloc(). */
    int *heap_calloc = (int *)calloc(1, sizeof(int));
    *heap_calloc = 50;

    /** Pointer to heap memory reallocated using realloc(). */
    int *heap_realloc = (int *)malloc(sizeof(int) * 2);
    heap_realloc[0] = 60;
    heap_realloc = (int *)realloc(heap_realloc, sizeof(int) * 4);
    heap_realloc[1] = 70;

    printf("\n===== MEMORY ADDRESSES =====\n");
    printf("Function (text segment):      %p\n", (void*)show_memory_regions);

    printf("\n--- Data Segment (.data) ---\n");
    printf("Initialized global:           %p\n", (void*)&global_init);
    printf("Static initialized:           %p\n", (void*)&static_init);

    printf("\n--- BSS Segment (.bss) ---\n");
    printf("Uninitialized global:         %p\n", (void*)&global_uninit);
    printf("Static uninitialized:         %p\n", (void*)&static_uninit);

    printf("\n--- Stack ---\n");
    printf("Local variable:               %p\n", (void*)&stack_var);

    printf("\n--- Heap ---\n");
    printf("malloc():                     %p\n", (void*)heap_malloc);
    printf("calloc():                     %p\n", (void*)heap_calloc);
    printf("realloc():                    %p\n", (void*)heap_realloc);

    free(heap_malloc);
    free(heap_calloc);
    free(heap_realloc);

    printf("\n(All heap memory freed successfully)\n");
    return 0;
}
