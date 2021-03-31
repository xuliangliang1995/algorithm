//
// Created by 许良 on 2021/3/12.
//

#include "algo_utils.h"
#include "include/heap_sort.h"
#define ARRAY_LENGTH 20

int main() {
    int array[ARRAY_LENGTH] = {0};
    RandomIntArray(array, ARRAY_LENGTH);
    PrintIntArray(array, ARRAY_LENGTH);
    HeapSort(array, ARRAY_LENGTH);
    PrintIntArray(array, ARRAY_LENGTH);
    return 0;
}

