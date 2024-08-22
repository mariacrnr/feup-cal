#ifndef INCLUDE_AIRPORT_H
#define INCLUDE_AIRPORT_H

#include <string>
#include <vector>
#include <queue>

#include "../../include/Utils/Position.h"
#include "../../include/FlightNet/Flight.h"


using namespace std;
/**Represents an Airport instance and holds all it's relevant information**/
class Airport {
private:
    int id;
    Position coords;
    string name;

    vector<vector<Flight*>> routes; //routes of the flights that leave each airport
    queue<int> crewQueue; //queue of crews available in each airport

public:
    /** Airport Constructor
     *
     * @param id id of the Airport
     * @param coords coordinates of it's position
     */
    Airport(int id, Position coords);

    /** Gets the Airport's id
     *
     * @return id of the Airport
     */
    int getId() const;

    /** Sets the name of the Airport
     *
     * @param name name of the Airport
     */
    void setName(string name);

    /** Gets the name of the Airport
     *
     * @return name of the Airport
     */
    string getName() const;

    /** Sets the Airport's Position
     *
     * @param coords coordinates of the Airport
     */
    void setPosition(Position coords);

    /** Gets the Airport's Position
     *
     * @return coordinates of the Airport
     */
    Position getPosition() const;

    /**Adds routes from flights to the airports routes
     *
     * @param flights flights to be added to the airport routes
     */
    void addRoutes(vector<Flight*> flights);

    /**Gets the routes of the Airport
     *
     * @return routes of the airport
     */
    vector<vector<Flight*>> getRoutes() const;

    /** Inserts a crew in the Airport's queue of crews
     *
     * @param id crew's id to insert on the Airport's queue of crews
     */
    void insertCrew(int id);

    /** Removes a crew from the Airport's queue of crews
     *
     * @return id of the Crew removed
     */
    int popCrew();

    /** Operator == Overload to compare two equal airports
     *
     * @param airport to be compared
     * @return true if the Airport's have the same id, false otherwise
     */
    bool operator==(Airport airport);

    /**Operator == Overload to compare two different airports
     *
     * @param airport airport to be compared
     * @return true if the Airport's have differente id's, false otherwise
     */
    bool operator!=(Airport airport);
};


#endif //INCLUDE_AIRPORT_H
