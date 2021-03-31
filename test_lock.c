//
// Created by grasswort on 2021/3/18.
//
#include <stdio.h>
#include <pthread.h>

int* Increase(void) {
    static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
    static int balance = 0;
    pthread_mutex_lock(&lock);
    balance = balance + 1;
    pthread_mutex_unlock(&lock);
    return &balance;
}

void Task(void) {
    for (int i = 0; i < 10; ++i) {
        Increase();
    }
}

int main() {
    pthread_t thread_1, thread_2;

    int rc1 = pthread_create(&thread_1, NULL, (void *(*)(void *)) Task, NULL);
    int rc2 = pthread_create(&thread_2, NULL, (void *(*)(void *)) Task, NULL);

    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);

    int* res = Increase();

    printf("%d", *res);

    return 0;
}

