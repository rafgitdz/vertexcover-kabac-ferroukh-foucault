/*-----------------------------------------------------------------------------*
 *               *Project of Complexity and Applied Algorithmic*               *
 *-----------------------------------------------------------------------------*
 *        Authors :                                                            *
 *                  Milan Kabac (milan.kabac@etu.u-bordeaux1.fr)               *
 *             Matthieu Foucault (matthieu.foucault@etu.u-bordeaux1.fr)        *
 *                 Rafik Ferroukh (rafik.ferroukh@etu.u-bordeaux1.fr)          *
 *-----------------------------------------------------------------------------*
 *              University Bordeaux 1, Software Engineering, Master 2          *
 *                                *2011/2012*                                  *
 * ----------------------------------------------------------------------------*
 * DrawGraph.cpp                                                               *
 * GraphViz (DOT) link : http://www.graphviz.org/                              *
 * Goal : draw a graph and export it in a png format file with DOT             *
 * Include => class Graph, a Tree is a Graph, inherits all methods from Graph  *
 *____________________________________________________________________________*/

#ifndef DRAWGRAPH_H
#define	DRAWGRAPH_H

#include "../generation/Graph.h"

class DrawGraph {
public:

    DrawGraph() {
    };

    virtual ~DrawGraph() {
    };

    /*
     * Get the graph to draw, the set of the vertexCover to colour, and the path
     * of the file where will be export the draw
     */
    void drawGraph(Graph graph, std::set<int> vertexCover, char* pictureFile);

    // convert int to string
    std::string convertToString(int toConvert);

    // convert char* to string
    std::string convertToString(char *toConvert);

};

#endif	/* DRAWGRAPH_H */

