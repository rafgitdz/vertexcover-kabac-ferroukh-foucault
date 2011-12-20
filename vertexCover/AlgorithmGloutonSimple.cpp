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
 * Goal : A variation of the greedy algorithm. The algorithm orders 		   *
 * 		  the vertices by their initial degree and uses the generated 		   *
 * 		  sequence to get the vertex cover									   *
 *____________________________________________________________________________*/

#include "AlgorithmGloutonSimple.h"

using namespace std;

/*
 * Returns the found vertex cover
 * Return : the found vertex cover
 * Complexity : O(n*log(n) + n*(log(n) + (neigh*log(n) + log(n)))) where
 * 					n -	number of vertices in the graph
 * 					neigh - number of vertice's neighbours
 */
set<int> AlgorithmGloutonSimple::getCover() {
	if (m_graph.getVertexCount() > 0) {
		map<int, set<int> >::const_iterator it;
		multimap<int, int>::const_iterator it1;

		// O(n)
		for (it = m_graph.getBeginGraph(); it != m_graph.getEndGraph(); it++)
			// O(log(n))
			vertexDegree.insert(pair<int, int>((it->second).size(), it->first));

		it1 = vertexDegree.end();
		// O(n)
		do {
			it1--;
			// O(log(n))
			m_vertexCover.insert(it1->second);
			// O(neigh*log(neigh) + log(n) + neigh*log(n) + log(n))
			m_graph.removeVertex(it1->second);
		} while ((m_graph.getEdgeCount() > 0) && (it1 != vertexDegree.begin()));
	}
	return m_vertexCover;
}
