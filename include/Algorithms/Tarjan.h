#ifndef INCLUDE_TARJAN_H
#define INCLUDE_TARJAN_H

#include "../Utils/MutablePriorityQueue.h"
#include "../../include/Graph/Graph.h"
#include <algorithm>
#include <iostream>

/**Implementation of the Tarjan Algorithm**/
class Tarjan{
private:
    Graph* graph;
    std::vector<int>* lowLink; //vector that stores the scc of the vertexes of that index

public:
    /** Tarjan Constructor
     *
     * graph graph to analise
     */
    Tarjan(Graph* graph);

    /** Calculates the strongly connected components of the graph using Tarjan's Algorithm
     *
     */
    void run();

    /** Depth-First Search in the graph from a specific vertex
     *
     * @param i index of the vertex
     * @param dfsOrder order from which the graph vertexes will be searched
     * @param low stores the scc's of the vertexes
     * @param current stores the vertexes that already have been visited
     */
    void DFS(int i, std::vector<int>* dfsOrder, std::vector<int>* low, std::vector<int>* current);

    /** Removes airports from the smaller scc's
     *
     * @return vector of vertexes removed
     */
    vector<Vertex*> removeIsolatedAirports();
};

#endif //INCLUDE_TARJAN_H
