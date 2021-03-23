//
// Created by 许良 on 2021/3/23.
//
#include <stdlib.h>
#include "algo_utils.h"
#define ARRAY_LENGTH 20

/**
 * 计数排序（默认没有负数，最大值为 maxVal） O(n)
 * @param array
 * @param length
 * @param maxVal
 */
void CountingSort(int array[], int length, int maxVal) {
    int* bak = malloc(sizeof(int) * maxVal);
    // init zero
    for (int i = 0; i < maxVal; ++i) {
        bak[i] = 0;
    }

    // counting
    for (int i = 0; i < length; ++i) {
        int val = array[i];
        bak[val] = bak[val] + 1;
    }

    int cursor = 0;
    // sort
    for (int i = 0; i < maxVal; ++i) {
        int count_i = bak[i];
        while (count_i > 0) {
            array[cursor] = i;
            cursor++;
            count_i--;
        }
    }

    free(bak);
    bak = NULL;
}

int main() {
    int array[ARRAY_LENGTH] = {0};
    RandomIntArray(array, ARRAY_LENGTH);
    PrintIntArray(array, ARRAY_LENGTH);
    CountingSort(array, ARRAY_LENGTH, 100);
    PrintIntArray(array, ARRAY_LENGTH);
    return 0;
}
