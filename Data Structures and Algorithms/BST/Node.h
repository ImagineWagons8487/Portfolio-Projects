//
// Created by jacki on 11/4/2024.
//

#ifndef BST_NODE_H
#define BST_NODE_H
template <typename T>
struct Node
{
    T data;
    Node<T> *left = nullptr, *right = nullptr;
};
#endif //BST_NODE_H
