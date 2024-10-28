//
// Created by jacki on 10/26/2024.
//
#ifndef MAX_HEAPS_MAXHEAP_CPP
#define MAX_HEAPS_MAXHEAP_CPP

#include "MaxHeap.h"
template<typename T>
void MaxHeap<T>::reheapifyUp(int childIndex)
{
    int parentIndex = getParentIndex(childIndex);

    if(data[childIndex] > data[parentIndex]) //while child is larger than parent
    {
        std::swap(data[childIndex], data[parentIndex]); //swap with parent
        reheapifyUp(parentIndex);
    }

}

template<typename T>
void MaxHeap<T>::reheapifyDown(int parentIndex)
{
    int maxChildIndex = getMaxChildIndex(parentIndex);

    if(data[maxChildIndex] > data[parentIndex])
    {
        std::swap(data[maxChildIndex], data[parentIndex]);
        reheapifyDown(maxChildIndex);
    }
}

template<typename T>
int MaxHeap<T>::getLeftChildIndex(int parentIndex)
{
    return 2 * parentIndex + 1;
}

template<typename T>
int MaxHeap<T>::getRightChildIndex(int parentIndex)
{
    return 2 * parentIndex + 2;
}

template<typename T>
int MaxHeap<T>::getMaxChildIndex(int parentIndex)
{
    int lIndex = getLeftChildIndex(parentIndex),
            rIndex = getRightChildIndex(parentIndex);

    if(data[lIndex] > data[rIndex])
        return lIndex;
    else
        return rIndex;
}

template<typename T>
int MaxHeap<T>::getParentIndex(int childIndex)
{
    return (childIndex-1)/2;
}

template<typename T>
void MaxHeap<T>::push(const T &item)
{
    data.push_back(item);
    reheapifyUp(data.size() - 1);
    size++;
}

template<typename T>
void MaxHeap<T>::pop()
{
    std::swap(data[0], data.back());
    data.pop_back();
    reheapifyDown(0);
    size--;
}

template<typename T>
T &MaxHeap<T>::top()
{
    return data[0];
}

template<typename T>
int MaxHeap<T>::getSize()
{
    return size;
}

template<typename T>
bool MaxHeap<T>::empty()
{
    if(size==0)
        return true;
    else
        return false;
}

#endif //MAX_HEAPS_MAXHEAP_CPP
