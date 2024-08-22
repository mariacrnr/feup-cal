#include "../../include/Graph/Vertex.h"


Vertex::Vertex(Airport in): info(in) {}

Airport* Vertex::getInfo(){
    return &this->info;
}

void Vertex::setDist(double dist) {
    this->dist = dist;
}

double Vertex::getDist() const {
    return this->dist;
}

void Vertex::setPath(Vertex* path) {
    this->path = path;
}

Vertex* Vertex::getPath() const {
    return this->path;
}

void Vertex::setVisited(bool visited) {
    this->visited = visited;
}

bool Vertex::getVisited() const {
    return this->visited;
}

vector<Edge> Vertex::getAdj() const {
    return this->adj;
}

void Vertex::addEdge(Vertex *d, double w) {
    adj.push_back(Edge(d, w));
}

bool Vertex::operator<(Vertex &vertex) const {
    return this->dist < vertex.getDist();
}

void Vertex::setGScore(double gScore) {
    this->gScore = gScore;
}

double Vertex::getGScore() const {
    return this->gScore;
}

bool Vertex::removeEdgeTo(Vertex *d) {
    for (auto it = adj.begin(); it!=adj.end(); it++) {
        if (it->dest == d) {
            adj.erase(it);
            return true;
        }
    }
    return false;
}

bool Vertex::operator==(Vertex & vertex) const {
    return this->info.getId() == vertex.info.getId();
}

