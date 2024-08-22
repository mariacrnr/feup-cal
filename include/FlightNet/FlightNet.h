#ifndef INCLUDE_SETUP_H
#define INCLUDE_SETUP_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <time.h>
#include <unordered_map>


#include "../Graph/Graph.h"
#include "Airport.h"
#include "../Utils/Files.h"
#include "../Algorithms/Tarjan.h"
#include "../../GraphViewerCpp/include/graphviewer.h"

/**Represents the FlightNet Company and all it´s relevant information**/
class FlightNet{

    int shiftDuration; //Between 4-10 hours
    int fuelDuration; //Between 4-10 hours
    int capacity; //Between 20-850 people

    vector<Vertex*> badWeatherReg; //Vector of vertexes inaccessible due to bad weather
    vector<Vertex*> isolatedAirports; //Vector of vertexes isolated (smaller SCC)

    //Passengers that travel in the FlightNet airports
    //The fist value represents the Source Airport of the passengers and the second map holds the Destination Airport
    //and the number of passengers that wnat to go to that destination
    unordered_map<int, unordered_map<int, int>> passengers;

public:
    /** FlightNet Constructor
     *
     */
    FlightNet();

    /** Reads the data from the Graph
     *
     * @return graph with the updated information
     */
    Graph readGraphData();

    /** Pre-processes the graph, removing edges that represent a violation of the flight crew shift time and the fuel
     * conditions and removing vertexes that represent
     *
     * @param graph
     */
    void flightNetSetup(Graph* graph);

    /**Reads and assigns to each Airport their name, from the data set provided
     *
     * @param graph graph to update with the information acquired
     */
    void readAirportsName(Graph* graph);

    /**Reads and Assigns to each Airport their position, from the data set provided
     *
     * @param graph graph to update with the information acquired
     */
    void readAirportsPos(Graph* graph);

    /**Reads and Assigns to the graph the Edges between the Airports, from the data set provided
     *
     * @param graph graph to update with the information acquired
     */
    void readEdges(Graph* graph);

    /**Removes edges which the distance violates the shift and fuel durations
     *
     * @param graph graph to update with the information acquired
     */
    void processRoutes(Graph* graph);

    /**Removes vertexes that represent airports with bad weather
     * Those vertexes are randomly chosen
     *
     * @param graph graph to update with the information acquired
     */
    void processWeather(Graph* graph);

    /** Creates passengers that travel using FlightNet
     * The number of passengers that fly between the airports ins randomly chosen
     *
     * @param graph graph to update with the information acquired
     */
    void createPassengers(Graph* graph);

    /** Sets the capacity of the FlightNet Airplanes
     *
     * @param capacity capacity of the FlightNet Airplanes
     */
    void setCapacity(int capacity);
    /** Gets the capacity of the FlightNet Airplanes
     *
     * @return capacity of the FlightNet Airplanes
     */
    int getCapacity() const;

    /** Gets the passengers that travel using FlightNet
     *
     * @return map that holds the number of passengers for each destination from a source airport, for all the FlighNet
     * airports
     */
    unordered_map<int, unordered_map<int, int>>* getPassengers();

    /** Sets the shift duration of each Flight Crew
     *
     * @param shiftDuration shift duration of each Flight Crew
     */
    void setShiftDuration(int shiftDuration);

    /**Sets the fuelDuration of the FlightNet Airplanes
     *
     * @param fuelDuration fuel duration of the FlightNet Airplanes
     */
    void setFuelDuration(int fuelDuration);

    /**Gets the vertexes that represent Airports with bad weather
     *
     * @return vector of vertex pointers to the airports with bad weather conditions
     */
    vector<Vertex*> getBadWeatherReg();

    /** Gets the vertexes that represent Isolated Airports
     *
     * @return vector of vertex pointers to the airports that are isolated
     */
    vector<Vertex*> getIsolatedReg();
};



#endif //INCLUDE_SETUP_H