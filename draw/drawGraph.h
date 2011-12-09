/*-----------------------------------------------------------------------------*
 *            *Project of Complexity and Applicated Algorithms*                *
 *-----------------------------------------------------------------------------*
 *        Authors :                                                            *
 *                  Milan Kabac (milan.kabac@etu.u-bordeaux1.fr)               *
 *             Matthieu Foucault (matthieu.foucault@etu.u-bordeaux1.fr)        *
 *                 Ferroukh Rafik (rafik.ferroukh@etu.u-bordeaux1.fr)          *
 *-----------------------------------------------------------------------------*
 *              University Bordeaux 1, Software Engineering, Master 2          *
 *                                *2011/2012*                                  *
 * ----------------------------------------------------------------------------*
 * DrawGraph.h                                                                 *
 * Goal :                                                                      *
 * Parameters :                                                                *
 * Include => class Graph, a Tree is a Graph, inherits all methods from Graph  *
 *____________________________________________________________________________*/

#ifndef DRAWGRAPH_H
#define	DRAWGRAPH_H

#include "../generation/Graph.h"

class DrawGraph {
public:
    DrawGraph();
    virtual ~DrawGraph();

    void drawGraph(Graph graph, std::list<int> vertexCover, char* pictureFile);
    std::string convertToString(int toConvert);
    std::string convertToString(char *toConvert);

};

#endif	/* DRAWGRAPH_H */

