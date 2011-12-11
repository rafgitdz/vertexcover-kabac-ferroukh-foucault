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
 * Goal : Represents a bipartite graph 								    	   *
 * Constructor Parameters : the number of vertices that the graph will have,   *
 * the probability to draw an edge between two vertices, 					   *
 * the ratio between the size of the two parts of the graph                	   *
 *____________________________________________________________________________*/

#ifndef BIPARTITEGRAPH_H_
#define BIPARTITEGRAPH_H_

#include "Graph.h"

class BipartiteGraph: public Graph {
	public:
		BipartiteGraph(const BipartiteGraph&);

		/*
		 * Constructor
		 * Parameters : the size of the graph, the probability to draw an edge
		 * between two vertices, the ratio between the parts of the graph
		 * Complexity : TODO
		 */
		BipartiteGraph(int graphSize, float edgeProba, float partRatio = 0.5);
		inline const std::set<int>& getLeftPart() const {return m_leftPart;}
		inline const std::set<int>& getRightPart() const {return m_rightPart;}

	private:
		std::set<int> m_leftPart;
		std::set<int> m_rightPart;
};

#endif /* BIPARTITEGRAPH_H_ */
