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

#include "OptimalTreeAlgorithm.h"

using namespace std;

/*
 * Constructor
 * Parameters : tree - determine the optimal vertex cover for the specified tree
 * Complexity : breadthFirtstSearchLeaves complexity
 */
OptimalTreeAlgorithm::OptimalTreeAlgorithm(Tree tree) :
		Algorithm(tree) {
	_algorithm = new SearchAlgorithm();
	_graphWithoutLeaves = _algorithm->breadthFirstSearchWithoutLeaves(tree,
			tree.getRoot());
}

/*
 * Destructor
 */
OptimalTreeAlgorithm::~OptimalTreeAlgorithm() {
	delete _algorithm;
}

/*
 * Chekcs if a set contains a vertex
 * Parameters :	vertex - the vertex to find
 * 				set - the set to look over
 * Return : true if the set contains the vertex else false
 * Complexity : Complexity : O(log(n)) where
 *			 		n - size of the set
 */
bool OptimalTreeAlgorithm::setContains(int vertex, set<int> set) {
	// O(log(n))
	return set.find(vertex) != set.end();
}

/*
 * Returns the parent of the vertex
 * Parameters :	vertex - the vertex whose parent we need
 * Return :	the parent of the vertex
 * Complexity : O(log(n)) where
 *			 		n - size of the m_numColorVertex
 */
int OptimalTreeAlgorithm::getParent(int vertex) {
	// O(log(n))
	return _algorithm->pi(vertex);
}

/*
 * Returns the found vertex cover
 * Return :	the found vertex cover
 * Complexity :	O(nl*(log(n) + neigh(log(neigh) + log(n) + log(n)))) where
 * 					nl - number of vertices without leaves
 * 					n - number of graph vertices
 * 					neigh - number of vertex neighbours
 *
 */
set<int> OptimalTreeAlgorithm::getVertexCover() {
	set<int> vertexCoverSet;
	list<int>::const_iterator graphIterator = _graphWithoutLeaves.end();

	// O(nl)
	do {
		--graphIterator;
		//O(log(n))
		set<int> neighbours = m_graph.getNeighbours(*graphIterator);

		set<int>::const_iterator neighbourIterator;
		//O(neigh)
		for (neighbourIterator = neighbours.begin();
				neighbourIterator != neighbours.end(); neighbourIterator++) {
			// O(log(n))
			if ((!setContains(*neighbourIterator, vertexCoverSet))
					// O(log(n))
					&& (getParent(*graphIterator) != *neighbourIterator)) {
				// O(log(n))
				vertexCoverSet.insert(*graphIterator);
				break;
			}
		}
	} while (graphIterator != _graphWithoutLeaves.begin());

	return vertexCoverSet;
}
