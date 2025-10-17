// gcc main.c -o ../build/objects/main.o

#include <stdio.h>
#include <stdlib.h>

#include "helloworld/helloworld.h"
#include "memoryallocation/memoryallocation.h"
#include "string/string.h"
#include "arrays/arrays.h"
int power(int base, int exp);

int main() {
    int* arrayPtr = returnAnArrayFromAfunction();
    for (int i = 0; i < 10; i++) {
        printf("array[%d] = %d\n", i, arrayPtr[i]);
    }
    free(arrayPtr);
}

// int power(int base, int exp) {
//     int p = 1;
//     for (int i = 0; i < exp; i++) {
//         p = p * base;
//     }
//     return p;
// }
