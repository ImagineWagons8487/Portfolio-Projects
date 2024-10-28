//
// Created by jacki on 3/13/2024.
//
#ifndef DOUBLYLINKEDLIST_IMPLEMENT_NODEITERATOR_CPP
#define DOUBLYLINKEDLIST_IMPLEMENT_NODEITERATOR_CPP
#include "NodeIterator.h"

template<typename T>
NodeIterator<T>::NodeIterator()
{

}

template<typename T>
NodeIterator<T>::NodeIterator(Node<T> *current)
{
    _current = current;
}

template<typename T>
NodeIterator<T> &NodeIterator<T>::operator++()
{
    _current = _current->next;
    return *this;
}

template<typename T>
NodeIterator<T> NodeIterator<T>::operator++(int)
{
    NodeIterator<T> copy(_current);
    _current = _current->next;
    return copy;
}

template<typename T>
NodeIterator<T> &NodeIterator<T>::operator--()
{
    _current = _current->prev;
    return *this;
}

template<typename T>
NodeIterator<T> NodeIterator<T>::operator--(int)
{
    NodeIterator<T> copy(_current);
    _current = _current->prev;
    return copy;
}

template<typename T>
T &NodeIterator<T>::operator*()
{
    return _current->data;
}

template<typename U>
bool operator==(const NodeIterator<U> &lhs, const NodeIterator<U> &rhs)
{
    return (lhs._current == rhs._current);
}

template<typename U>
bool operator!=(const NodeIterator<U> &lhs, const NodeIterator<U> &rhs)
{
    return (lhs._current != rhs._current);
}

template<typename T>
NodeIterator<T>& NodeIterator<T>::operator=(const NodeIterator<T> &iter)
{
    this->_current = iter._current;
    return *this;
}

#endif //DOUBLYLINKEDLIST_IMPLEMENT_NODEITERATOR_CPP