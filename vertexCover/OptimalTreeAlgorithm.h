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
 * Goal : Optimal vertex cover algorithm for trees   	  	   				   *
 *____________________________________________________________________________*/

#ifndef OPTIMALTREEALGORITHM_H_
#define OPTIMALTREEALGORITHM_H_

#include "Algorithm.h"
#include "../generation/Tree.h"
#include "SearchAlgorithm.h"

class OptimalTreeAlgorithm : public Algorithm {
public:
	/*
	 * Constructor
	 * Parameters : tree - determine the optimal vertex cover for the specified tree
	 * Complexity : breadthFirtstSearchLeaves complexity
	 */
	OptimalTreeAlgorithm(Tree tree);
	virtual ~OptimalTreeAlgorithm();

	/*
	 * Returns the found vertex cover
	 * Return :	the found vertex cover
	 * Complexity :	O(nl*(log(n) + neigh(log(v) + log(n) + log(v)))) where
	 * 					nl - graph size without leaves
	 * 					n - graph size
	 * 					neigh - number of vertex neighbours
	 * 					v - vertex cover size
	 */
	std::set<int> getVertexCover();

	/*
	 * Chekcs if a set contains a vertex
	 * Parameters :	vertex - the vertex to find
	 * 				set - the set to look over
	 * Return : true if the set contains the vertex else false
	 * Complexity : Complexity : O(log(n)) where
	 *			 		n - size of the set
	 */
	bool setContains(int vertex, std::set<int> set);

	/*
	 * Returns the parent of the vertex
	 * Parameters :	vertex - the vertex whose parent we need
	 * Return :	the parent of the vertex
	 * Complexity : O(log(n)) where
	 *			 		n - size of the m_numColorVertex
	 */
	int getParent(int vertex);

private:
	std::list<int> _graphWithoutLeaves;
	SearchAlgorithm* _algorithm;

};

#endif /* OPTIMALTREEALGORITHM_H_ */
