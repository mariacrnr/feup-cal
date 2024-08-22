#include "../../include/Algorithms/Tarjan.h"

Tarjan::Tarjan(Graph* graph) : graph(graph) {
}

void Tarjan::DFS(int i, std::vector<int>* dfsOrder, std::vector<int>* low, std::vector<int>* current){
    static int unvisitedCounter = 0;
    dfsOrder->at(i) = low->at(i) = ++unvisitedCounter;
    current->push_back(i);

    Vertex* u = graph->getVertexAt(i);

    for (auto edge : u->getAdj()) {
        Vertex* v = edge.getDest();

        std::vector<Vertex*> vertices = graph->getVertexSet();
        int index = (int) (find(vertices.begin(), vertices.end(), v) - vertices.begin());


        if (dfsOrder->at(index) == -1) {
            DFS(index, dfsOrder, low, current);
            low->at(i) = min(low->at(i), low->at(index));
        }

        else if (find(current->begin(), current->end(), index) != current->end())
            low->at(i) = min(low->at(i), dfsOrder->at(index));

    }

    if (dfsOrder->at(i) == low->at(i)) { // If u is head of scc
        for (auto it = find(current->begin(), current->end(), i); it != current->end();) {
            low->at(*it) = low->at(i);
            current->erase(it);
        }
    }
}

void Tarjan::run(){
    unsigned size = graph->getNumVertex();

    auto* dfsOrder = new std::vector<int>(size, -1);
    auto* low = new std::vector<int>(size, -1);
    auto* current = new std::vector<int>();

    for (int i = 0; i < size; i++)
        if (dfsOrder->at(i) == -1)
            DFS(i, dfsOrder, low, current);


    lowLink = low;
}

vector<Vertex*> Tarjan::removeIsolatedAirports(){
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
