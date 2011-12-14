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
 * Goal : Build a SimpleGraph containing a vertex cover					       *
 *____________________________________________________________________________*/

#ifndef SMALLCOVERGRAPH_H_
#define SMALLCOVERGRAPH_H_

#include "SimpleGraph.h"

class SmallCoverGraph : public SimpleGraph {
public:
	/*
	 * Generates a SimpleGraph containing a vertex cover
	 * Parameters:	vertexCount - number of vertices in the graph
	 * 			   	edgeProba - probability of drawing an edge between
	 * 			   				two vertices
	 * 			   	coverSize - size of the vertex cover to be generated
	 * Complexity:	SimpleGraph complexity +
	 * 				O(|cs| + |n-cs|*log(n-cs) + |n-cs|*|cs|*log(n))
	 */
	SmallCoverGraph(unsigned vertexCount, float edgeProba, unsigned coverSize);
	~SmallCoverGraph(){};
private:
	std::set<int> verticesInVC;
	std::set<int> verticesOutOfVC;
};

#endif /* SMALLCOVERGRAPH_H_ */
