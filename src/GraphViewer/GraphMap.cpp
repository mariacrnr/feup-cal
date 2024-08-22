#include <iostream>
#include "../../include/GraphViewer/GraphMap.h"

GraphMap::GraphMap() {
}
void GraphMap::graphViewerSetup(const Graph *graph){
    gvInit();

    gvReadVertex(graph, sf::Color(205,205,205));
    gvReadEdges(graph, sf::Color(205,205,205));
}

void GraphMap::graphViewerAllNodes(const Graph *graph, vector<Vertex*> &badWeatherReg,
                                   vector<Vertex*> &isolatedVertex){
    gvInit();
    gvReadVertex(graph, sf::Color::Red);
    gvReadVertexReg(badWeatherReg); // read weather affected nodes
    gvReadIsolatedVertex(badWeatherReg.size(),isolatedVertex); //read isolated vertex
    gvReadEdges(graph, sf::Color::Black);
}

void GraphMap::gvInit(){
    gv.setCenter(sf::Vector2f(0,0));
    gv.setBackground("../data/background.png",sf::Vector2f(-1120, -800), sf::Vector2f(1.3, 1.3));
}

void GraphMap::nodeSetup(gvNode &node, sf::Color color){
    node.setColor(color);
    node.setSize(5); // reducing size
    node.setOutlineThickness(0.1);
    node.setOutlineColor(color);
}


void GraphMap::gvReadVertex(const Graph *graph, const sf::Color &color){
    vector<Vertex*> v = graph->getVertexSet();
    for (int i = 0, totalCount = 0;i < v.size(); i++, totalCount++) {

        if (v[i]->getInfo()->getId() - 1 == totalCount){
            Position p = v[i]->getInfo()->getPosition();
            viewerNodes.push_back(&gv.addNode(v[i]->getInfo()->getId() - 1,
                                              sf::Vector2f(p.getLongitude()*6.6,
                                                           -p.getLatitude()*6.6))); // Create node in graph viewer storing reference
            nodeSetup(*viewerNodes.back(), color);
        }
        else {
            i--;
            viewerNodes.push_back(nullptr);
        }
    }
}


void GraphMap::gvReadVertexReg(vector<Vertex*> &badWeatherReg){
    for (int i = 0; i < badWeatherReg.size(); i++){
        gvNode *node = &gv.addNode(viewerNodes.size() + i,
                                   sf::Vector2f(badWeatherReg[i]->getInfo()->getPosition().getLongitude()*6.55,
                                                -badWeatherReg[i]->getInfo()->getPosition().getLatitude()*6.55));
        nodeSetup(*node, sf::Color::Blue);
    }
}

void GraphMap::gvReadIsolatedVertex(int begin, vector<Vertex*> &isolatedVertexes){
    for (int i = begin; i < (begin + isolatedVertexes.size()); i++){
        gvNode *node = &gv.addNode(viewerNodes.size() + i,
                                   sf::Vector2f(isolatedVertexes[i-begin]->getInfo()->getPosition().getLongitude()*6.55,
                                                -isolatedVertexes[i-begin]->getInfo()->getPosition().getLatitude()*6.55));
        nodeSetup(*node, sf::Color::Green);
    }
}

void GraphMap::gvReadEdges(const Graph *graph, const sf::Color &color){
    for (auto v: graph->getVertexSet()){
        for (auto e: v->getAdj()){
            viewerEdges.push_back(&gv.addEdge(viewerEdges.size(),
                                              *viewerNodes[v->getInfo()->getId()-1],
                                              *viewerNodes[e.getDest()->getInfo()->getId()-1],
                                              gvEdge::UNDIRECTED));
            // Create edge in graph viewer storing reference
            viewerEdges.back()->setThickness(0.1); // reducing size
            viewerEdges.back()->setColor(color);
        }
    }
}

void GraphMap::activateEdge(Vertex* src, Vertex* dest, const string &colorS){
    sf::Color color = stringToColor(colorS);
    for(auto edge: viewerEdges){
        if(edge->getTo()->getId() == dest->getInfo()->getId() - 1
                && edge->getFrom()->getId() == src->getInfo()->getId() - 1) {
            edge->setColor(color);
            edge->setThickness(7.0);
            break;
        }
    }
}

void GraphMap::setVertexSize(Vertex *src, int size) {
    for(auto node: viewerNodes){
        if(node == nullptr) continue;
        if(node->getId() == src->getInfo()->getId() - 1){
            node->setSize(size);
            break;
        }
    }
}

void GraphMap::setVertexLabel(Vertex* src,const string &label){
    for(auto node: viewerNodes){
        if(node == nullptr) continue;
        if(node->getId() == src->getInfo()->getId() - 1){
            node->setLabel(label);
            break;
        }
    }
}

void GraphMap::setVertexColor(Vertex *src, const string &colorS) {
    sf::Color color = stringToColor(colorS);
    for(auto node: viewerNodes){
        if(node == nullptr) continue;
        if(node->getId() == src->getInfo()->getId() - 1) {
            node->setColor(color);
            break;
        }
    }
}

void GraphMap::graphViewerCreateWindow(){
    gv.createWindow(1900, 1000);
}

void GraphMap::graphViewerJoin(){
    gv.join();
}



sf::Color GraphMap::stringToColor(const string & color){
    if(color == "BLACK") return sf::Color::Black;
    if(color == "WHITE") return sf::Color::White;
    if(color == "RED") return sf::Color::Red;
    if(color == "GREEN") return sf::Color::Green;
    if(color == "BLUE") return sf::Color::Blue;
    if(color == "YELLOW") return sf::Color::Yellow;
    if(color == "MAGENTA") return sf::Color::Magenta;
    if(color == "CYAN") return sf::Color::Cyan;
    return sf::Color(); //default
}