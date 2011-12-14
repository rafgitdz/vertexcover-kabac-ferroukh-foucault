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
#ifndef BIPARTITEOPTIMALCOVER_H_
#define BIPARTITEOPTIMALCOVER_H_

#include "OrientedGraph.h"
#include "SearchAlgorithm.h"
#include "../generation/BipartiteGraph.h"



class AlgorithmBipartiteOptimal {
public:
	AlgorithmBipartiteOptimal(const BipartiteGraph&);
	/*
	 * To get the cover of a bipartite graph, we use an algorithm based on
	 * the max flow and min cut, of an oriented graph where all the vertices
	 * of the first part are connected to the source, and all the vertices of
	 * the second part are connected to the target
	 * Complexity : TODO
	 */
	std::set<int> getCover();

private :
	void buildMaxFlow();

	BipartiteGraph m_graph;
	OrientedGraph m_flowGraph;
	int m_sourceVertex;
	int m_targetVertex;
	SearchAlgorithm m_search;

};

#endif /* BIPARTITEOPTIMALCOVER_H_ */
