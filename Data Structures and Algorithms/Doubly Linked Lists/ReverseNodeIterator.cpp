//
// Created by jacki on 3/14/2024.
//

#ifndef DOUBLYLINKEDLIST_IMPLEMENT_REVERSENODEITERATOR_CPP
#define DOUBLYLINKEDLIST_IMPLEMENT_REVERSENODEITERATOR_CPP
#include "ReverseNodeIterator.h"

template<typename T>
ReverseNodeIterator<T>::ReverseNodeIterator()
{

}

template<typename T>
ReverseNodeIterator<T>::ReverseNodeIterator(Node<T> *current)
{
    _current = current;
}

template<typename T>
ReverseNodeIterator<T> &ReverseNodeIterator<T>::operator++()
{
    _current = _current->prev;
    return *this;
}

template<typename T>
ReverseNodeIterator<T> ReverseNodeIterator<T>::operator++(int)
{
    ReverseNodeIterator<T> copy(_current);
    _current = _current->prev;
    return copy;
}

template<typename T>
ReverseNodeIterator<T> &ReverseNodeIterator<T>::operator--()
{
    _current = _current->next;
    return *this;
}

template<typename T>
ReverseNodeIterator<T> ReverseNodeIterator<T>::operator--(int)
{
    ReverseNodeIterator<T> copy(_current);
    _current = _current->next;
    return copy;
}

template<typename T>
T &ReverseNodeIterator<T>::operator*()
{
    return _current->data;
}

template<typename T>
ReverseNodeIterator<T> &ReverseNodeIterator<T>::operator=(const ReverseNodeIterator<T> &iter)
{
    this->_current = iter._current;
    return *this;
}

template<typename U>
bool operator==(const ReverseNodeIterator<U> &lhs, const ReverseNodeIterator<U> &rhs)
{
    return (lhs._current == rhs._current);
}

template<typename U>
bool operator!=(const ReverseNodeIterator<U> &lhs, const ReverseNodeIterator<U> &rhs)
{
    return (lhs._current != rhs._current);
}

#endif //DOUBLYLINKEDLIST_IMPLEMENT_REVERSENODEITERATOR_CPP
