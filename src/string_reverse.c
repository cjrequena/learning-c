// gcc string_reverse.c -o ../build/objects/string_reverse.o
#include <stdio.h>
#include <string.h>

void reverse(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char aux = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = aux;
    }
}

int main(void) {
    char str[] = "Hello World!";
    reverse(str);
    printf("%s\n", str);
    return 0;
}