#include <iostream>
#include "../include/FlightNet/FlightNet.h"
#include "../include/Interface.h"


int main() {

    FlightNet* flightNet = new FlightNet();

    Graph unprocessedGraph = flightNet->readGraphData();

    Interface interface = Interface(unprocessedGraph,flightNet);
    interface.processMainMenu();

    return 0;
}
