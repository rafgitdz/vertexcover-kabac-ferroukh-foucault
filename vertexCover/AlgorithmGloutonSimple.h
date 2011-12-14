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

#ifndef ALGORITHMGLOUTONSIMPLE_H_
#define ALGORITHMGLOUTONSIMPLE_H_

#include "AlgorithmGlouton.h"

using namespace std;

class AlgorithmGloutonSimple : public AlgorithmGlouton {
public:
	AlgorithmGloutonSimple(Graph graph);
	virtual std::set<int> getCover();
private:
	multimap<int, int> vertexDegree;
};

#endif /* ALGORITHMGLOUTONSIMPLE_H_ */
