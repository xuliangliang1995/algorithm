//
// Created by grasswort on 2021/3/13.
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/**
 * 合并 时间复杂度 O(n)
 * @param array
 * @param p
 * @param q
 * @param r
 */
void MergeExec(int array[], int p, int q, int r) {
    int merge_size = r - p + 1;
    int* dst = malloc(sizeof(int) * merge_size);

    int left = p;
    int right = q + 1;

    for (int i = 0; i < merge_size; ++i) {

        if (left > q) {
            dst[i] = array[right];
            right++;
        } else if (right > r) {
            dst[i] = array[left];
            left ++;
        } else if (array[left] < array[right]) {
            dst[i] = array[left];
            left ++;
        } else {
            dst[i] = array[right];
            right++;
        }
    }

    memcpy(array + p, dst, merge_size * sizeof(int));
    free(dst);
    dst = NULL;
}

/**
 * 分治 // Tn = 2 * T(n / 2) + O(n)
 * @param array
 * @param length
 */
void PartitionSort(int array[], int left, int right) {
    if (left == right) {
        return;
    }
    int mid = left + ((right - left) / 2);
    PartitionSort(array, left, mid);
    PartitionSort(array, mid + 1, right);
    MergeExec(array, left, mid, right);
}

/**
 * 归并排序  时间复杂度 O(n * lg^n)
 * @param array
 * @param length
 */
void MergeSort(int array[], int length) {
    PartitionSort(array, 0, length - 1);
}