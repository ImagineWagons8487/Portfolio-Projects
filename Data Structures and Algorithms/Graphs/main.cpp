#include "Graph.h"

int main()
{
    //std::int?
    //with x vertices, make an x by x array/matrix
    Graph g(5);
    g.addVertex(1);
//    g.addVertex(6);
    int weights[][3] = {
            {0, 1, 2},
            {0, 5, 9},
            {1, 2, 8},
            {1, 3, 15},
            {1, 5, 6},
            {2, 3, 1},
            {2, 4, 7},
            {3, 4, 3},
            {4, 5, 3},
    };
    for(auto & weight : weights)
        g.addEdge(weight[0], weight[1], weight[2]);
    for(int i=0; i<6; i++)
    {
        g.breadth_first(i);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for(int i=0; i<6; i++)
    {
        g.depth_first(i);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for(int i=0; i<6; i++)
    {
        g.shortestPath(0, i);
        std::cout << std::endl;
    }
    return 0;
}


///-----  Graphs  -----
//3 coins with H or T

//Starting with HHH
//can go to THH, HTH, or HHT
    //one change in one coin
//THH can go to HHH, TTH, or THT
//HTH can go to TTH, HHH, HTT

///-----  Directed Graphs  -----
//graphs where the edges are directed
//circle A has an arrow pointed to circle B

///-----  Undirected Graphs  -----
//edges are bidirectional
//circle A has an arrow pointed to circle B and circle B has an arrow pointed to circle A

///-----  Weighted Graphs  -----
//edges have a weight or cost
    //like how Google Maps factors in traffic and other variables to have the best possible path

///-----  Labeled Graphs  -----
//has named vertices

///THERE ARE COMBINATIONS OF CERTAIN GRAPHS

///there is no root, can start at any vertex for traversals

///Breadth_first
//starting at 0, with a 0-5 graph on notebk
//fill a queue with what you visit, [0], then push in what it's connected to, [0, 1, 2]
//then pop, [1, 2], anything that is visited, mark as "visited"

///-----  Dijkstra's Algorithm  -----
//usually weighted?

