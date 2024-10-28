//
// Created by jacki on 4/23/2024.
//

#include "Graph.h"

void Graph::depth_first(int source, std::vector<bool>& visited)
{
    if(!visited[source]) //stopping case, if index is visited
    {
        std::set<int> neighbors; // set up neighbors list as set
        visited[source] = true; // mark source as visited
        for(int i=0; i<adjacencyMatrix[source].size(); i++) // get all neighbors of source
        {
            if(adjacencyMatrix[source][i] && !visited[i]) //if connection and not visited
                neighbors.insert(i);  //inserts all neighbors of source
        }
        std::cout << source; // cout source
        for(int iter : neighbors)// iterate through neighbors
            depth_first(iter, visited);// call recursively for each neighbor
    }
}

int Graph::getLowest(std::vector<int> vector)
{
    int lowest=vector[0];
        for(int i=1; i<vector.size(); i++)
        {
            if(vector[i] < lowest)
                lowest = vector[i];
        }
    return lowest;
}

std::vector<int> Graph::getNeighbors(int source)
{
    std::vector<int> neighbors;
    for(int i=0; i<adjacencyMatrix[source].size(); i++)
    {
        if(adjacencyMatrix[source][i])
            neighbors.push_back(i);
    }
    return neighbors;
}

Graph::Graph()
{

}

Graph::Graph(const int &vertices)
{
    this->vertices = vertices;

    adjacencyMatrix.resize(vertices);
    _weight.resize(vertices);

    for(int i=0; i<vertices; i++)
    {
        adjacencyMatrix[i].resize(vertices);
        _weight[i].resize(vertices);
    }
}

void Graph::addVertex(int vertexAmount)
{
    vertices += vertexAmount;

    adjacencyMatrix.resize(vertices);
    _weight.resize(vertices);

    for(int i=0; i<vertices; i++)   //this double for is to add columns to existing rows
    {
        adjacencyMatrix[i].resize(vertices);
        _weight[i].resize(vertices);
    }
}

void Graph::addEdge(int source, int destination, int weight)
{
    adjacencyMatrix[source][destination] = true;
    adjacencyMatrix[destination][source] = true;
    _weight[source][destination] = weight;
    _weight[destination][source] = weight;
}

int Graph::size()
{
    return vertices;
}

void Graph::removeEdge(int source, int destination)
{
    adjacencyMatrix[source][destination] = false;
    adjacencyMatrix[destination][source] = false;
    _weight[source][destination] = -1;
    _weight[destination][source] = -1;
}

void Graph::breadth_first(int sourceVertex)
{
    std::queue<int> q; //make a queue
    std::vector<bool> visited;  //can't do = {false}? & setting up visited vector
    visited.resize(vertices); //resize visited vector to vertices amount
    q.push(sourceVertex); //add source to q
    visited[sourceVertex] = true; //mark source as visited
    while(!q.empty()) //while q is not empty
    {
        for(int i=0; i<adjacencyMatrix[q.front()].size(); i++) //for loop that goes for adjacency matrix at q.front()
        {
            //add all unvisited neighbors of front of q to q
            if(adjacencyMatrix[q.front()][i] && !visited[i]) // if connection exists and not visited
            {
                q.push(i); // push unvisited neighbor
                visited[i] = true; //mark as visited
            }
        }
        std::cout << q.front(); //cout front of q
        q.pop(); //pop q
    }
}

void Graph::depth_first(int sourceVertex)
{
    std::vector<bool> visited;//set up visited
    visited.resize(vertices);//resize visited
    depth_first(sourceVertex, visited);// call private depth first
}

void Graph::shortestPath(int source, int destination) //dijkstra's alg
{
    //create an array, set cost for everything to be INT32_MAX
    std::vector<int> costs(vertices, INT32_MAX), q;
    //create an int array for path set everything to INT32_MIN
    std::vector<int> paths(vertices, INT32_MIN);
    //add all vertices to q
    for(int i=0; i<vertices; i++)
        q.push_back(i);
    costs[source] = 0;
    paths[source] = 0;
    while(!q.empty())
    {
        //let v = vertex with lowest cost
        int lowest = INT32_MAX;
        for(int i : q)
        {
            if(costs[i] < lowest)
                lowest = i;
        }
        int v = lowest;
        //remove v from q
        for(int i=0; i<q.size(); i++)
        {
            if(q[i] == v)
                q.erase(q.begin() + i);
        }
//        q.erase(std::find(q.begin(), q.end(), v));
        //loop through all neighbors, n of v
        std::vector<int> n = getNeighbors(v);
        for(int i:n)
        {
            int min = costs[v] + _weight[v][i];
            if(min < costs[i])
            {
                costs[i] = min;
                paths[i] = v;
            }
        }
        //min = cost[v] + weight[v][n]
        //if(min < cost[n])
            //change cost[n] to new min
            //path[n] = v
    }
    //start at destination
    //loop getting curr vertex path until source
    int temp = destination;
    while(temp != source)
    {
        std::cout << temp << " -> ";
        temp = paths[temp];
    }
    std::cout << temp;
}
