#include "../include/Interface.h"

Interface::Interface(Graph unprocessedGraph,  FlightNet* flightNet){
    this->graph = new Graph(unprocessedGraph);
    this->flightNet = flightNet;

    this->flightNet->flightNetSetup(this->graph);

    cout << "Reversing the Graph..." << endl;
    this->reverseGraph = this->graph->getReversedGraph();

    this->dijkstra = new Dijkstra(this->graph);
    this->astar = new AStar(this->graph);

}

void Interface::showMainMenu() {

    cout << "->-<->-<->-<->-<->-<->-FLIGHTNET-<->-<->-<->-<->-<->-<" << endl;
    cout << "1. Check shortest path between two airports" << endl;
    cout << "2. Check flights from an Airport" << endl;
    cout << "3. Show Map" << endl;
    cout << "4. Adjust FlightNet Settings" << endl;
    cout << "5. Exit" << endl;

}

void Interface::showAlgorithmsMenu() {
    cout << "Available algorithms:" << endl;
    cout << "1. Dijkstra One-To-Many " << endl;
    cout << "2. Dijkstra Two-Points" << endl;
    cout << "3. Bidirectional Dijkstra"<< endl;
    cout << "4. A-Star" << endl;
    cout << "5. Go back to Main Menu" << endl;
}

void Interface::showHeuristicMenu() {
    cout << "Heuristic Stats:" << endl;
    cout << "1. Check Flight Stats" << endl;
    cout << "2. Check Route Info" << endl;
    cout << "3. Execution Time" << endl;
    cout << "4. Go back to Main Menu" << endl;
}


void Interface::showFlightNetSettingsMenu() {

    cout << "Settings:" << endl;
    cout << "1. Change crew shift duration" << endl;
    cout << "2. Change airplane maximum flight duration (without refuelling)" << endl;
    cout << "3. Change airplane capacity"<< endl;
    cout << "4. Go back to Main Menu" << endl;

}


void Interface::processMainMenu() {

    system("CLS");

    showMainMenu();

    string message = "Select a valid option: ";
    string invalid = "Invalid option. Please try again.\n";
    int input = readInput(1, 5, message, invalid);

    switch (input) {
        case 1:
            processAlgorithmsMenu();
            break;
        case 2: {
            double duration;
            Vertex *origin = calculateHeuristic(duration);
            processFlightsMenu(origin, duration);
        }
            break;
        case 3:
            showMap();
            break;
        case 4: {
            processFlightNetSettingsMenu();
        }
            break;
        default:
                return;
        }
            processMainMenu();
    }

void Interface::processAlgorithmsMenu() {
    chrono::steady_clock::time_point begin;
    chrono::steady_clock::time_point end;

    system("CLS");

    showAlgorithmsMenu();

    string message = "Select a valid option: ";
    string invalid = "Invalid option. Please try again.\n";
    int input = readInput(1, 5, message, invalid);

    Vertex *origin, *destination;
    chooseAirports(&origin, &destination);

    system("CLS");

    switch (input) {
        case 1: {
            cout << "Dijkstra's One-To-Many Algorithm" << endl;

            begin = chrono::steady_clock::now();

            dijkstra->DijkstraOneToMany(*origin->getInfo());

            end = chrono::steady_clock::now();

            vector<Airport *> path = dijkstra->getPath(*origin->getInfo(), *destination->getInfo());

            if (path.empty()) cout << "There is no connection between the two airports!" << endl;
            else {

                cout << "The algorithm was completed in "
                     << (chrono::duration_cast<chrono::microseconds>(end - begin).count()) / 1000000.0
                     << " seconds." << endl;
                cout << "Path between airports:" << endl;
                for (auto it = path.begin(); it != path.end(); it++) {
                    cout << (*it)->getId();
                    if ((it + 1) != path.end()) cout << " -> ";
                }
                cout << endl;

                cout << "Loading path in Map..." << endl;
                processPathMap(path);
            }
            system("Pause");
        }
            break;
        case 2: {
            cout << "Dijkstra's Two-Points Algorithm" << endl;

            begin = chrono::steady_clock::now();

            dijkstra->DijkstraTwoPoints(*origin->getInfo(), *destination->getInfo());

            end = chrono::steady_clock::now();

            vector<Airport *> path = dijkstra->getPath(*origin->getInfo(), *destination->getInfo());

            if (path.empty()) cout << "There is no connection between the two airports!" << endl;
            else {
                cout << "The algorithm was completed in "
                     << (chrono::duration_cast<chrono::microseconds>(end - begin).count()) / 1000000.0
                     << " seconds." << endl;
                cout << "Path between airports:" << endl;
                for (auto it = path.begin(); it != path.end(); it++) {
                    cout << (*it)->getId();
                    if ((it + 1) != path.end()) cout << " -> ";
                }
                cout << endl;

                cout << "Loading path in Map..." << endl;
                processPathMap(path);
            }
            system("Pause");
        }
            break;
        case 3: {
            cout << "Bidirectional Dijkstra Algorithm" << endl;

            begin = chrono::steady_clock::now();

            dijkstra->BidirectionalDijkstra(*origin->getInfo(), *destination->getInfo(), this->reverseGraph);

            end = chrono::steady_clock::now();

            vector<Airport *> path = dijkstra->getBiDirPath(*origin->getInfo(), *destination->getInfo());

            if (path.empty()) cout << "There is no connection between the two airports!" << endl;
            else {
                cout << "The algorithm was completed in "
                     << (chrono::duration_cast<chrono::microseconds>(end - begin).count()) / 1000000.0
                     << " seconds." << endl;
                cout << "Path between airports:" << endl;
                for (auto it = path.begin(); it != path.end(); it++) {
                    cout << (*it)->getId();
                    if ((it + 1) != path.end()) cout << " -> ";
                }
                cout << endl;
                cout << "Loading path in Map..." << endl;
                processPathMap(path);
            }
            system("Pause");
        }
            break;
        case 4: {
            cout << "A-Star Two Points Algorithm" << endl;

            begin = chrono::steady_clock::now();

            astar->AStarTwoPoints(*origin->getInfo(), *destination->getInfo());

            end = chrono::steady_clock::now();

            vector<Airport *> path = astar->getPath(*origin->getInfo(), *destination->getInfo());

            if (path.empty()) cout << "There is no connection between the two airports!" << endl;
            else {
                cout << "The algorithm was completed in "
                     << (chrono::duration_cast<chrono::microseconds>(end - begin).count()) / 1000000.0
                     << " seconds." << endl;
                cout << "Path between airports:" << endl;
                for (auto it = path.begin(); it != path.end(); it++) {
                    cout << (*it)->getId();
                    if ((it + 1) != path.end()) cout << " -> ";
                }
                cout << endl;
                cout << "Loading path in Map..." << endl;
                processPathMap(path);
            }
            system("Pause");
        }
        default:
            break;

    }
}

Vertex *Interface::calculateHeuristic(double &duration) {
    chrono::steady_clock::time_point begin;
    chrono::steady_clock::time_point end;

    system("CLS");

    Vertex *origin;
    chooseOriginAirport(&origin);

    system("CLS");
    cout << "Loading Heuristic Stats..." << endl;

    begin = chrono::steady_clock::now();

    this->heuristic = new Heuristic(this->graph, flightNet->getPassengers(),
                                    flightNet->getCapacity(), origin->getInfo());
    int c = 0;
    for (auto v: graph->getVertexSet()) {
        if (*origin->getInfo() != *v->getInfo()) {
            heuristic->generateFlights(*origin->getInfo(), *v->getInfo());
            heuristic->generateFlights(*v->getInfo(), *origin->getInfo());
        }
    }

    end = chrono::steady_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - begin).count() / 1000000.0;

    return origin;
}

void Interface::processFlightsMenu(Vertex *origin, double duration) {

    system("CLS");

    showHeuristicMenu();

    string message = "Select a valid option: ";
    string invalid = "Invalid option. Please try again.\n";
    int input = readInput(1, 4, message, invalid);

    processFlightsStatsMenu(origin, input, duration);
}

void Interface::processFlightsStatsMenu(Vertex *origin, int input, double duration) {

    switch (input) {
        case 1: {
            showStats(origin->getInfo());
            system("pause");

            processFlightsMenu(origin, duration);
        }
            break;
        case 2: {
            showRouteInfo();
            system("pause");

            processFlightsMenu(origin, duration);
        }
            break;
        case 3: {
            system("CLS");
            cout << "The proposed heuristic was completed in " << duration << " seconds." << endl;
            system("pause");
            processFlightsMenu(origin, duration);
        }
        default:
            break;
    }

}

void Interface::processFlightNetSettingsMenu(){
    system("CLS");

    showFlightNetSettingsMenu();

    string message = "Select a valid option: ";
    string invalid = "Invalid option. Please try again.\n";
    int input =  readInput(1,4, message, invalid);

    processFlightNetSettingsChanges(input);
}

void Interface::processFlightNetSettingsChanges(int input) {
    string message, invalid;

    switch (input) {
        case 1: {
            message = "Crew shift duration: (4 to 10 hours) ";
            invalid = "Invalid time. Please try again.\n";
            input = readInput(4, 10, message, invalid);

            this->flightNet->setShiftDuration(input);

            system("pause");
            processFlightNetSettingsMenu();
        }
            break;
        case 2: {
            message = "Maximum flight duration: (4 to 10 hours) ";
            invalid = "Invalid time. Please try again.\n";
            input = readInput(4, 10, message, invalid);

            this->flightNet->setFuelDuration(input);


            system("pause");
            processFlightNetSettingsMenu();
        }
            break;
        case 3: {
            message = "Airplane capacity: (20 to 850 people) ";
            invalid = "Invalid time. Please try again.\n";
            input = readInput(20, 850, message, invalid);

            this->flightNet->setCapacity(input);

            system("pause");
            processFlightNetSettingsMenu();
        }
            break;
        default:
            break;
    }
}

void Interface::showStats(Airport *origin) {
    system("CLS");
    cout << "Flight Stats: " << endl;

    stats = new Stats(this->graph, origin);
    cout << "Total of passengers transported from the origin to the final"
            " destination: " << stats->nrSrcDestPassengersTransported() << endl;
    cout << "Total of passengers transported whose departure or arrival is different than the origin "
            "or final destination: " << stats->nrNonSrcDestPassengersTransported() << endl;
    cout << "Total of passengers transported: " << stats->nrPassengersTransported() << endl;

    cout << endl;

    cout << "Average passengers from the origin per flight: " << stats->srcPassengersPerFlight() << endl;
    cout << "Average passengers with other origin or destination "
            "per flight: " << stats->nonSrcPassengersPerFlight() << endl;
    cout << "Average passengers per flight: " << stats->allPassengersPerFlight() << endl;

    cout << endl;

    cout << "Average passengers in the first half processing: " << stats->firstHalfPassengers() << endl;
    cout << "Average passengers in the second half processing: " << stats->secondHalfPassengers() << endl;

    cout << endl;

    cout << "Total number of flights: " << stats->nrFlights() << endl;
    cout << "Total number of routes(a group of flights): " << stats->nrRoutes() << endl;
    cout << "Total number of routes from the source: " << stats->nrSrcRoutes() << endl;

}

void Interface::showRouteInfo() {
    system("CLS");

    Vertex *orig;
    Vertex *dest;
    chooseAirports(&orig, &dest);
    bool flag = false;

    vector<vector<Flight *>> routes = orig->getInfo()->getRoutes();

    for (auto flights: routes) {
        if (flights.size() != 0 && flights[0]->getMainDest() == dest->getInfo()->getId()) {
            flag = true;
            cout << "Route from " << orig->getInfo()->getName() << "(" << orig->getInfo()->getId() << ") to "
                 << dest->getInfo()->getName() << "(" << dest->getInfo()->getId()
                 << ") Flights passenger number sequence:";
            for (auto flight: flights)
                cout << " " << flight->getSeats();
            cout << endl;
        }
    }
    if (!flag)
        cout << "There is no route from " << orig->getInfo()->getName() << "(" << orig->getInfo()->getId()
             << ") to "
             << dest->getInfo()->getName() << "(" <<
             dest->getInfo()->getId() << ")" << endl;
}

void Interface::showMap() {
    system("CLS");

    cout << "Loading Map..." << endl;

    GraphMap *graphMap = new GraphMap();

    vector<Vertex *> badWeatherVertexes = flightNet->getBadWeatherReg();
    vector<Vertex *> isolatedVertexes = flightNet->getIsolatedReg();
    graphMap->graphViewerAllNodes(this->graph, badWeatherVertexes, isolatedVertexes);

    graphMap->graphViewerCreateWindow();
    graphMap->graphViewerJoin();

    delete graphMap;

    system("pause");

}

void Interface::chooseOriginAirport(Vertex **originVertex) {
    while (true) {
        string message = "Select an origin airport: (1 to 3425) ";
        string invalid = "Invalid input. Please try again.\n";
        int input = readInput(1, 3425, message, invalid);

        Airport origin(input, Position(0, 0));
        *originVertex = this->graph->findVertex(origin);

        if (*originVertex == nullptr)
            cout << "FlightNet doesn't work in that airport or it's weather conditions are bad. Please try again." << endl;
        else break;
    }
}

void Interface::chooseDestinationAirport(Vertex **destVertex) {
    while (true) {
        string message = "Select a destination airport: (1 to 3425) ";
        string invalid = "Invalid input. Please try again.\n";
        int input = readInput(1, 3425, message, invalid);

        Airport dest(input, Position(0, 0));
        *destVertex = this->graph->findVertex(dest);

        if (*destVertex == nullptr)
            cout << "FlightNet doesn't work in that airport or it's weather conditions are bad. Please try again."<< endl;
        else break;
    }
}

void Interface::chooseAirports(Vertex **originVertex, Vertex **destVertex) {
    chooseOriginAirport(originVertex);
    chooseDestinationAirport(destVertex);
}

void Interface::processPathMap(const vector<Airport *> &path) {
    Vertex *src = graph->findVertex(*path[0]);
    Vertex *dest = graph->findVertex(*(path[path.size() - 1]));

    Vertex *vertex, *next;
    GraphMap *graphMap = new GraphMap();

    graphMap->graphViewerSetup(this->graph);

    graphMap->setVertexLabel(src, "source");
    graphMap->setVertexColor(src, "MAGENTA");
    graphMap->setVertexSize(src, 40.0);


    for (auto it = path.begin(); it != path.end(); it++) {
        vertex = graph->findVertex(*(*it));
        if (it != path.begin() && it != path.end()) {
            graphMap->setVertexColor(vertex, "YELLOW");
            graphMap->setVertexSize(vertex, 20.0);
        }

        if ((it + 1) != path.end()) {
            next = graph->findVertex(*(*(it + 1)));
            graphMap->activateEdge(vertex, next, "CYAN");
        }
    }

    graphMap->setVertexLabel(dest, "destination");
    graphMap->setVertexColor(dest, "MAGENTA");
    graphMap->setVertexSize(dest, 40.0);


    graphMap->graphViewerCreateWindow();

    graphMap->graphViewerJoin();

    delete graphMap;
}
