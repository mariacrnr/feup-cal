#ifndef INCLUDE_FLIGHT_H
#define INCLUDE_FLIGHT_H


#include <unordered_map>
#include <vector>

using namespace std;
/**Represents a Flight instance and holds all it's relevant information**/
class Flight{
    vector<pair<int, pair<int, int>>> seats; //Seats in a Flight
    int src; //Source Airport id of the Flight
    int dest; //Destination Airport id of the Flight
    int crewID; //id of the crew allocated to the Flight
  
public:
    /** Flight Constructor
     *
     * @param src source airport id of the Flight
     * @param dest destination airport id of the Flight
     * @param crewID id of the crew allocated to the Flight
     */
    Flight(int src, int dest, int crewID);

    /** Adds passengers to the available seats in the Flight
     *
     * @param src source airport id of the Flight
     * @param dest destination airport id of the Flight
     * @param noPassengers number of passengers to add to the Flight
     */
    void addPassengers(int src, int dest, int noPassengers);

    /** Gets the number of seats occupied in a Flight
     *
     * @return number of seats occupied in a Flight
     */
    int getSeats() const;

    /** Gets the number of passengers who arrived at their destination in this flight
     * Useful to count the total number of passengers
     * @return number of passengers who arrived at their destination in this flight
     */
    int getArrivingPassengers();

    /** Gives the number of passengers that were transported from the their source to the final destination airports
     * (same as the routes)
     *
     * @return number of passengers that were transported from the their source to the final destination airports
     */
    int getSrcDestPassengers();

    /** Gets the id of the crew allocated to the Flight
     *
     * @return id of the crew allocated to the Flight
     */
    int getCrewID() const;

    /** Gets the main destination of the flight
     *
     * @return id of the main destination of the flight
     */
    int getMainDest() const;

};


#endif //INCLUDE_FLIGHT_H
