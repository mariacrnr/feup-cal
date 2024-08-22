#ifndef INCLUDE_INTERFACE_H
#define INCLUDE_INTERFACE_H
#include <unistd.h>

#include "FlightNet/FlightNet.h"
#include "GraphViewer/GraphMap.h"
#include "Algorithms/Dijkstra.h"
#include "Algorithms/AStar.h"
#include "Algorithms/AStar.h"
#include "Algorithms/Heuristic.h"
#include "Algorithms/Kosaraju.h"
#include "Algorithms/Tarjan.h"
#include "Stats.h"

/**Represents the user's interface**/
class Interface {
private:
    Graph* graph;
    Graph* reverseGraph;
    FlightNet* flightNet;
    Dijkstra* dijkstra;
    AStar* astar;
    Stats* stats;
    Heuristic* heuristic;

public:
    /**Interface Constructor
     *
     * @param unprocessedGraph graph to be used in processing
     * @param flightNet flightNet instance to be used
     */
    Interface(Graph unprocessedGraph, FlightNet* flightNet);

    /**Main menu display
     *
     */
    void showMainMenu();

    /**Algorithms menu display
     *
     */
    void showAlgorithmsMenu();

    /**Heuristic menu display
     *
     */
    void showHeuristicMenu();


    /**FlightNet Settings menu display
     *
     */
    void showFlightNetSettingsMenu();

    /**Processes main menu events
     *
     */
    void processMainMenu();

    /**Processes algorithms menu events, and calculates the shortest paths between two points, using the implemented
     * algorithms
     *
     */
    void processAlgorithmsMenu();


    /** Calculates the Proposed Heuristic for a single airport
     *
     * @param duration time of the algorithm
     * @return origin vertex
     */
    Vertex* calculateHeuristic(double &duration);

    /** Processes Flight menu events
     *
     * @param origin origin airport that the heuristic is applied to
     * @param duration duration of the heuristic algorithm
     */
    void processFlightsMenu(Vertex* origin, double duration);

    /** Parses user input and shows relevant information
     *
     * @param origin origin airport that the heuristic is applied to
     * @param input user input
     * @param duration duration of the heuristic algorithm
     */
    void processFlightsStatsMenu(Vertex * origin, int input, double duration);

    /**Processes Flight Net Settings menu events
     *
     */
    void processFlightNetSettingsMenu();
    /** Parses user input and changes the corresponding settings
     *
     * @param input
     */
    void processFlightNetSettingsChanges(int input);

    /**Processes and shows the path obtained from the algorithms in a graph viewer map
     *
     * @param path path to be displayed
     */
    void processPathMap(const vector<Airport*> &path);

    /**Process the airports to be chosen events
     *
     * @param originVertex source vertex
     * @param destVertex destination vertex
     */
    void chooseAirports(Vertex** originVertex, Vertex** destVertex);

    /**
     *
     * @param originVertex
     */
    void chooseOriginAirport(Vertex** originVertex);

    /**
     *
     * @param destVertex
     */
    void chooseDestinationAirport(Vertex** destVertex);

    /** Shows the stats of the heuristic for a single airport
     *
     * @param origin Airport to show the stats of
     */
    void showStats(Airport* origin);

    /** Shows the number of passengers in each flight for a specific route between two airports in the graph
     *
     */
    void showRouteInfo();

    /**Shows the graph and all it's nodes
     *
     */
    void showMap();
};


#endif //INCLUDE_INTERFACE_H
