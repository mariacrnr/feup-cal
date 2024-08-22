#ifndef INCLUDE_VERTEX_H
#define INCLUDE_VERTEX_H

#include <vector>

#include "Edge.h"

using namespace std;


class Vertex {
    Airport info;		// content of the vertex
    vector<Edge> adj;		// outgoing edges

    double dist = 0; //auxiliary field for the shortest path algorithms

    Vertex *path = NULL; //auxiliary field for the shortest path algorithms

    bool visited = false;		// auxiliary field

    double gScore = 0; //auxiliary field
    bool processing = false;	// auxiliary field

public:
    int queueIndex = 0; //auxiliary public field for MutablePriorityQueue

    /**Vertex Constructor
     *
     * @param in info of the vertex
     */
    Vertex(Airport in);

    /**Gets the Vertex info
     *
     * @return vertex info (airport pointer)
     */
    Airport* getInfo();

    /**Sets the distance of the vertex
     *
     * @param dist distance of the vertex
     */
    void setDist(double dist);

    /**Gets the distance of the vertex
     *
     * @return distance of the vertex
     */
    double getDist() const;

    /**Sets the path of the vertex
     *
     * @param path path of the vertex
     */
    void setPath(Vertex* path);
    /**Gets the path of the vertex
     *
     * @return path vertex pointer to the path of the vertex
     */
    Vertex* getPath() const;

    /**Sets if the vertex was visited
     *
     * @param visited visited value of the vertex
     */
    void setVisited(bool visited);
    /**Gets if the vertex was visited
     *
     * @return visited visited value of the vertex
     */
    bool getVisited() const;


    /**Sets the gScore of the vertex
     *
     * @param gScore gScore of the vertex
     */
    void setGScore(double gScore);

    /**Gets the gScore of the vertex
     *
     * @return gScore of the vertex
     */
    double getGScore() const;

    /**Gets the adjacent Edges of the vertex (outgoing)
     *
     * @return vector of the adjacent edges of the vertex
     */
    vector<Edge> getAdj() const;

    /**Adds Edge to the adjacent edges vector of the vertex
     *
     * @param d destination vertex
     * @param w weight
     */
    void addEdge(Vertex *d, double w);

    /**Removes edge to a destination vertex
     *
     * @param d destination vertex
     * @return true if the vertex is removed, false otherwise
     */
    bool removeEdgeTo(Vertex *d);

    /**Operator < overload to compare two vertexes
     *
     * @param vertex vertex to compare
     * @return true if the vertex is lower that the vertex to compare
     */
    bool operator<(Vertex & vertex) const;

    /**Operator == overload to compare two equal vertexes
     *
     * @param vertex vertex to compare
     * @return true if the vertexes are equal, false otherwise
     */
    bool operator==(Vertex & vertex) const;

    friend class Graph;

};

#endif //INCLUDE_VERTEX_H
