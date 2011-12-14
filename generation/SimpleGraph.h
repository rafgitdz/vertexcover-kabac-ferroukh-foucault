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
 * Goal : Builds a graph defined by the number of vertices and the			   *
 * 		  probability of an edge between two vertices						   *
 *____________________________________________________________________________*/

#ifndef SIMPLEGRAPH_H_
#define SIMPLEGRAPH_H_

#include "Graph.h"

class SimpleGraph : public Graph {
public:
	/*
	 * Generates a random graph, with vertexCount vertices,
	 * and a probability edgeProba to draw and edge between two vertices
	 * Parameters:	vertexCount - number of vertices in the graph
	 * 			   	edgeProba - probability of drawing an edge between
	 * 			   				two vertices
	 * Complexity:	O(n²*log(n) + n*log(n))
	 */
    SimpleGraph(int vertexCount, float edgeProba);
    virtual ~SimpleGraph(){};

protected:
    int probability;
};

#endif /* SIMPLEGRAPH_H_ */
