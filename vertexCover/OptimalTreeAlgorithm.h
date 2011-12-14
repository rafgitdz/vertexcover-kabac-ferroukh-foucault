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
 * Goal : Gets the optimal cover of a bipartite graph				    	   *
 *_____________________________________________________________________________*/

#ifndef OPTIMALTREEALGORITHM_H_
#define OPTIMALTREEALGORITHM_H_

#include "Algorithm.h"
#include "../generation/Tree.h"
#include "SearchAlgorithm.h"

class OptimalTreeAlgorithm : public Algorithm {
public:
	OptimalTreeAlgorithm(Tree tree);
	virtual ~OptimalTreeAlgorithm();
	std::set<int> getVertexCover();
	bool setContains(int vertex, std::set<int> set);
	int getParent(int vertex);

private:
	std::list<int> _graphWithoutLeaves;
	SearchAlgorithm* _algorithm;

};

#endif /* OPTIMALTREEALGORITHM_H_ */
