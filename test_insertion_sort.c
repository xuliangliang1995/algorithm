//
// Created by grasswort on 2021/2/22.
//
#include <stdio.h>
#include "include/algo_utils.h"
#include "include/insertion_sort.h"
#define ARRAY_LENGTH 20

int main() {
    int array[ARRAY_LENGTH] = {0};
    RandomIntArray(array, ARRAY_LENGTH);
    PrintIntArray(array, ARRAY_LENGTH);
    InsertionSort(array, ARRAY_LENGTH);
    puts("\nInsertion-sort .");
    PrintIntArray(array, ARRAY_LENGTH);
    return 0;
}
