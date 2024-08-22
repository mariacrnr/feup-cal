#ifndef INCLUDE_GRAPHMAP_H
#define INCLUDE_GRAPHMAP_H

#include "graphviewer.h"
#include "../Graph/Graph.h"

using gvNode = GraphViewer::Node;
using gvEdge = GraphViewer::Edge;

/**Represents the map of the Graph presented by graph Viewer**/
class GraphMap{
    GraphViewer gv; //graph viewer
    vector<gvNode*> viewerNodes; // nodes to display
    vector<gvEdge*> viewerEdges; // edges to display

public:
    /**GraphMap default constructor
     *
     */
    GraphMap();

    /**Initializes the graph viewer with all the nodes and edges to display
     *
     * @param graph graph to display
     */
    void graphViewerSetup(const Graph *graph);

    /**Initializes the graph viewer with all the nodes and edges to display, including the removed nodes from the graph,
     * such as bad weather nodes and nodes outside of the main SCC
     *
     * @param graph graph to display
     * @param badWeatherReg vector of the bad weather nodes
     * @param isolatedVertex vector of the nodes that are in isolated scc's
     */
    void graphViewerAllNodes(const Graph *graph, vector<Vertex*> &badWeatherReg, vector<Vertex*> &isolatedVertex);

    /**Initializes graph viewer
     *
     */
    void gvInit();

    /** Changes the node display settings
     *
     * @param node node to setup
     * @param color color of the node
     */
    void nodeSetup(gvNode &node, sf::Color color);

    /** Reads the bad weather nodes from the graph provided
     *
     * @param badWeatherReg vector of the bad weather nodes
     */
    void gvReadVertexReg(vector<Vertex*> &badWeatherReg);


    /** Reads the isolated nodes from the graph provided
     *
     * @param begin first index to add to the viewer nodes
     * @param isolatedVertexes vector of vertexes that represent isolated nodes
     */
    void gvReadIsolatedVertex(int begin, vector<Vertex*> &isolatedVertexes);

    /**Reads the vertexes from the graph provided
     *
     * @param graph graph to display
     * @param color color of the vertexes
     */
    void gvReadVertex(const Graph *graph,const sf::Color &color);

    /**Reads the edges from the graph provided
     *
     * @param graph graph to display
     * @param color color of the edges
     */
    void gvReadEdges(const Graph *graph,const  sf::Color &color);

    /**Creates a graph viewer window
     *
     */
    void graphViewerCreateWindow();

    /**Joins the graph viewer window to the main thread
     *
     */
    void graphViewerJoin();

    /**Activates a specific edge in the map
     *
     * @param src source vertex of the edge
     * @param dest destination vertex of the edge
     * @param colorS color string to paint the edge
     */
    void activateEdge(Vertex* src, Vertex* dest, const string &colorS);

    /**Sets a specific vertex size
     *
     * @param src source vertex to resize
     * @param size size of the vertex
     */
    void setVertexSize(Vertex* src, int size);

    /**Sets a specific vertex label
     *
     * @param src source vertex to label
     * @param label label to add to the vertex
     */
    void setVertexLabel(Vertex* src,const string &label);

    /**Sets a specific vertex color
     *
     * @param src source vertex to color
     * @param colorS color string to paint the vertex
     */
    void setVertexColor(Vertex* src, const string &colorS);

    /**Converts a color string to an SF color
     *
     * @param color string to be converted
     * @return converted sf color
     */
    sf::Color stringToColor(const string & color);

};



#endif //INCLUDE_GRAPHMAP_H
