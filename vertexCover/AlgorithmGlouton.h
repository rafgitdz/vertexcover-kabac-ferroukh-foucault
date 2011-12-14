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
 * Goal : Greedy algorithm for the vertex cover problem. 			    	   *
 *____________________________________________________________________________*/

#ifndef ALGORITHMGLOUTON_H_
#define ALGORITHMGLOUTON_H_

#include "Algorithm.h"
#include <set>

class AlgorithmGlouton : public Algorithm {
public:
	AlgorithmGlouton(const Graph& graph) : Algorithm(graph) {};

	/*
	 * Returns the found vertex cover
	 * Return : the vertex cover
	 * Complexity : addVertextoVC complexity +
	 * 				O(n*(neigh*log(n) + log(n))) where
	 * 					n -	number of vertices in the graph
	 * 					neigh - number of vertice's neighbours
	 */
	virtual std::set<int> getCover();

	/*
	 * Removes isolated vertices from the graph and adds the vertex
	 * with the highest degree to the vertex cover
	 * Return : the vertex added to the vertex cover
	 * Complexity : O(n*(neigh*log(n) + log(n)) + log(n)) where
	 * 					n - graph size
	 * 					neigh - number of vertice's neighbours
	 */
	int addVertexToVC();

protected:
	std::set<int> vertexCover_;
};

#endif /* ALGORITHMGLOUTON_H_ */
