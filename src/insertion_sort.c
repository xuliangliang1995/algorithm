//
// Created by grasswort on 2021/2/22.
//
/**
 * 插入排序
 * @param array
 * @param length
 */
void InsertionSort(int array[], int length) {
    for (int i = 1; i < length; ++i) {          // c1   n - 1
        int key = array[i];                     // c2   n - 1
        int j = i - 1;                          // c3   n - 1
        while (j >= 0 && array[j] > key) {      // c4   \sum_{i=1}^{n - 1} = n * \frac{n-1}{2}
            array[j + 1] = array[j];            // c5   \sum_{i=1}^{n - 1}
            j = j - 1;                          // c6   \sum_{i=1}^{n - 1}
        }
        array[j + 1] = key;                     // c7   n - 1
    }
    // Tn = a * n^2 + b * n + c  算法时间复杂度： O(n^2)
}

