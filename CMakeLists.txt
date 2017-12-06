cmake_minimum_required(VERSION 3.6)
project(heap)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Heap.cpp Heap.h String.cpp String.h HeapNode.cpp HeapNode.h)
add_executable(heap ${SOURCE_FILES})