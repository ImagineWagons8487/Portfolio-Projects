#include <iostream>
#include "MaxHeap.h"
int main()
{
    MaxHeap<int> h;
    h.push(9);
    h.push(3);
    h.push(5);
    std::cout << h.top() << " " << h.getSize() << std::endl;
    h.pop();
    std::cout << h.top() << " " << h.getSize();
    return 0;
}
