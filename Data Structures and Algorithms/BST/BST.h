//
// Created by jacki on 11/4/2024.
//

#ifndef BST_BST_H
#define BST_BST_H
#include "Node.h"
#include <iostream>
#include <queue>
template <class T>
class BST
{
private:
    Node<T>* root = nullptr;
    unsigned int counter = 0;
    bool ifLeaf(Node<T>* node);
    Node<T>* getOneChild(Node<T>*& node);
    Node<T>*& getNextSuccessor(Node<T>*& node);
    Node<T> *&searchBefore(Node<T> *&prev, Node<T> *&current, T data);
    void swapNodeData(Node<T>*& n1, Node<T>*& n2);
    void inorder(Node<T>* node, void(*f)(T& param));
    void preorder(Node<T>* node, void(*f)(T& param));
    void postorder(Node<T>* node, void(*f)(T& param));
    void push(Node<T> *&node, const T &data);
    void remove(Node<T> *&node, const T &data);
public:
    bool empty(); ///returns true if tree is empty, else false
    int size(); ///returns number of items in the tree
    void push(const T& data);
    void remove(const T& data);
    void breadth_first(void (*f)(T& param));
    void preorder(void(*f)(T& param));
    void postorder(void(*f)(T& param));
    void inorder(void(*f)(T& param)); ///call the private and pass f as second parameter
};
#include "BST.cpp"

#endif //BST_BST_H
