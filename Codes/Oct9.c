#include "stdio.h"

int main() {
//     int x = 0x12345678;
//     printf("Mine: 0x%x", (x | (0x0a << 16)));
//     char a = 0x2f;
//     char * p = &a;
//     printf("%u", *p);
    int a = 0;
    char *s_ptr = (char *)&a;
    scanf("%s", s_ptr);
    printf("a = %d\n", a);
    return 0;
}
