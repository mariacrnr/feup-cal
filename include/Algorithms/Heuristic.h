#ifndef INCLUDE_HEURISTIC_H
#define INCLUDE_HEURISTIC_H

#include "unordered_map"
#include <iostream>

#include "../Graph/Graph.h"
#include "Dijkstra.h"
#include "../FlightNet/Flight.h"


class Heuristic{
    Graph* graph;
    unordered_map<int, unordered_map<int, int>> *passengers;
    int capacity;
    Airport* src;
    Dijkstra* dijkstra;


public:
    /**Heuristic Constructor
     *
     * @param graph graph to be used
     * @param passengers map with the passengers source, number and their destinations
     * @param airplane capacity
     * @param origin airport
     */
    Heuristic(Graph* graph, unordered_map<int, unordered_map<int, int>> *passengers, int capacity, Airport* src);
    /** Function that generates a flight according to the source and destination airports
     * @param src origin airport
     * @param dest destination airport
     */
    void generateFlights(Airport & src, Airport & dest);
    /** Function that fills a flight created in generateFlights with passengers
     *
     * @param path airport route path returned by dijkstra
     * @param flights flights to be filled
     */
    void flightFill(vector<Airport*> &path, vector<Flight*> &flights);

};

#endif //INCLUDE_HEURISTIC_H
