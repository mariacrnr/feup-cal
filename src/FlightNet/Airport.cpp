#include "../../include/FlightNet/Airport.h"

Airport::Airport(int id, Position coords): id(id), coords(coords) {}

int Airport::getId() const {return this->id;}

Position Airport::getPosition() const {return this->coords;}

string Airport::getName() const {return this->name;}


void Airport::setName(string name){this->name = name;}

void Airport::setPosition(Position coords) {this->coords = coords;}

void Airport::addRoutes(vector<Flight*> flights){routes.push_back(flights);}

vector<vector<Flight*>> Airport::getRoutes() const{return routes;}

void Airport::insertCrew(int id){
    crewQueue.push(id);
}

int Airport::popCrew(){
    int id = crewQueue.front();
    crewQueue.pop();
    return id;
}

bool Airport::operator==(Airport airport) {return id == airport.getId();}

bool Airport::operator!=(Airport airport) {return id != airport.getId();}




