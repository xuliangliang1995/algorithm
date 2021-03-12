//
// Created by 许良 on 2021/3/12.
//

#include "algo_utils.h"
#define ARRAY_LENGTH 20


/**
 * MAX_HEAPIFY 堆化  O(h)
 * @param array
 * @param length
 * @param i
 */
void MaxHeapify(int array[], int length, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    int largest = i;
    if (left <= length - 1 && array[left] > array[largest]) {
        largest = left;
    }
    if (right <= length - 1 && array[right] > array[largest]) {
        largest = right;
    }

    if (i == largest) {
        return;
    }

    Swap(array + i, array + largest);

    MaxHeapify(array, length, largest);
}

/**
 * 建堆 O(n)
 * @param array
 * @param length
 */
void BuildMaxHeap(int array[], int length) {
    int i = length / 2 - 1;
    while (i >= 0) {
        MaxHeapify(array, length, i);
        i--;
    }
}

/**
 * 堆排序 O(n*lg^n)
 * @param array
 * @param length
 */
void HeapSort(int array[], int length) {
    BuildMaxHeap(array, length);       // O(n)

    int i = length - 1;
    while (i > 0) {
        Swap(array, array + i);    // O(n)
        MaxHeapify(array, i, 0);    // n * O(lg^n)
        i--;
    }

}

int main() {
    int array[ARRAY_LENGTH] = {0};
    RandomIntArray(array, ARRAY_LENGTH);
    PrintIntArray(array, ARRAY_LENGTH);
    HeapSort(array, ARRAY_LENGTH);
    PrintIntArray(array, ARRAY_LENGTH);
    return 0;
}

