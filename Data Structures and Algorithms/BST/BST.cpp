//
// Created by jacki on 11/4/2024.
//

#ifndef BST_BST_CPP
#define BST_BST_CPP
#include "BST.h"

template<class T>
bool BST<T>::ifLeaf(Node<T> *node)
{
    return (node && !node->left && !node->right);
}

template<class T>
Node<T> *BST<T>::getOneChild(Node<T> *&node)
{
    if(node->left && !node->right)
        return node->left;
    else if(node->right && !node->left)
        return node->right;
    else return nullptr;
}

template<class T>
Node<T> *&BST<T>::getNextSuccessor(Node<T> *&node)
{
    if(ifLeaf(node) || !node->left)
        return node;
    else
        return getNextSuccessor(node->left);
}

template<class T>
Node<T> *&BST<T>::searchBefore(Node<T> *&prev, Node<T> *&current, T data)
{
    if(data == current->data)
        return prev;
    else if(data < current->data)
        return searchBefore(current, current->left, data);
    else if(data > current->data)
        return searchBefore(current, current->right, data);
}

template<class T>
void BST<T>::swapNodeData(Node<T>*& n1, Node<T>*& n2)
{
    T temp = n1->data;
    n1->data = n2->data;
    n2->data = temp;
}

template<class T>
void BST<T>::inorder(Node<T> *node, void (*f)(T& param))
{
    if(node)
    {
        inorder(node->left, f);
        f(node->data);
        inorder(node->right, f);
    }
    else
        return;
}

template<class T>
void BST<T>::preorder(Node<T> *node, void (*f)(T& param))
{
    if(node)
    {
        f(node->data);
        preorder(node->left, f);
        preorder(node->right, f);
    }
}

template<class T>
void BST<T>::postorder(Node<T> *node, void (*f)(T& param))
{
    if(node)
    {
        postorder(node->left, f);
        postorder(node->right, f);
        f(node->data);
    }
}

template<class T>
void BST<T>::push(Node<T> *&node,const T &data)
{
    if(!node) //not node aka points to nullptr
    {
        node = new Node<T>; //creates new node
        node->data = data; //sets node data to data
        counter++;
    }
    else if(data <= node->data)
        push(node->left, data);
    else if(data > node->data)
        push(node->right, data);
}

template<class T>
void BST<T>::remove(Node<T> *&node,const T &data)
{
    if(!node)
        return;
    else if(data < node->data)
        remove(node->left, data);
    else if(data > node->data)
        remove(node->right, data);
    else
    {
        if (ifLeaf(node))
        {
            delete node;
            node = nullptr;
        }
        else if (getOneChild(node))
        {
            Node<T> *child = getOneChild(node);
            Node<T>* temp = node;
            node = child;
            delete temp;
        }
        else
        {
            Node<T> *&s = getNextSuccessor(node->right);
            swapNodeData(node, s);
            remove(s, data);
        }
    }
}

template<class T>
bool BST<T>::empty()
{
    if(root == nullptr)
        return true;
    return false;
}

template<class T>
int BST<T>::size()
{
    return counter;
}

template<class T>
void BST<T>::inorder(void (*f)(T& param))
{
    inorder(root, f);
}

template<class T>
void BST<T>::preorder(void (*f)(T& param))
{
    preorder(root, f);
}

template<class T>
void BST<T>::postorder(void (*f)(T& param))
{
    postorder(root, f);
}

template<class T>
void BST<T>::push(const T& data)
{
    push(root, data);
}

template<class T>
void BST<T>::remove(const T& data)
{
    remove(root, data);
    counter--;
}

template<class T>
void BST<T>::breadth_first(void (*f)(T& param))
{
    std::queue<Node<T>*> q;
    if(root)
        q.push(root);

    while(!q.empty())
    {
        Node<T>* temp = q.front();

        if(temp->left != nullptr)
            q.push(temp->left);
        if(temp->right != nullptr)
            q.push(temp->right);

        f(q.front()->data);
        q.pop();
    }
}
#endif