#include "../../include/FlightNet/Flight.h"

Flight::Flight(int src, int dest, int crewID): src(src), dest(dest), crewID(crewID){}

void Flight::addPassengers(int src, int dest, int noPassengers){
    seats.push_back(make_pair(noPassengers, make_pair(src,dest)));
}

int Flight::getSeats() const{
    int count = 0;
    for (int i = 0; i < seats.size(); i++)
        count += seats[i].first;
    return count;
}

int Flight::getArrivingPassengers(){
    int count = 0;
    for (int i = 0; i < seats.size(); i++){
        if (seats[i].second.second == dest) count += seats[i].first;
    }
    return count;
}

int Flight::getSrcDestPassengers(){
    return seats[0].first;
}

int Flight::getCrewID() const{
    return crewID;
}

int Flight::getMainDest() const {
    if(seats.size() == 0) return -1;
    else return seats[0].second.second;
}
