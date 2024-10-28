//
// Created by jacki on 3/12/2024.
//

#ifndef SFML_PROJECT_NODE_H
#define SFML_PROJECT_NODE_H

template <typename T>
struct Node
{
    T data;
    Node<T> *next = nullptr, *prev = nullptr;
};
#endif //SFML_PROJECT_NODE_H
