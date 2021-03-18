//
// Created by 许良 on 2021/3/18.
//
#include "algo_utils.h"
#define ARRAY_LENGTH 20

/**
 * 分区原址排序 O(n)
 * @param A
 * @param l
 * @param r
 * @return int
 */
int Qs_PartitionSort(int A[], int l, int r) {
    int key = A[r];
    int i = l - 1;
    for (int j = l; j < r; ++j) {
        if (A[j] < key) {
            i = i + 1;
            Swap(A + i, A + j);
        }
    }
    Swap(A + i + 1, A + r);
    return i + 1;
}

/**
 * QuickSort O(n * lg ^ n)
 * @param A
 * @param l
 * @param r
 */
void QuickSortExec(int A[], int l, int r) {
    if (r <= l) {
        return;
    }

    int q = Qs_PartitionSort(A, l, r);
    QuickSortExec(A, l, q - 1);
    QuickSortExec(A, q + 1, r);
}

/**
 * QuickSort
 * @param A
 * @param length
 */
void QuickSort(int A[], int length) {
    QuickSortExec(A, 0, length - 1);
}

int main() {
    int array[ARRAY_LENGTH] = {0};
    RandomIntArray(array, ARRAY_LENGTH);
    PrintIntArray(array, ARRAY_LENGTH);
    QuickSort(array, ARRAY_LENGTH);
    PrintIntArray(array, ARRAY_LENGTH);
    return 0;
}
