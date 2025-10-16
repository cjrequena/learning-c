// gcc main.c -o ../build/objects/main.o

#include <stdio.h>
#include "helloworld/helloworld.h"
#include "memoryallocation/memoryallocation.h"
#include "string/string.h"
#include "arrays/arrays.h"
int power(int base, int exp);

int main() {

    printArrayAddresses();

    char str[] = "Hello World!";
    reverseString(str);
    printf("%s\n", str);

    say_hello();
    printMemoryAllocation();
    int p = power(3, 10);
    printf("%d\n", p);
}

int power(int base, int exp) {
    int p = 1;
    for (int i = 0; i < exp; i++) {
        p = p * base;
    }
    return p;
}
