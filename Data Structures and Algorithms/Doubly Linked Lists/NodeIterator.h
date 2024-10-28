//
// Created by jacki on 3/13/2024.
//

#ifndef DOUBLYLINKEDLIST_IMPLEMENT_NODEITERATOR_H
#define DOUBLYLINKEDLIST_IMPLEMENT_NODEITERATOR_H
#include "Node.h"
#include <iterator>
template <typename T>
class NodeIterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
private:
    Node<T>* _current;
public:
    NodeIterator();
    NodeIterator(Node<T>* current);

    //++ prefix
    NodeIterator& operator++();
    //++ postfix
    NodeIterator operator++(int);
    //-- prefix
    NodeIterator& operator--();
    //-- postfix makes a copy, increments, returns copy
    NodeIterator operator--(int);
    // dereference
    T& operator*();
    //equal to
    template <typename U>
    friend bool operator==(const NodeIterator<U>& lhs, const NodeIterator<U>& rhs);
    //not equal to
    template <typename U>
    friend bool operator!=(const NodeIterator<U>& lhs, const NodeIterator<U>& rhs);
    //assignment
    NodeIterator<T>& operator=(const NodeIterator<T>& iter);
};

#include "NodeIterator.cpp"
#endif //DOUBLYLINKEDLIST_IMPLEMENT_NODEITERATOR_H
