#ifndef INCLUDE_EDGE_H
#define INCLUDE_EDGE_H

#include "../FlightNet/Airport.h"

class Vertex;
/**Represents a Graph's Edge**/
class Edge {
    Vertex* dest;      // destination vertex
    double weight;         // edge weight
public:
    /**Edge Constructor
     *
     * @param dest destination vertex
     * @param w edge weight
     */
    Edge(Vertex *dest, double w);

    /**Gets the destination vertex
     *
     * @return destination vertex
     */
    Vertex* getDest() const;

    /**Gets the weight of the edge
     *
     * @return weight of the edge
     */
    double getWeight() const;         // edge weight

    friend class Graph;
    friend class Vertex;
};

#endif //INCLUDE_EDGE_H
