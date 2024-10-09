#include "stdio.h"
#include "math.h"

int main(int argc, char *argv[])
{
    int x;
    scanf("%d", &x);
    int size = (int)ceil(log2(x));

    int bits[size];
    for (int i = size; i >= 0; --i) {
        bits[i] = x % 2;
        x = x / 2;
    };
    for (int j = 0; j <= size; ++j) {
        printf("%d", bits[j]);
    };

    printf("\n");

   return 0;
}
