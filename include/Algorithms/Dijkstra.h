#ifndef SRC_DIJKSTRA_H
#define SRC_DIJKSTRA_H

#include "../Utils/MutablePriorityQueue.h"
#include "../../include/Graph/Graph.h"
#include <set>

using namespace std;
/**Implementation of the Dijkstra's Algorithms**/
class Dijkstra{
private:
    Graph* graph;
    Graph* reverseGraph = NULL;
    Vertex* midPoint; //Mid-point stored for the Bi-Directional Dijkstra Algorithm

    /** Sets up and initializes all the graph variables used by the Dijkstra´s algorithms
     *
     * @param source
     * @param backwards
     * @return
     */
    Vertex* DijkstraSetUp(const Airport & source, bool backwards);
public:
    /** Dijkstra Constructor
     *
     * @param graph graph to apply the Dijkstra's Algorithms
     */
    Dijkstra(Graph * graph);

    /** Calculates the shortest path between one source vertex and all the other vertexes, using Dijkstra's Algorithm
     *
     * @param source source airport
     * @return 1 if the vertexes are not in the graph, 0 otherwise
     */
    int DijkstraOneToMany(const Airport & source);

    /** Calculates the shortest path between two vertexes using Dijkstra's Algorithm
     *
     * @param source source airport
     * @param dest destination airport
     * @return 1 if the vertexes are not in the graph, 0 otherwise
     */
    int DijkstraTwoPoints(const Airport & source, const Airport & dest);

    /** Calculates the shortest path between two vertexes using Bi-Directional Dijkstra's Algorithm
     *
     * @param source source airport
     * @param dest destination airport
     * @param reverseGraph Transpose of the graph, used to compute the backwards path (destination to source)
     * @return 1 if the vertexes are not in the graph, 0 otherwise
     */
    int BidirectionalDijkstra(const Airport & source, const Airport & dest, Graph* reverseGraph);

    /** Assembles the path from the destination vertex to the origin, needed to assemble the path for the
     * Bi-Directional Dijkstra algorithm
     *
     * @param origin origin airport
     * @param dest destination airport
     * @return vector of pointers to airports, ordered by the resulting path
     */
    vector<Airport*> getBackPath(const Airport &origin, const Airport &dest) const;

    /** Assembles the path from the origin vertex to the destination calculated by the Dijkstra's Algorithms
     *
     * @param origin origin airport
     * @param dest destination airport
     * @return vector of pointers to airports, ordered by the resulting path
     */
    vector<Airport*> getPath(const Airport &origin, const Airport &dest) const;

    /** Assembles the path calculated by the Bi-Directional Dijkstra Algorithm
     *
     * @param origin origin airport
     * @param dest destination airport
     * @return vector of pointers to airports, ordered by the resulting path
     */
    vector<Airport*> getBiDirPath(const Airport &origin, const Airport &dest) const;

};

#endif //INCLUDE_DIJKSTRA_H
