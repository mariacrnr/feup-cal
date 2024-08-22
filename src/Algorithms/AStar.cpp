#include "../../include/Algorithms/AStar.h"

AStar::AStar(Graph *graph): graph(graph){}

double AStar::Heuristic(const Airport &source, const Airport &dest){
    return source.getPosition().getHaversineDistance(dest.getPosition());
}

Vertex *AStar::AStarSetUp(const Airport &source) {
    Vertex* start;

    if((start = graph->findVertex(source)) == nullptr) return nullptr;

    for(Vertex* v: graph->getVertexSet()){

        v->setVisited(false);
        v->setDist(INF);
        v->setPath(nullptr);
        v->setGScore(INF);
        v->queueIndex = 0;

    }

    return start;
}

int AStar::AStarTwoPoints(const Airport &source, const Airport &dest) { //TODO FINISH THIS
    MutablePriorityQueue<Vertex> Q;
    Vertex *origin, *final;

    if((origin = AStarSetUp(source)) == nullptr) return 1;
    if((final = graph->findVertex(dest)) == nullptr) return 1;

    origin->setDist(Heuristic(source,dest));
    origin->setGScore(0);

    Q.insert(origin);

    while(!Q.empty()){

        Vertex* v = Q.extractMin(); //Choose vertex with lowest f-score
        v->setVisited(true);

        if(v == final) break;

        for(const Edge& e: v->getAdj()){

            Vertex* w = e.getDest();

            if(w->getVisited()) continue; //neighbour vertex was already visited so it must be ignored

            double tentativeGScore = v->getGScore() + e.getWeight();

            if(w->getDist() == INF)  Q.insert(w);

            if(tentativeGScore < w->getGScore()) {
                w->setPath(v);
                w->setGScore(tentativeGScore);
                w->setDist(w->getGScore() + Heuristic(*w->getInfo(),dest));
                Q.decreaseKey(w);
            }
            //If tentativeGScore >= w->getGScore is ignored because there is a shorter route to the neighbour
        }
    }
    return 0;
}

vector<Airport*> AStar::getPath(const Airport &source, const Airport &dest) const {
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