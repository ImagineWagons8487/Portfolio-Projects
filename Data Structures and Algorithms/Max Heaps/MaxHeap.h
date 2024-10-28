//
// Created by jacki on 10/26/2024.
//

#ifndef MAX_HEAPS_MAXHEAP_H
#define MAX_HEAPS_MAXHEAP_H
#include <vector>

template <typename T>
class MaxHeap
{
private:
    std::vector<T> data;
    unsigned int size=0;
    void reheapifyUp(int childIndex);
    void reheapifyDown(int parentIndex);
    int getLeftChildIndex(int parentIndex);
    int getRightChildIndex(int parentIndex);
    int getMaxChildIndex(int parentIndex); //returns the largest child
    int getParentIndex(int childIndex);

public:
    void push(const T& item);
    void pop();
    T& top();
    int getSize();
    bool empty();
};

#include "MaxHeap.cpp"
#endif //MAX_HEAPS_MAXHEAP_H
