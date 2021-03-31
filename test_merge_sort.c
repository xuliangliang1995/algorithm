//
// Created by 许良 on 2021/3/11.
//
#include "include/merge_sort.h"
#include "algo_utils.h"
#define ARRAY_LENGTH 20

int main() {
    int array[ARRAY_LENGTH] = {0};
    RandomIntArray(array, ARRAY_LENGTH);
    PrintIntArray(array, ARRAY_LENGTH);
    MergeSort(array, ARRAY_LENGTH);
    PrintIntArray(array, ARRAY_LENGTH);
    return 0;
}

