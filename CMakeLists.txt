cmake_minimum_required(VERSION 3.17)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} C)

set(CMAKE_C_STANDARD 99)

include_directories("include")

file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
foreach(file ${files})
    get_filename_component(name ${file} NAME)
    add_executable(${name} ${file}
            src/algo_utils.c
            src/struct_array_list.c
            src/insertion_sort.c
            src/heap_sort.c
            src/merge_sort.c
            )
    target_compile_definitions(${name} PUBLIC DEBUG)
endforeach()