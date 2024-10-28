//
// Created by jacki on 3/12/2024.
//

#ifndef SFML_PROJECT_LINKEDLIST_H
#define SFML_PROJECT_LINKEDLIST_H
#include "Node.h"
#include <iostream>
#include "NodeIterator.h"
#include "ReverseNodeIterator.h"
#include "ConstNodeIterator.h"
//input iterator, output iterator, forward iterator, bidirectional iterator, random access iterator
//this linked list is a bidirectional iterator
template <typename T>
class LinkedList
{
private:
    Node<T>* head = nullptr, *tail = nullptr;
    void addFirstNode(Node<T>* node); /// adds the first node of a list
    Node<T>* createNode(const T& data); /// returns a new node containing data
    void push_front(Node<T> *node); ///adds node to front of list
    void push_back(Node<T> *node); ///adds node to back of list
    Node<T>* search(const T& data); /// return the first containing data
    void remove(Node<T>* node); ///remove the node from the list
    void insertAfter(Node<T>* node);
    void insertBefore(Node<T>* node);
public:
    typedef NodeIterator<T> iterator;
    typedef const ConstNodeIterator<T> const_iterator;
    typedef ReverseNodeIterator<T> reverse_iterator;
    LinkedList(); ///default constructor
    LinkedList(const LinkedList<T>& list); ///copy constructor
    void push_front(const T& item); ///create a new node containing item and pass it to private push_front function
    void push_back(const T& item); ///same as push_front but push_back instead
    void insertAfter(const T& item);
    void insertBefore(const T& item);
    void pop_front();
    void pop_back();
    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const LinkedList<U>& list);
    LinkedList<T>& operator=(const LinkedList<T>& list);
    iterator begin();
    iterator end();
    const const_iterator cbegin() const;
    const const_iterator cend() const;
    reverse_iterator rbegin();
    reverse_iterator rend();
    ~LinkedList(); ///destructor
};

#include "LinkedList.cpp"
#endif //SFML_PROJECT_LINKEDLIST_H

