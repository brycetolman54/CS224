#include "stdio.h"

int main() {
    int x = 0x12345678;
    printf("First: %x\n", (x>>20) & 0xf);
    printf("Second: %x\n", (x<<8)>>28);

    int y = 0x87654321;
    char c = y;
    char b = y & 0xff;
    printf("c: %c, b: %c\n", c, b);

    int d = 0x5a;
    int e = 0x73;
    printf("&&: %x, &: %x\n", d && e, d & e);

    return 0;
}
