// gcc string_reverse.c -o ../build/objects/string_reverse.o
#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    const int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        const char aux = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = aux;
    }
}

void reverseStringV1(char* str) {
    const int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        const char aux = *(str + i);
        *(str + i) = *(str + len - i -1);
        *(str + len - i -1) = aux;
    }
}

void reverseStringV2(char* str) {
    char* start = str;
    char* end = str + strlen(str) - 1;

    while (start < end) {
        const char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// int main(void) {
//     char str[] = "Hello World!";
//     reverse(str);
//     printf("%s\n", str);
//     return 0;
// }