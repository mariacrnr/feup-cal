#ifndef CAL_2021_G66_STATS_H
#define CAL_2021_G66_STATS_H

#include "Graph/Graph.h"

/**Represents the Stats given by the implemented Heuristic**/
class Stats{
    Graph* graph;
    Airport* src; //source Airport

public:
    /** Stats Constructor
     *
     * @param graph graph to be used
     * @param src source Airport
     */
    Stats(Graph* graph, Airport* src);

    /** Gives the number of passengers transported
     *
     * @return number of passengers transported
     */
    float nrPassengersTransported();

    /** Gives the number of passengers that were transported from the source to the final destination airports
     *
     * @return number of passengers that were transported from the source to the final destination airports
     */
    float nrSrcDestPassengersTransported();

    /** Gives the number of passengers that were transported from the source to the intermediary destinations airports
     *
     * @return number of passengers that were transported from the source to the intermediary destinations airports
     */
    float nrNonSrcDestPassengersTransported();

    /** Gives the sum of the total number of passengers that have the same arrival and departure as the route of
     * the flight
     *
     * @return sum of the total number of passengers that have the same arrival and departure as the route of the flight
     */
    float srcPassengersPerFlight();

    /** Gives the sum of the total number of passengers that don't have the same arrival and departure as the route of
     * the flight
     *
     * @return sum of the total number of passengers that don't have the same arrival and departure as the route of the flight
     */
    float nonSrcPassengersPerFlight();

    /** Gives the average total number of passengers per flight
     *
     * @return average total number of passengers per flight
     */
    float allPassengersPerFlight();

    /** Gives the number of passengers processed in the first half of the algorithm
     *
     * @return number of passengers processed in the first half of the algorithm
     */
    float firstHalfPassengers();

    /** Gives the number of passengers processed in the second half of the algorithm
     *
     * @return number of passengers processed in the second half of the algorithm
     */
    float secondHalfPassengers();

    /** Gives the total number of flights
     *
     * @return total number of flights
     */
    float nrFlights();

    /** Gives the total number of routes
     *
     * @return total number of routes
     */
    float nrRoutes();

    /** Gives the number of routes that left the origin airport
     *
     * @return number of routes that left the origin airport
     */
    float nrSrcRoutes();
};



#endif //CAL_2021_G66_STATS_H
