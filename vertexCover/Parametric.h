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
 * Goal : Gets the optimal cover of a graph. This algorithm is recursive, and  *
 * can only be used on graphs with a small cover					    	   *
 *_____________________________________________________________________________*/
#ifndef PARAMETRIC_H_
#define PARAMETRIC_H_

#include "../generation/Graph.h"
#include "Algorithm.h"

class Parametric : public Algorithm {
public:
	Parametric(const Graph& graph) : Algorithm(graph){};

	bool tryGetCover(unsigned maxCoverSize, std::set<int> &cover);
	bool tryGetCoverBis(unsigned maxCoverSize, std::set<int> &cover);
private:
	bool tryGetCover(Graph g, unsigned maxCoverSize, std::set<int> &cover);
	bool tryGetCoverBis(Graph g, unsigned maxCoverSize, std::set<int> &cover);
};

#endif /* PARAMETRIC_H_ */
