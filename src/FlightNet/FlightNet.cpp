#include "../../include/FlightNet/FlightNet.h"


FlightNet::FlightNet(): shiftDuration(8), fuelDuration(8), capacity(200) {}

void FlightNet::readAirportsName(Graph *graph){
    int numAirports, id, crewCount = 1;
    string name, line;
    srand(time(NULL));

    ifstream file;
    file.open("..\\data\\airports_full_nodes_names.txt");
    getline(file, line);
    numAirports = stoi(line);

    for (int i = 0; i < numAirports; i++) {
        getline(file, line);

        id = stoi(line.substr(1, line.find(",")));
        line.erase(line.begin(),line.begin() + line.find(",") + 1);

        name = line.substr(0, line.find(")"));

        for (int j = 0; j < (rand() % 10 + 5); j++){
            graph->getVertexAt(id-1)->getInfo()->insertCrew(crewCount);
            crewCount++;
        }

        graph->getVertexAt(id - 1)->getInfo()->setName(name);
    }
}


void FlightNet::readAirportsPos(Graph* graph){
    int numAirports, id;
    double lat, lon;
    string line, number;

    ifstream file;
    file.open("..\\data\\airports_full_nodes_latlng.txt");
    getline(file, line);
    numAirports = stoi(line);

    for (int i = 0; i < numAirports; i++) {
        getline(file, line);

        id = stoi(line.substr(1, line.find(",")));
        line.erase(line.begin(),line.begin() + line.find(",") + 1);

        lat = stod(line.substr(0, line.find(",")));
        line.erase(line.begin(),line.begin() + line.find(",") + 1);

        lon = stod(line.substr(0, line.find(")")));


        Position airportLocation(lat,lon);
        Airport airport(id,airportLocation);

        graph->addVertex(airport);
    }
}

void FlightNet::readEdges(Graph* graph){
    int numRoutes, id1, id2;
    double weight;
    string line, number;

    ifstream file;
    file.open("..\\data\\airports_full_edges_weights.txt");
    getline(file, line);
    numRoutes = stoi(line);

    for (int i = 0; i < numRoutes; i++) {
        getline(file, line);
        id1 = stoi(line.substr(1, line.find(',')));
        line.erase(line.begin(),line.begin() + line.find(',') + 1);

        id2 = stoi(line.substr(0, line.find(',')));
        line.erase(line.begin(),line.begin() + line.find(',') + 1);

        weight = stod(line.substr(0, line.find(')')));

        Position pos(0.0, 0.0);
        Airport a1(id1, pos);
        Airport a2(id2, pos);

        graph->addEdge(a1, a2, weight);
    }
}

void FlightNet::processRoutes(Graph* graph){
    vector<Vertex*> vertexSet = graph->getVertexSet();

    for (auto v: vertexSet){
        for (auto e: v->getAdj()){
            double dist = v->getInfo()->getPosition().getTimeDistance(e.getDest()->getInfo()->getPosition());

            if (dist > min(shiftDuration, fuelDuration)){
                graph->removeEdge(*v->getInfo(), *e.getDest()->getInfo());
            }
        }
    }
}

void FlightNet::processWeather(Graph* graph){
    vector<Vertex*> vertexSet = graph->getVertexSet();
    srand(time(NULL));

    for (auto v: vertexSet){
        if (rand() % 100 == 0){ // one in one hundred airports will be chosen to have bad weather
            for(auto e: v->getAdj()){
                if (rand() % (v->getAdj().size() / 10 + 2) == 0) // a few of the adjacent airports might get affected
                badWeatherReg.push_back(v); // store the airport removed
                graph->removeVertex(*v->getInfo());
            }
        }
    }
}

void FlightNet::createPassengers(Graph *graph){
    srand(time(NULL));

    for (auto v1: graph->getVertexSet()){
        unordered_map<int, int> airportPassengers;

        for (auto v2: graph->getVertexSet()){
            if (*v1->getInfo() != *v2->getInfo()){

                double dist = v1->getInfo()->getPosition().getTimeDistance(v2->getInfo()->getPosition());
                int passengerCount = rand() % 500/dist;
                // to reduce processing time, the limit of random defined passengers will not be not very high.
                // Increasing distance generates less customers

                airportPassengers.insert(pair<int, int>(v2->getInfo()->getId(), passengerCount));

            }
        }
        passengers.insert(make_pair(v1->getInfo()->getId(), airportPassengers));


    }
}

int FlightNet::getCapacity() const{
    return capacity;
}

unordered_map<int, unordered_map<int, int>>* FlightNet::getPassengers(){
    return &passengers;
}


Graph FlightNet::readGraphData(){
    Graph graph;

    cout << "Loading Airports Positions..." << endl;
    readAirportsPos(&graph);
    cout << "Loading Airports Names..." << endl;
    readAirportsName(&graph);
    cout << "Loading Graph Edges..." << endl;
    readEdges(&graph);

    return graph;

}

void FlightNet::flightNetSetup(Graph* graph){
    Tarjan* tarjan = new Tarjan(graph);

    cout << "Processing Routes..." << endl;
    processRoutes(graph); // removes all edges whose distance is too big for the plane fuel or the crew work time

    cout << "Processing Weather Conditions..." << endl;
    processWeather(graph); // generates bad weather conditions in a few airports

    cout << "Removing Isolated Airports..." << endl;
    tarjan->run();
    this->isolatedAirports = tarjan->removeIsolatedAirports();

    cout << "Creating Passengers..." << endl;
    createPassengers(graph);
}

void FlightNet::setFuelDuration(int fuelDuration) {
    this->fuelDuration = fuelDuration;
}

void FlightNet::setShiftDuration(int shiftDuration) {
    this->shiftDuration = shiftDuration;
}

void FlightNet::setCapacity(int capacity) {
    this->capacity = capacity;
}

vector<Vertex *> FlightNet::getBadWeatherReg() {
    return this->badWeatherReg;
}

vector<Vertex *> FlightNet::getIsolatedReg() {
    return this->isolatedAirports;
}





