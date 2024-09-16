#include "stdio.h"

int main() {

    char c = 's';
    printf("0x%x\n", c);

    char a = 'b';
    char b = ';';

    printf("Value: %d\n", a < c);
    printf("values in Hex: 0x%x, 0x%x, 0x%x\n", c, a, b);
    printf("Values in char: %c, %c, %c\n", c, a, b);
    printf("Values in decimal: %d, %d, %d\n", c, a, b);

    printf("\nNow we can look at typecasting:\n");
    char d[] = "abcdefgh";
    for (int j = 0; j < 8; ++j) {
        printf("%c\n", d[j]);
    };
    int * i = (int *)&a;
    for (int j = 0; j < 2; ++j) {
        printf("%d\n", d[j]);
    };

    printf("\n%s\n", d);

    printf("\nLet's do some more typecasting:\n");
    int n = 0x00555942; // we need to add the 0x to make it hex and the 00 to make it a char array (the last box has to be null)
    char* p = (char*)&n;
    printf("Hex: %x\n", n);
    for(int k = 0; k < 3; ++k) {
        printf("%c", *(p+k));
    }

    return 0;
}
