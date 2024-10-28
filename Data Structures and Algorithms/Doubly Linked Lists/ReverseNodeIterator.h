//
// Created by jacki on 3/14/2024.
//

#ifndef DOUBLYLINKEDLIST_IMPLEMENT_REVERSENODEITERATOR_H
#define DOUBLYLINKEDLIST_IMPLEMENT_REVERSENODEITERATOR_H
#include "Node.h"
#include <iterator>
template <typename T>
class ReverseNodeIterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
private:
    Node<T>* _current;
public:
    ReverseNodeIterator();
    ReverseNodeIterator(Node<T>* current);
    
    ReverseNodeIterator& operator++();
    ReverseNodeIterator operator++(int);
    ReverseNodeIterator& operator--();
    ReverseNodeIterator operator--(int);
    T& operator*();
    
    template<typename U>
    friend bool operator==(const ReverseNodeIterator<U>& lhs, const ReverseNodeIterator<U>& rhs);
    template <typename U>
    friend bool operator!=(const ReverseNodeIterator<U>& lhs, const ReverseNodeIterator<U>& rhs);
    ReverseNodeIterator<T>& operator=(const ReverseNodeIterator<T>& iter);
};

#include "ReverseNodeIterator.cpp"
#endif //DOUBLYLINKEDLIST_IMPLEMENT_REVERSENODEITERATOR_H
