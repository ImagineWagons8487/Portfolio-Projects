//
// Created by jacki on 3/14/2024.
//

#ifndef DOUBLYLINKEDLIST_IMPLEMENT_CONSTNODEITERATOR_H
#define DOUBLYLINKEDLIST_IMPLEMENT_CONSTNODEITERATOR_H
#include "Node.h"
#include <iterator>
template<typename T>
class ConstNodeIterator : public std::iterator<std::bidirectional_iterator_tag, T>
{

private:
    const Node<T>* _current;
public:
    ConstNodeIterator();
    ConstNodeIterator(Node<T>* current);

    ConstNodeIterator& operator++();
    ConstNodeIterator operator++(int);
    ConstNodeIterator& operator--();
    ConstNodeIterator operator--(int);
    const T& operator*() const;

    template <typename U>
    friend bool operator==(const ConstNodeIterator<U>& lhs, const ConstNodeIterator<U>& rhs);
    template <typename U>
    friend bool operator!=(const ConstNodeIterator<U>& lhs, const ConstNodeIterator<U>& rhs);
    ConstNodeIterator<T>& operator=(const ConstNodeIterator<T>& iter);
};

#include "ConstNodeIterator.cpp"
#endif //DOUBLYLINKEDLIST_IMPLEMENT_CONSTNODEITERATOR_H
