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
 * Goal : Build a random graph with a small cover							   *
 *____________________________________________________________________________*/

#ifndef SMALLCOVERGRAPH_H_
#define SMALLCOVERGRAPH_H_

#include "SimpleGraph.h"

class SmallCoverGraph : public SimpleGraph {
public:
	/*
	 * Generates a random graph, with vertexCount vertices, a probability
	 * edgeProba to draw an edge between two vertices, and a cover of
	 * coverSize vertices
	 */
	SmallCoverGraph(unsigned vertexCount, float edgeProba, unsigned coverSize);
	~SmallCoverGraph(){};
private:
	std::set<int> verticesInVC;
	std::set<int> verticesOutOfVC;
};

#endif /* SMALLCOVERGRAPH_H_ */
