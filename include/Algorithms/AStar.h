#ifndef INCLUDE_ASTAR_H
#define INCLUDE_ASTAR_H

#include "../Graph/Graph.h"
#include "../Utils/MutablePriorityQueue.h"

/** Implementation of A-Star algorithm **/
class AStar {
private:
    Graph * graph;

    /** Heuristic Function used to calculate the distance between the vertexes
     *
     * @param source source airport
     * @param dest destination airport
     * @return Haversine distance between the source and destination airports
     */
    double Heuristic(const Airport &source, const Airport &dest);

    /** Sets up and initializes all the graph variables used by the A-Star algorithm
     *
     * @param source source airport
     * @return vertex pointer of the source vertex in the graph
     */
    Vertex* AStarSetUp(const Airport & source);

public:
    /** A-Star Constructor
     *
     * @param graph graph to apply the A-Star algorithm
     */
    AStar(Graph * graph);

    /** Calculates the shortest path between two points using the A-Star algorithm
     *
     * @param source source airport
     * @param dest destination airport
     * @return 1 if the vertexes are not in the graph, 0 otherwise
     */
    int AStarTwoPoints(const Airport & source, const Airport & dest);

    /** Assembles the path calculated using the A-Star algorithm
     *
     * @param origin origin airport
     * @param dest destination airport
     * @return vector of pointers to airports, ordered by the resulting path
     */
    vector<Airport*> getPath(const Airport &origin, const Airport &dest) const;

};


#endif //INCLUDE_ASTAR_H

