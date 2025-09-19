cmake_minimum_required(VERSION 3.30)
project(SortingAlgorithm)

set(CMAKE_CXX_STANDARD 20)

add_executable(SortingAlgorithm main.cpp
        InsertionSort.cpp
        InsertionSort.h
        MergeSort.cpp
        MergeSort.h
        Merge_Insertion_Sort.cpp
        Merge_Insertion_Sort.h)
