//
// Created by grasswort on 2021/2/23.
//
#include <stdlib.h>
#include <string.h>

#ifndef ALGORITHM_STRUCT_LIST_H
#define ALGORITHM_STRUCT_LIST_H
struct ArrayList {
    /**
     * 数组起始指针
     */
    void *array;
    /**
     * 存储元素尺寸
     */
    int size_E;
    /**
     * 集合容量
     */
    int capacity;
    /**
     * 集合大小
     */
    int size;
};
typedef struct ArrayList ArrayList;
#endif //ALGORITHM_STRUCT_LIST_H
#define LIST_INIT_CAPACITY 10

/**
 * 构造器（指定初始化容量）
 * @param capacity
 * @param size_E
 * @return
 */
ArrayList* Constructor_List_Init_Capacity(int capacity, int size_E) {
    ArrayList* list = malloc(sizeof(ArrayList));
    void* array = malloc(size_E * capacity);
    list->size_E = size_E;
    list->size = 0;
    list->array = array;
    list->capacity = capacity;
    return list;
}

/**
 * 构造器
 * @param size_E
 * @return
 */
ArrayList* Constructor_List(int size_E) {
    return Constructor_List_Init_Capacity(LIST_INIT_CAPACITY, size_E);
}

/**
 * 添加
 * @param list
 * @param val
 */
void List_Add(ArrayList *list, void *val) {
    int size = list->size;
    int capacity = list->capacity;
    int size_E = list->size_E;

    if (size == capacity) {
        // 数组已满
        int capacity_ext = capacity * 2;
        void *array_ext = malloc(list->size_E * capacity_ext);
        void *array = list -> array;
        // 复制内存
        memcpy(array_ext, array, size * size_E);
        free(list -> array);
        list->array = NULL;
        list->array = array_ext;
        list->capacity = capacity_ext;
    }

    list->size = list->size + 1;
    void* array = list->array;
    memcpy(array + size, val, size_E);
}

/**
 * 根据索引查询
 * @param list
 * @param index
 * @return
 */
void* List_Get(ArrayList *list, int index) {
    ArrayList _list = *list;
    char* array = _list.array;
    return array + index * _list.size_E;
}

/**
 * 移除某个元素
 * @param list
 * @param index
 * @return
 */
void* List_Remove(ArrayList *list, int index) {

}

/**
 * 释放
 * @param list
 */
void List_Free(ArrayList **list) {
    ArrayList *_list_p = *list;
    free(_list_p->array);
    free(_list_p);
    *list = NULL;
}






