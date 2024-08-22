#include "../../include/Algorithms/Dijkstra.h"

Dijkstra::Dijkstra(Graph *graph): graph(graph) {}

Vertex* Dijkstra::DijkstraSetUp(const Airport & source, bool backwards){
    Vertex* start;

    if(backwards){
        if((start = reverseGraph->findVertex(source)) == nullptr) return nullptr;

        for(Vertex* v: reverseGraph->getVertexSet()){
            v->setVisited(false);
            v->setDist(INF);
            v->setPath(nullptr);
            v->queueIndex = 0;
        }

    } else{
        if((start = graph->findVertex(source)) == nullptr) return nullptr;

        for(Vertex* v: graph->getVertexSet()){
            v->setVisited(false);
            v->setDist(INF);
            v->setPath(nullptr);
            v->queueIndex = 0;
        }
    }

    start->setDist(0);

    return start;
}

int Dijkstra::DijkstraOneToMany(const Airport & source){
    MutablePriorityQueue<Vertex> Q;
    Vertex* origin;

    if((origin = DijkstraSetUp(source,false)) == nullptr) return 1;

    Q.insert(origin);

    while(!Q.empty()){

        Vertex* v = Q.extractMin();
        v->setVisited(true);

        for(const Edge& e: v->getAdj()){

            Vertex* w = e.getDest();
            double length = v->getDist() + e.getWeight();
            double oldDist = w->getDist();

            if(oldDist > length){
                w->setDist(length);
                w->setPath(v);

                if(oldDist == INF) Q.insert(w);
                else Q.decreaseKey(w);
            }

        }
    }
    return 0;
}

int Dijkstra::DijkstraTwoPoints(const Airport & source, const Airport & dest){
    MutablePriorityQueue<Vertex> Q;
    Vertex *origin, *final;

    if((origin = DijkstraSetUp(source,false)) == nullptr) return 1;
    if((final = graph->findVertex(dest)) == nullptr) return 1;

    Q.insert(origin);

    while(!Q.empty()){

        Vertex* v = Q.extractMin();
        v->setVisited(true);

        if(v == final) break;

        for(const Edge& e: v->getAdj()){

            Vertex* w = e.getDest();
            double length = v->getDist() + e.getWeight();
            double oldDist = w->getDist();

            if(oldDist > length){

                w->setDist(length);
                w->setPath(v);

                if(oldDist == INF) Q.insert(w);
                else Q.decreaseKey(w);
            }

        }
    }
    return 0;
}

int Dijkstra::BidirectionalDijkstra(const Airport & source, const Airport & dest, Graph* reverseGraph){
    MutablePriorityQueue<Vertex> forwardQ, backwardsQ;
    Vertex *origin, *final;
    set<Vertex*> processedF, processedB;

    this->reverseGraph = reverseGraph;
    double mu = INF;

    if((origin = DijkstraSetUp(source,false)) == nullptr) return 1;
    if((final = DijkstraSetUp(dest,true)) == nullptr) return 1;

    forwardQ.insert(origin);
    backwardsQ.insert(final);

    while(!forwardQ.empty() && !backwardsQ.empty()) {

        Vertex *vf = forwardQ.extractMin();
        processedF.insert(vf);

        Vertex *vb = backwardsQ.extractMin();
        processedB.insert(vb);

        if(vf->getDist() + vb->getDist() >= mu) break; //mu is the true distance between the two points

        //Forward Search
        for (const Edge &e: vf->getAdj()) {

            Vertex *w = e.getDest();
            double length = vf->getDist() + e.getWeight();
            double oldDist = w->getDist();

            if (oldDist > length) {
                w->setDist(length);
                w->setPath(vf);

                if (oldDist == INF) forwardQ.insert(w);
                else forwardQ.decreaseKey(w);
            }

            Vertex* reverseW = reverseGraph->findVertex(*w->getInfo());

            if((processedB.find(reverseW) != processedB.end()) && (length + reverseW->getDist() < mu)){
                mu = length + reverseW->getDist();
                this->midPoint = w;
            }

        }

        //Backwards Search
        for (const Edge &e: vb->getAdj()) {

            Vertex *w = e.getDest();
            double length = vb->getDist() + e.getWeight();
            double oldDist = w->getDist();

            if (oldDist > length) {
                w->setDist(length);
                w->setPath(vb);

                if (oldDist == INF) backwardsQ.insert(w);
                else backwardsQ.decreaseKey(w);

            }

            Vertex* forwardW = graph->findVertex(*w->getInfo());

            if((processedF.find(forwardW) != processedF.end()) && (length + forwardW->getDist() < mu)){
                mu = length + forwardW->getDist();
                this->midPoint = w;
            }
        }
    }
    return 0;
}

vector<Airport*> Dijkstra::getBackPath(const Airport &source, const Airport &dest) const {
    vector<Airport*> path;
    Vertex *origin, *final;

    if((origin = reverseGraph->findVertex(source)) == nullptr) return path;
    if((final = reverseGraph->findVertex(dest)) == nullptr) return path;

    if(origin->getDist() == INF) return path; //Vertex is disconnected

    path.push_back(origin->getInfo());

    while(origin != final){
        origin = origin->getPath();
        path.push_back(origin->getInfo());
    }

    return path;
}

vector<Airport*> Dijkstra::getPath(const Airport &source, const Airport &dest) const {
    vector<Airport*> path;
    Vertex *origin, *final;

    if((origin = graph->findVertex(source)) == nullptr) return path;
    if((final = graph->findVertex(dest)) == nullptr) return path;

    if(final->getDist() == INF) return path; //Vertex is disconnected

    path.push_back(final->getInfo());

    while(origin != final){
        final = final->getPath();
        path.push_back(final->getInfo());
    }

    reverse(path.begin(), path.end());

    return path;
}

vector<Airport*> Dijkstra::getBiDirPath(const Airport &origin, const Airport &dest) const {

    vector<Airport*> forwardPath = this->getPath(origin,*this->midPoint->getInfo());
    vector<Airport*> backwardsPath = this->getBackPath(*this->midPoint->getInfo(),dest);

    forwardPath.pop_back();
    forwardPath.insert( forwardPath.end(), backwardsPath.begin(), backwardsPath.end());

    return forwardPath;
}