#pragma once
#ifndef HEAPSORT_H
#define HEAPSORT_H
#include "PriorityQueue.h"
#include<vector>

template<typename T>
void HeapSort(vector<T>& arr) {
    PriorityQueue<T> pq;
    pq.buildMaxHeap(arr);
    arr.clear();
    while (!pq.empty()) {
        arr.push_back(pq.extractMax());
    }
}
#endif
