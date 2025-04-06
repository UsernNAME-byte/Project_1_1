#pragma once
#include <vector>
#include <iostream>

using namespace std;

template<typename T>
class PriorityQueue {
private:
    vector<T> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void minHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < heap.size() && heap[l] < heap[smallest]) {
            smallest = l;
        }
        if (r < heap.size() && heap[r] < heap[smallest]) {
            smallest = r;
        }
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            minHeapify(smallest);
        }
    }

    void heapDecreaseKey(int i, T key) {
        if (key > heap[i]) throw runtime_error("New key is greater than current key");
        heap[i] = key;
        while (i > 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:

    T heapMaximum()
    {
        if (heap.empty()) throw runtime_error("Heap is empty");
        return heap[0];
    }

    T extractMax() {
        if (heap.empty()) throw runtime_error("Heap underflow");
        T max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        minHeapify(0);
        return max;
    }

    void insert(T key) {
        heap.push_back(key);
        heapDecreaseKey(heap.size() - 1, key);
    }

    void buildMaxHeap(const vector<T>& values) {
        heap.clear();
        for (T val : values) {
            insert(val);
        }
    }

    bool empty() const {
        return heap.empty();
    }

    void printHeap() {
        for (Shop val : heap) 
        {
            cout << val << " ";
        }
        cout << endl;
    }
};
