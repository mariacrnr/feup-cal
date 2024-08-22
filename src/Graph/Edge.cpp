#include "../../include/Graph/Edge.h"


Edge::Edge(Vertex *dest, double w): dest(dest), weight(w) {}

Vertex* Edge::getDest() const{
    return dest;
}
double Edge::getWeight() const{
    return weight;
}
