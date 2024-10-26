//
// Created by jacki on 3/12/2024.
//
#ifndef SFML_PROJECT_LINKEDLIST_CPP
#define SFML_PROJECT_LINKEDLIST_CPP
#include "LinkedList.h"

template<typename T>
LinkedList<T>::LinkedList()
{

}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &list)
{
    *this = list;
}

template<typename T>
void LinkedList<T>::addFirstNode(Node<T> *node)
{
    Node<T>* n = node;
    n->prev = nullptr;
    n->next = nullptr;
    head = n;
    tail = n;
}

template<typename T>
Node<T> *LinkedList<T>::createNode(const T &data)
{
    Node<T>* n = new Node<T>;
    n->data = data;
    return n;
}

template<typename T>
void LinkedList<T>::push_front(Node<T> *node)
{
    Node<T>* n = node;
    if(head == nullptr)
        addFirstNode(n);
    else
    {
        n->next = head;
        head->prev = n;
        n->prev = nullptr;
        head = n;
    }
}

template<typename T>
void LinkedList<T>::push_back(Node<T> *node)
{
    Node<T>* n = node;
    if(head == nullptr)
        addFirstNode(n);
    else
    {
        n->prev = tail;
        tail->next = n;
        n->next = nullptr;
        tail = n;
    }

}

template<typename T>
Node<T> *LinkedList<T>::search(const T &data)
{
    Node<T>* walker = head;
    while(walker->data != data)
    {
        walker = walker->next;
    }
    return walker;
}

template<typename T>
void LinkedList<T>::remove(Node<T> *node)
{
    Node<T>* target = node;
    if(target == head && target == tail)
    {
        head = nullptr;
        tail = nullptr;
    }
    else if(target == head)
    {
        head = target->next;
        head->prev = nullptr;
    }
    else if(target == tail)
    {
        tail = target->prev;
        tail->next = nullptr;
    }
    else
    {
        target->prev->next = target->next;
        target->next->prev = target->prev;
    }
    delete target;
}

template<typename T>
void LinkedList<T>::push_front(const T &item)
{
    Node<T>* n = createNode(item);
    push_front(n);
}

template<typename T>
void LinkedList<T>::push_back(const T &item)
{
    Node<T>* n = createNode(item);
    push_back(n);
}

template<typename T>
void LinkedList<T>::pop_front()
{
    if(head != nullptr)
        remove(head);
}

template<typename T>
void LinkedList<T>::pop_back()
{
    if(tail != nullptr)
        remove(tail);
}

template<typename U>
std::ostream &operator<<(std::ostream &out, const LinkedList<U> &list)
{
    Node<U>* walker = list.head;
    while(walker != nullptr)
    {
        out << walker->data << " ";
        walker = walker->next;
    }
    return out;
}

template<typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &list)
{
    Node<T>* walker = list.head;
    LinkedList<T>::~LinkedList();
    while(walker != nullptr)
    {
        push_back(walker->data);
        walker = walker->next;
    }
    return *this;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    while(head != nullptr)
    {
        remove(head);
    }
}

template<typename T>
void LinkedList<T>::insertAfter(Node<T> *node)
{
    Node<T>* target = node, next = target->next, n;
    n->next = next;
    next->prev = n;
    target->next = n;
    n->prev = target;

    //create node ptr next and point to target's next
    //create new node
    //point n's next to next
    //point next's prev to n
    //point target's next to n
    //point n's prev to target
}

template<typename T>
void LinkedList<T>::insertAfter(const T &item)
{
    insertAfter(createNode(item));
}

template<typename T>
void LinkedList<T>::insertBefore(Node<T> *node)
{
    Node<T>* target = node;
    insertAfter(target->prev);
}

template<typename T>
void LinkedList<T>::insertBefore(const T &item)
{
    insertBefore(createNode(item));
}

template<typename T>
typename LinkedList<T>::iterator LinkedList<T>::begin()
{
    return NodeIterator<T>(head);
}

template<typename T>
typename LinkedList<T>::iterator LinkedList<T>::end()
{
    return NodeIterator<T>(nullptr);
}

template<typename T>
const typename LinkedList<T>::const_iterator LinkedList<T>::cbegin() const
{
    return ConstNodeIterator<T>(head);
}

template<typename T>
const typename LinkedList<T>::const_iterator LinkedList<T>::cend() const
{
    return ConstNodeIterator<T>(nullptr);
}

template<typename T>
typename LinkedList<T>::reverse_iterator LinkedList<T>::rbegin()
{
    return ReverseNodeIterator<T>(tail);
}

template<typename T>
typename LinkedList<T>::reverse_iterator LinkedList<T>::rend()
{
    return ReverseNodeIterator<T>(nullptr);
}

#endif //SFML_PROJECT_LINKEDLIST_CPP