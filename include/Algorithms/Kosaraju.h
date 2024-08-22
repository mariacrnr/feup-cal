#ifndef INCLUDE_KOSARAJU_H
#define INCLUDE_KOSARAJU_H

#include "../../include/Graph/Graph.h"
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

/**Implementation of Kosaraju's Algorithm**/
class Kosaraju {
private:
    Graph* graph;
    Graph* reversedGraph;
    std::vector<Vertex*> vertices; //vertexes of the graph

    int sccCounter; //number of strongly connected components

    std::vector<int>* lowLink; //vector that stores the scc of the vertexes of that index
    int mainScc; //index of the main scc

public:
    /**Kosaraju Constructor
     *
     * @param graph graph to analise
     * @param reverseGraph
     */
    Kosaraju(Graph* graph, Graph* reverseGraph);

    /** Calculates the strongly connected components of the graph using Tarjan's Algorithm
     *
     */
    void run();

    /** Depth-First Search using stack to store the ordered vertexes
     *
     * @param i index of the vertex
     * @param visited stores the vertexes visited
     * @param stack stores the ordered vertexes
     */
    void DFS_S(int i, vector<bool>* visited, stack<int>* stack);

    /** Depth-First Search
     *
     * @param curr index of the current vertex
     * @param visited stores the vertexes visited
     * @param scc stores the vertexes that already have been visited
     */
    void DFS(int curr, vector<bool>* visited, vector<int>* scc);

    /** Removes airports from the smaller scc's
     *
     * @return vector of vertexes removed
     */
    vector<Vertex*> removeIsolatedAirports();
};

#endif //INCLUDE_KOSARAJU_H
