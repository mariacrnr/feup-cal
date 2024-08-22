#ifndef INCLUDE_GRAPH_H
#define INCLUDE_GRAPH_H

#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
#include "Vertex.h"

using namespace std;

#define INF std::numeric_limits<double>::max()

/**Represents a Directed Graph**/
class Graph {
    vector<Vertex*> vertexSet;
public:
    /** Graph default constructor
     *
     */
    Graph();
    /**Graph Constructor
     *
     * @param vertexSet set of vertexes of the graph
     */
    Graph(vector<Vertex*> vertexSet);

    /** Gets the vertex set of the graph
     *
     * @return vector of vertex pointers of the vertexes in the graph
     */
    vector<Vertex*> getVertexSet() const;
    /**Gets the total number of vertexes in the graph
     *
     * @return total number of vertexes in the graph
     */
    int getNumVertex() const;

    /**Finds a vertex in the graph
     *
     * @param in info of the vertex
     * @return if found, pointer to the vertex, NULL otherwise
     */
    Vertex* findVertex(const Airport &in) const;

    /**Gets the vertex index
     *
     * @param v vertex to get the index of
     * @return vertex index
     */
    int getVertexIndex(const Vertex* v) const;

    /**Gets the vertex at a specific index
     *
     * @param index index of the vertex to get
     * @return pointer to the vertex of the specific index
     */
    Vertex* getVertexAt(int index);

    /**Adds vertex to the graph
     *
     * @param in info of the vertex
     * @return false if the vertex is already in the vertex set, true otherwise
     */
    bool addVertex(const Airport &in);

    /**Adds edge to the graph
     *
     * @param sourc source vertex
     * @param dest destination vertex
     * @param w weight of the edge
     * @return false if the vertexes are not in the graph, true otherwise
     */
    bool addEdge(const Airport &sourc, const Airport &dest, double w);

    /**Removes edge from graph
     *
     * @param sourc source vertex
     * @param dest destination vertex
     * @return false if the vertexes are not in the graph, true otherwise
     */
    bool removeEdge(const Airport &sourc, const Airport &dest);

    /**Removes vertex from graph
     *
     * @param in info of the vertex to be removed
     * @return false if the vertex to be removed is not in the graph, false otherwise
     */
    bool removeVertex(const Airport &in);

    /**Gets the transpose of the graph
     *
     * @return pointer to transposed graph
     */
    Graph* getReversedGraph();

    /**Graph default destructor
     *
     */
    ~Graph();
};

#endif //INCLUDE_GRAPH_H
