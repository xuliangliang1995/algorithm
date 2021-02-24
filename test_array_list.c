//
// Created by grasswort on 2021/2/23.
//
#include <stdio.h>
#include "include/struct_array_list.h"

typedef struct Student {
    char* name;
    int age;
} Student;

/**
 * 打印 student 信息
 * @param student
 */
void PrintStudent(Student *student) {
    printf("student{name = %s, age = %d}\n", student->name, student->age);
}

int main() {
    ArrayList *list = Constructor_List(sizeof(Student));
    printf("ArrayList -> capacity : %d\n", list->capacity);
    printf("ArrayList -> size : %d\n", list->size);
    printf("ArrayList -> size_E : %d\n", list->size_E);

    Student jerry = {.name="jerry", .age=8};
    List_Add(list, &jerry);
    PrintStudent(&jerry);

    Student *index_0_val = List_Get(list, 0);
    PrintStudent(index_0_val);

    printf("ArrayList -> size : %d\n", list->size);
    List_Free(&list);
    return 0;
}

