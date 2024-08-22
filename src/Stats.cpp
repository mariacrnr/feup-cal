#include "../include/Stats.h"

Stats::Stats(Graph* graph, Airport* src): graph(graph), src(src){}

float Stats::nrPassengersTransported(){
    int count = 0;
    for (auto v: graph->getVertexSet()){
        vector<vector<Flight*>> routes = v->getInfo()->getRoutes();
        for (auto flights: routes)
            for (auto flight: flights)
                count += flight->getArrivingPassengers();
    }
    return count;
}

float Stats::nrSrcDestPassengersTransported(){
    int count = 0;
    vector<vector<Flight*>> routes = src->getRoutes();
    for (auto flights: routes)
        count += flights[0]->getSrcDestPassengers();

    return count;
}

float Stats::nrNonSrcDestPassengersTransported(){
    return nrPassengersTransported() - nrSrcDestPassengersTransported();
}

float Stats::srcPassengersPerFlight(){
    return nrSrcDestPassengersTransported() / nrSrcRoutes();
}
float Stats::nonSrcPassengersPerFlight(){
    int count = 0;
    for (auto v: graph->getVertexSet()) {
        vector<vector<Flight *>> routes = v->getInfo()->getRoutes();
        for (auto flights: routes)
            for (auto flight: flights)
                count += (flight->getSeats() - flight->getSrcDestPassengers());

    }
    return count / nrFlights();
}
float Stats::allPassengersPerFlight(){
    int count = 0;
    for (auto v: graph->getVertexSet()) {
        vector<vector<Flight *>> routes = v->getInfo()->getRoutes();
        for (auto flights: routes)
            for (auto flight: flights)
                count += flight->getSeats();

    }
    return count / nrFlights();
}

float Stats::firstHalfPassengers(){
    int count = 0;
    vector<Vertex*> set = graph->getVertexSet();
    for (int i = 0; i < set.size() / 2; i++) {
        vector<vector<Flight *>> routes = set[i]->getInfo()->getRoutes();
        for (auto flights: routes)
            for (auto flight: flights)
                count += flight->getArrivingPassengers();

    }
    return count;
}

float Stats::secondHalfPassengers(){
    int count = 0;
    vector<Vertex*> set = graph->getVertexSet();
    for (int i = set.size() / 2; i < set.size(); i++) {
        vector<vector<Flight *>> routes = set[i]->getInfo()->getRoutes();
        for (auto flights: routes)
            for (auto flight: flights)
                count += flight->getArrivingPassengers();

    }
    return count;
}

float Stats::nrFlights(){
    int count = 0;
    for (auto v: graph->getVertexSet()){
        vector<vector<Flight*>> routes = v->getInfo()->getRoutes();
        for (auto flights: routes)
            count += flights.size();
    }
    return count;
}

float Stats::nrRoutes() {
    int count = 0;
    for (auto v: graph->getVertexSet())
        count += v->getInfo()->getRoutes().size();

    return count;
}

float Stats::nrSrcRoutes() {
    return src->getRoutes().size();
}