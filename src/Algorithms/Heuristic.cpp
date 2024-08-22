#include "../../include/Algorithms/Heuristic.h"

Heuristic::Heuristic(Graph* graph, unordered_map<int, unordered_map<int, int>> *passengers, int capacity, Airport* src):graph(graph), passengers(passengers), capacity(capacity), src(src){
    this->dijkstra = new Dijkstra(this->graph);
}

void Heuristic::flightFill(vector<Airport*> &path, vector<Flight*> &flights){
    for (unsigned i = 0; i < path.size() - 1; i++){

        for (unsigned j = path.size() - 1; j > i; j--){

            int freeSeats = capacity; // max value

            for(unsigned k = i; k < j; k++)
                freeSeats = min(freeSeats, capacity - flights[k]->getSeats());
            if (freeSeats == 0) continue;

            int passengerCount = passengers->find(path[i]->getId())->second.find(path[j]->getId())->second;

            int available = min(passengerCount, freeSeats);

            for(unsigned k = i; k < j; k++)
                flights[k]->addPassengers(path[i]->getId(), path[j]->getId(), available);


            passengers->find(path[i]->getId())->second.find(path[j]->getId())->second -= available;

        }
    }
}


void Heuristic::generateFlights(Airport & src, Airport & dest){

    dijkstra->DijkstraTwoPoints(src, dest);

    vector<Airport*> path = dijkstra->getPath(src, dest);

    if (path.size() == 0) return;

    while (passengers->find(src.getId())->second.find(dest.getId())->second > 0){
        vector<Flight*> flights;
        for (unsigned i = 0; i < path.size() - 1; i++){
            int crewId = path[i]->popCrew();
            flights.push_back(new Flight(path[i]->getId(), path[i+1]->getId(), crewId));
            path[i+1]->insertCrew(crewId);
        }

        flightFill(path, flights);
        src.addRoutes(flights);
    }


}