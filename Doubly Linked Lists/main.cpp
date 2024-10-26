#include <iostream>
#include "LinkedList.h"
int main()
{
    LinkedList<int> list;
    for(int i=0; i<10; i++)
        list.push_back(i);
    LinkedList<int> loser(list);
    std::cout << "\n\n Iterator Test\n";
    for(auto i : list)
        std::cout << i << " ";
    std::cout << "\n\n Const Iterator Test\n";
    for(auto i = list.cbegin(); i != list.cend(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << "\n\n reverse Iterator Test\n";
    for(auto i = list.rbegin(); i != list.rend(); ++i)
    {
        std::cout << *i << " ";
    }
    return 0;
}

void f(const LinkedList<int>& l)
{
    for(auto i = l.cbegin(); i != l.cend(); ++i)
    {
        std::cout << *i << " ";
    }
}
