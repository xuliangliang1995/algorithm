//
// Created by grasswort on 2021/2/22.
//
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * 交换
 * @param p1
 * @param p2
 */
void Swap(int *p1, int *p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

/**
 * 生成随机 int 数组 （0 - 99）
 * @param array
 * @param length
 */
void RandomIntArray(int *array, int length) {
    srand(time(NULL));
    for (int i = 0; i < length; ++i) {
        array[i] = rand() % 100;
    }
}

/**
 * 打印数组
 * @param array
 * @param length
 */
void PrintIntArray(int array[], int length) {
    for (int i = 0; i < length; ++i) {
        printf((i == length - 1) ? "%d" : "%d, ", array[i]);
    }
}

