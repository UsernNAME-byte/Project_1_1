cmake_minimum_required(VERSION 3.10)

project(Project_1_1)

set(CMAKE_CXX_STANDARD 17)

# Перевірка на правильний шлях до файлів
set(SOURCES
    src/Project_1_1.cpp
    src/Shop.cpp
    src/readArrayFromFile.cpp
    src/searchAndDisplayProducts.cpp
    src/userInterface.cpp
)

set(HEADERS
    src/DoublyLinkedList.h
    src/HeapSort.h
    src/PriorityQueue.h
    src/Shop.h
    src/readArrayFromFile.h
    src/searchAndDisplayProducts.h
    src/userInterface.h
)


add_executable(Project_1_1 ${SOURCES})
