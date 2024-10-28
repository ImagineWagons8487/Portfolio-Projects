//
// Created by jacki on 3/14/2024.
//

#ifndef DOUBLYLINKEDLIST_IMPLEMENT_CONSTNODEITERATOR_CPP
#define DOUBLYLINKEDLIST_IMPLEMENT_CONSTNODEITERATOR_CPP
#include "ConstNodeIterator.h"

template<typename T>
ConstNodeIterator<T>::ConstNodeIterator()
{

}

template<typename T>
ConstNodeIterator<T>::ConstNodeIterator(Node<T> *current)
{
    _current = current;
}

template<typename T>
ConstNodeIterator<T> &ConstNodeIterator<T>::operator++()
{
    _current = _current->next;
    return *this;
}

template<typename T>
ConstNodeIterator<T> ConstNodeIterator<T>::operator++(int)
{
    ConstNodeIterator<T> copy(_current);
    _current = _current->next;
    return copy;
}

template<typename T>
ConstNodeIterator<T> &ConstNodeIterator<T>::operator--()
{
    _current = _current->prev;
    return *this;
}

template<typename T>
ConstNodeIterator<T> ConstNodeIterator<T>::operator--(int)
{
    ConstNodeIterator<T> copy(_current);
    _current = _current->prev;
    return *this;
}

template<typename T>
const T &ConstNodeIterator<T>::operator*() const
{
    return _current->data;
}

template<typename T>
ConstNodeIterator<T> &ConstNodeIterator<T>::operator=(const ConstNodeIterator<T> &iter)
{
    this->_current = iter._current;
    return *this;
}

template<typename U>
bool operator==(const ConstNodeIterator<U> &lhs, const ConstNodeIterator<U> &rhs)
{
    return (lhs._current == rhs._current);
}

template<typename U>
bool operator!=(const ConstNodeIterator<U> &lhs, const ConstNodeIterator<U> &rhs)
{
    return (lhs._current != rhs._current);
}

#endif //DOUBLYLINKEDLIST_IMPLEMENT_CONSTNODEITERATOR_CPP