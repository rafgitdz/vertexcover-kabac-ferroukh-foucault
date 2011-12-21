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
 * Goal : Represents a bipartite graph with a small cover                      *
 *____________________________________________________________________________*/
#ifndef SMALLCOVERBIPARTITEGRAPH_H_
#define SMALLCOVERBIPARTITEGRAPH_H_

#include "BipartiteGraph.h"
#include <set>

class SmallCoverBipartiteGraph : public BipartiteGraph {
public:
	SmallCoverBipartiteGraph(int graphSize, float edgeProba, float partRatio, int coverSize, float coverRatio);
	virtual ~SmallCoverBipartiteGraph(){};
private:
	std::set<int> m_vcLeft;
	std::set<int> m_vcRight;
};

#endif /* SMALLCOVERBIPARTITEGRAPH_H_ */
