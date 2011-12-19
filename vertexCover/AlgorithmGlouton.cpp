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
 * Goal : Greedy algorithm for the vertex cover problem. 			    	   *
 *____________________________________________________________________________*/

#include "AlgorithmGlouton.h"

using namespace std;

/*
 * Removes isolated vertices from the graph and adds the vertex
 * with the highest degree to the vertex cover
 * Return : the vertex added to the vertex cover
 * Complexity : O(n*log(n) + log(n)) where
 * 					n - graph size
 */

int AlgorithmGlouton::addVertexToVC() {
        int vertexPosition(0);
        unsigned int maxDegree(0);

        std::map<int, std::set<int> >::const_iterator it;
        // O(n)
        for (it = m_graph.getBeginGraph(); it != m_graph.getEndGraph(); it++) {
                if (it->second.size() == 0)
                        // neigh = number of vertice's neighbours
                        // O((neigh*log(n) + log(n))
                        m_graph.removeVertex(it->first);
                else
                if (maxDegree < ((it->second).size())) {
                        maxDegree = ((it->second).size());
                        vertexPosition = it->first;
                }
        }
        // O(log(n))
        vertexCover_.insert(vertexPosition);
        return vertexPosition;

}

/*
	std::map<int, std::set<int> >::iterator itBegin = m_graph.getBeginGraph1();
	std::map<int, std::set<int> >::iterator itEnd = m_graph.getEndGraph1();
	std::map<int, std::set<int> >::iterator tmp;
	while(itBegin != itEnd) {
		if (itBegin->second.size() == 0) {
			// O(log(n))
			tmp = itBegin;
			++itBegin;
			m_graph.removeIsolatedVertex((tmp));
		}
		else
			if (maxDegree < ((itBegin->second).size())) {
				maxDegree = ((itBegin->second).size());
				vertexPosition = itBegin->first;
				++itBegin;
			}
	}
    // O(log(n))
    vertexCover_.insert(vertexPosition);
    return vertexPosition;

}
*/
/*
 * Returns the found vertex cover
 * Return : the vertex cover
 * Complexity : addVertextoVC complexity +
 * 				O( n*( (neigh*log(n) + log(n)) + (n*log(n) + log(n)) ) ) where
 * 					n -	number of vertices in the graph
 * 					neigh - number of vertice's neighbours
 */
set<int> AlgorithmGlouton::getCover() {
	while (m_graph.getEdgeCount() > 0) {
		m_graph.removeVertex(addVertexToVC());
	}

	return vertexCover_;
}

