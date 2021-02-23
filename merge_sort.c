//
// Created by grasswort on 2021/2/22.
//
#include <stdio.h>
#include <stdlib.h>
#include "include/algo_utils.h"
#define ARRAY_LENGTH 20

/**
 * 分治
 * @param array
 * @param start
 * @param end
 */
void PartitionMergeSort(int *array, int start, int end) {
    if (start >= end) {
        return;
    }
    if (end - start == 1) {
        if (array[start] > array[end]) {
            Swap(array + start, array + end);
        }
        return;
    }
    int right = start + ((end - start) / 2);
    int left = right - 1;
    PartitionMergeSort(array, start, left);
    PartitionMergeSort(array, right, end);

    int bak_length = end - start + 1;
    int *array_bak = malloc(sizeof(int) * bak_length);

    int const_start = start;
    for (int i = 0; i < bak_length; ++i) {
        if (start > left) {
            array_bak[i] = array[right++];
            continue;
        }
        if (right > end) {
            array_bak[i] = array[start++];
            continue;
        }

        int left_val = array[start];
        int right_val = array[right];
        if (left_val < right_val) {
            array_bak[i] = array[start++];
        } else {
            array_bak[i] = array[right++];
        }
    }
    for (int i = 0; i < bak_length; ++i) {
        array[const_start++] = array_bak[i];
    }
    free(array_bak);
    array_bak = NULL;
}

/**
 * 归并排序
 * @param array
 * @param length
 */
void MergeSort(int array[], int length) {
    PartitionMergeSort(array, 0, length - 1);
}

int main() {
    int array[ARRAY_LENGTH] = {0};
    RandomIntArray(array, ARRAY_LENGTH);
    PrintIntArray(array, ARRAY_LENGTH);
    MergeSort(array, ARRAY_LENGTH);
    puts("\nMerge-sort .");
    PrintIntArray(array, ARRAY_LENGTH);
    return 0;
}

