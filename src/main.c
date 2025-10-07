// gcc main.c -o ../build/objects/main.o

#include <stdio.h>
#include "string_reverse.c"

int main() {
    char str[] = "Hello World!11";
    reverse(str);
    printf("%s\n", str);
    return 0;
}
