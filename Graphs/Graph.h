//
// Created by jacki on 4/23/2024.
//

#ifndef NOTES_GRAPHS_GRAPH_H
#define NOTES_GRAPHS_GRAPH_H
#include <vector>
#include <queue>
#include <set>
#include <iostream>
class Graph
{
    //undirected weighted graph
private:
    int vertices=0;
    std::vector<std::vector<bool>> adjacencyMatrix;
    std::vector<std::vector<int>> _weight;
    void depth_first(int source, std::vector<bool> &visited);
    int getLowest(std::vector<int> vector);
    std::vector<int> getNeighbors(int source);
public:
    Graph();
    Graph(const int& vertices);
    void addVertex(int vertexAmount);
    void addEdge(int source, int destination, int weight);
    int size();
    void removeEdge(int source, int destination);
    //bracket operator overload maybe :O

    void breadth_first(int sourceVertex);
    void depth_first(int sourceVertex);
    void shortestPath(int source, int destination);
    //HAVE ALL TRAVERSALS COUT THE PATH(S)

    //int vertices
    //bool adjacencyMatrix [][]  2D vector preferably
    //int weight [][] 2D array of ints

    //void addVertex(int vertex);
        //vertices++;
    //void addEdge(int source, int destination, int weight);
        //will add from source to destination but also destination to source since undirected
        //will add weights for the edges
    //void removeEdge(int source, int destination)
        //will remove both edges
    //bracket operator overload (maybe)

    //---  Traversals  --
    //void breadth_first(int sourceVertex);

    //public void depth_first(int sourceVertex);

    //private void depth_first(source, visited);

    //void shortestPath(int source, destination);



};


#endif //NOTES_GRAPHS_GRAPH_H
