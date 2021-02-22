//
// Created by grasswort on 2021/2/22.
//
#include <stdio.h>
#include "include/algo_utils.h"
/**
 * 插入排序
 * @param array
 * @param length
 */
void InsertionSort(int array[], int length) {
    for (int i = 1; i < length; ++i) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}


int main() {
    int array[20] = {0};
    RandomIntArray(array, 20);
    PrintIntArray(array, 20);
    InsertionSort(array, 20);
    puts("\nInsertion-sort .");
    PrintIntArray(array, 20);
    return 0;
}
