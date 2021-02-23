//
// Created by grasswort on 2021/2/23.
//

#ifndef ALGORITHM_STRUCT_LIST_H
#define ALGORITHM_STRUCT_LIST_H
struct _list {
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
typedef struct _list List;
#endif //ALGORITHM_STRUCT_LIST_H

/**
 * 构造器
 * @param size_E
 * @return
 */
List* Constructor_List(int size_E);

/**
 * 构造器（指定初始化容量）
 * @param capacity
 * @param size_E
 * @return
 */
List* Constructor_List_Init_Capacity(int capacity, int size_E);

/**
 * 添加
 * @param list
 * @param val
 */
void List_Add(List *list, void *val);

/**
 * 根据索引查询
 * @param list
 * @param index
 * @return
 */
void* List_Get(List *list, int index);

/**
 * 移除某个元素
 * @param list
 * @param index
 * @return
 */
void* List_Remove(List *list, int index);

/**
 * 释放
 * @param list
 */
void List_Free(List **list);





