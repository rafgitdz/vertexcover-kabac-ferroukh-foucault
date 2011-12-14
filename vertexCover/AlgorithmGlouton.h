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

#ifndef ALGORITHMGLOUTON_H_
#define ALGORITHMGLOUTON_H_

#include "Algorithm.h"
#include <set>

class AlgorithmGlouton : public Algorithm {
public:
	AlgorithmGlouton(const Graph& graph) : Algorithm(graph) {};
	virtual std::set<int> getCover();
	int addVertexToVC();

protected:
	std::set<int> vertexCover_;
};

#endif /* ALGORITHMGLOUTON_H_ */
