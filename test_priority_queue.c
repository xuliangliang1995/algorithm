//
// Created by grasswort on 2021/3/13.
//
#include <stdio.h>
#include <stdlib.h>

/**
 * 优先级队列（最大优先级队列）
 */
typedef struct PriorityQueue {
    int capacity;
    int heapSize;
    int *heap;
} PriorityQueue;

/**
 * Constructor
 * @param capacity
 * @return
 */
PriorityQueue* PriorityQueueConstructor(int capacity) {
    int* heap = malloc(sizeof(int) * capacity);
    PriorityQueue* queue = malloc(sizeof(PriorityQueue));
    queue->capacity = capacity;
    queue->heapSize = 0;
    queue->heap = heap;
    return queue;
}
/**
 * Destroy
 * @param queue_pp
 */
void PriorityQueueDestroy(PriorityQueue **queue_pp) {
    PriorityQueue* p = *queue_pp;
    free(p->heap);
    p->heapSize = 0;
    p->capacity = 0;
    p->heap = NULL;
    free(p);
    *queue_pp = NULL;
}

/**
 * HEAP-MAXIMUM
 * @return
 */
int* HeapMaximum(PriorityQueue *priorityQueue) {
    int *p = NULL;
    int heapSize = priorityQueue->heapSize;
    if (heapSize < 1) {
        return p;
    }
    return priorityQueue->heap;
}
/**
 * INSERT(S, x)
 * @param
 * @param x
 */
void PriorityQueueInsert(PriorityQueue *priorityQueue, int x) {

}

int main() {
    PriorityQueue* priorityQueue = PriorityQueueConstructor(20);
    printf("PriorityQueue -> Capacity : %d\n", priorityQueue->capacity);


    PriorityQueueDestroy(&priorityQueue);
    return 0;
}