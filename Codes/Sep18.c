#include "stdio.h"
#include "math.h"

void Bin(int x) {
    int end = ceil(log(x) / log(2));
    int bits[end];
    for (int i = end - 1; i >= 0; --i) {
        bits[i] = x % 2;
        x = x / 2;
    };
    for (int j = 0; j < end; ++j) {
        printf("%d", bits[j]);
    };

};

int main() {

    int a = 0x123456;
    printf("Hex: %x\n", a);
    printf("Decimal: %d\n", a);
    printf("Octal: %o\n", a);
    printf("Char: %c\n", a);

    printf("\n");

    char b = 'V';
    printf("Hex: %x\n", b);
    printf("Decimal: %d\n", b);
    printf("Octal: %o\n", b);
    printf("Char: %c\n", b);

    printf("\n");

    Bin(0x19);

    return 0;
}
