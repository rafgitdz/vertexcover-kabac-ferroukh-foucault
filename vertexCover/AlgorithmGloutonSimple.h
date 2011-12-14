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
 * Goal : A variation of the greedy algorithm. The algorithm orders 		   *
 * 		  the vertices by their initial degree and uses the generated 		   *
 * 		  sequence to get the vertex cover									   *
 *____________________________________________________________________________*/

#ifndef ALGORITHMGLOUTONSIMPLE_H_
#define ALGORITHMGLOUTONSIMPLE_H_

#include "AlgorithmGlouton.h"

using namespace std;

class AlgorithmGloutonSimple : public AlgorithmGlouton {
public:
	/*
	 * Constructor
	 * Complexity : AlgorithmGlouton complexity
	 */
	AlgorithmGloutonSimple(const Graph& graph) : AlgorithmGlouton(graph) {};

	/*
	 * Returns the found vertex cover
	 * Return : std::set<int>
	 * Complexity : O(n*log(n) + n*(log(n) + (neigh*log(n) + log(n)))) where
	 * 					n -	number of vertices in the graph
	 * 					neigh - number of vertice's neighbours
	 */
	virtual std::set<int> getCover();
private:
	multimap<int, int> vertexDegree;
};

#endif /* ALGORITHMGLOUTONSIMPLE_H_ */
