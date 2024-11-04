#include "BST.h"

void print(int& num)
{
    std::cout << num << " ";
}

int main() {
    BST<int> tree;
    tree.push(4);
    tree.push(2);
    tree.push(5);
    tree.push(7);
    tree.push(9);
    tree.push(56);
    tree.remove(2);
    tree.push(23);
    if(!tree.empty())
    {
        std::cout << tree.size() << std::endl;
        tree.preorder(print);
        std::cout << std::endl;
        tree.inorder(print);
        std::cout << std::endl;
        tree.postorder(print);
        std::cout << std::endl;
        tree.breadth_first(print);
    }
    return 0;
}
