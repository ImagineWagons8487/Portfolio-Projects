cmake_minimum_required(VERSION 3.26)
project(DoublyLinkedList_Implement)

set(CMAKE_CXX_STANDARD 17)

add_executable(DoublyLinkedList_Implement main.cpp
        Node.h
        LinkedList.h
        LinkedList.cpp
        NodeIterator.cpp
        NodeIterator.h
        ReverseNodeIterator.cpp
        ReverseNodeIterator.h
        ConstNodeIterator.cpp
        ConstNodeIterator.h)
