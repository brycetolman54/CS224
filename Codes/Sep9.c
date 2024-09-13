#include "stdio.h"

int main() {
    int num = 0;

    printf("Enter a number: ");
    fflush(stdout);
    scanf("%d", &num);

    int sum = 0;

    for (int i = 0; i < num; i = i + 1) {
        sum = sum + i;
    };

    printf("The sum is: %d\n", sum);

    scanf("%d", &num);

    return 0;
}
