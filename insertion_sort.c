//
// Created by grasswort on 2021/2/22.
//
#include <stdio.h>
#include "include/algo_utils.h"
#define ARRAY_LENGTH 20
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
    int array[ARRAY_LENGTH] = {0};
    RandomIntArray(array, ARRAY_LENGTH);
    PrintIntArray(array, ARRAY_LENGTH);
    InsertionSort(array, ARRAY_LENGTH);
    puts("\nInsertion-sort .");
    PrintIntArray(array, ARRAY_LENGTH);
    return 0;
}
