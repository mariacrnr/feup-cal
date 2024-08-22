#include "../../include/Algorithms/Kosaraju.h"

Kosaraju::Kosaraju(Graph* graph, Graph* reversedGraph) : graph(graph) , reversedGraph(reversedGraph), vertices(graph->getVertexSet()) {
    sccCounter = 0;
}

void Kosaraju::run() {
    int size = graph->getNumVertex();

    auto scc = new std::vector<int> (size, -1);
    auto stack = new std::stack<int>;
    auto visited = new std::vector<bool> (size, false);

    for (int i = 0; i < size; ++i)
        if (!visited->at(i))
            DFS_S(i, visited, stack); //DFS1

    Graph* holder = graph;
    graph = reversedGraph;
    reversedGraph = holder;

    for (int i = 0; i < size; ++i)
        visited->at(i) = false;

    while(!stack->empty()) {
        int curr = stack->top();
        stack->pop();

        if (!visited->at(curr)){
            DFS(curr, visited, scc); //DFS2
            sccCounter++;
        }

    }


    int biggestScc = -1;
    int biggestSccSize = -1;

    for (int i = 0; i < sccCounter; i++){
        int counter = (int) count(scc->begin(), scc->end(), i);
        if (counter > biggestSccSize){
            biggestScc = i;
            biggestSccSize = counter;
        }
    }


    mainScc = biggestScc;
    lowLink = scc;

    graph = reversedGraph;
    reversedGraph = holder;
}


void Kosaraju::DFS_S(int i, vector<bool>* visited, stack<int>* stack) { //DFS1
    Vertex* v = graph->getVertexAt(i);

    visited->at(i) = true;

    for (auto edge : v->getAdj()) {
        Vertex* u = edge.getDest();

        int j = (int) (find(vertices.begin(), vertices.end(), u) - vertices.begin());

        if (!visited->at(j))
            DFS_S(j, visited, stack);
    }

    stack->push(i);
}

void Kosaraju::DFS(int i, std::vector<bool>* visited, std::vector<int>* scc) { //DFS2
    visited->at(i) = true;
    scc->at(i) = sccCounter;

    Vertex* v = graph->getVertexAt(i);

    for (auto edge : v->getAdj()) {
        Vertex* u = edge.getDest();
        int j = graph->getVertexIndex(u);

        if (!visited->at(j))
            DFS(j, visited, scc);
    }
}

vector<Vertex*> Kosaraju::removeIsolatedAirports() {
    vector<Vertex*> removedVertexes;
    for (auto it = graph->getVertexSet().begin(); it != graph->getVertexSet().end(); it++){
        int index = it - graph->getVertexSet().begin();

        if (lowLink->at(index) != 1) {
            Vertex* v = graph->getVertexAt(index);
            removedVertexes.push_back(v);
            graph->removeVertex(*(v->getInfo()));
            lowLink->erase(lowLink->begin() + index);
            it--;
        }
    }
    return removedVertexes;
}