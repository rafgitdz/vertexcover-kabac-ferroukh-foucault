/*-----------------------------------------------------------------------------*
 *            *Project of Complexity and Applied Algorithmic*                  *
 *-----------------------------------------------------------------------------*
 *        Authors :                                                            *
 *                  Milan Kabac (milan.kabac@etu.u-bordeaux1.fr)               *
 *             Matthieu Foucault (matthieu.foucault@etu.u-bordeaux1.fr)        *
 *                 Rafik Ferroukh (rafik.ferroukh@etu.u-bordeaux1.fr)          *
 *-----------------------------------------------------------------------------*
 *              University Bordeaux 1, Software Engineering, Master 2          *
 *                                *2011/2012*                                  *
 * ----------------------------------------------------------------------------*
 * Goal : Build a random graph										    	   *
 * Constructor Parameters : the number of vertices that the graph will have,   *
 *  and the probability to draw an edge between two vertices                   *
 *____________________________________________________________________________*/

#ifndef SIMPLEGRAPH_H_
#define SIMPLEGRAPH_H_

#include "Graph.h"

class SimpleGraph : public Graph {
public:
	/*
	 * Generates a random graph, with vertexCount vertices,
	 * and a probability edgeProba to draw and edge between two graphs
	 * Complexity: TODO
	 */
    SimpleGraph(int vertexCount, float edgeProba);
    virtual ~SimpleGraph(){};

protected:
    int probability;
};

#endif /* SIMPLEGRAPH_H_ */
