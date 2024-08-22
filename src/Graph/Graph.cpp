#include "../../include/Graph/Graph.h"

Graph::Graph() = default;

Graph::Graph(vector<Vertex*> vertexSet): vertexSet(move(vertexSet)) {}


vector<Vertex *> Graph::getVertexSet() const {
    return vertexSet;
}


int Graph::getNumVertex() const {
    return vertexSet.size();
}


Vertex* Graph::findVertex(const Airport &in) const {
    for (auto v : vertexSet)
        if (v->info == in)
            return v;
    return nullptr;
}

int Graph::getVertexIndex(const Vertex *v) const {
    return (int) distance(vertexSet.begin(), find(vertexSet.begin(), vertexSet.end(), v));
}

Vertex* Graph::getVertexAt(int index){
    return vertexSet[index];
}

bool Graph::addVertex(const Airport &in) {
    if (findVertex(in) != nullptr)
        return false;
    vertexSet.push_back(new Vertex(in));
    return true;
}


bool Graph::addEdge(const Airport &sourc, const Airport &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2,w);
    return true;
}

bool Graph::removeEdge(const Airport &sourc, const Airport &dest){
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);

    if (v1 == nullptr || v2 == nullptr)
        return false;
    return v1->removeEdgeTo(v2);
}

bool Graph::removeVertex(const Airport &in) {

    Vertex *v = nullptr;

    for (auto it = vertexSet.begin(); it!= vertexSet.end(); it++){

        if ((*it)->info == in) {
            v = *it;
            vertexSet.erase(it);
        }
    }

    for (auto &it : vertexSet) {

        if(!(it->info == in))
            it->removeEdgeTo(v);
    }

    if (v != nullptr) return true;
    return false;
}

Graph* Graph::getReversedGraph() {
    Graph* reversedGraph = new Graph();
    for(Vertex* v : this->vertexSet) {
        reversedGraph->addVertex(v->info);
    }
    for (Vertex* v : this->vertexSet) {
        for (const Edge &e : v->adj) {
            reversedGraph->addEdge(e.dest->info, v->info, e.weight);
        }
    }
    return reversedGraph;
}

Graph::~Graph() {

}

