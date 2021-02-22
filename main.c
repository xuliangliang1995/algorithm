#include <stdio.h>
#include "include/algo_utils.h"

int main() {
    int a = 1, b = 2;
    Swap(&a, &b);
    printf("a = %d, b = %d \n", a, b);

    int array[10] = {0};
    RandomIntArray(array, 10);

    PrintIntArray(array, 10);
    return 0;
}
