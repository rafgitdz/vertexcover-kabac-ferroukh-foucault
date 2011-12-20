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
 * Goal : Uses the covering tree based on a deep search to find a vertex cover *
 *____________________________________________________________________________*/
#include "AlgorithmDeepSearch.h"
using namespace std;

/*
 * Uses the covering tree based on a deep search to find a vertex cover
 * This algorithms return a 2-approached vertex cover
 * Complexity: O(|E| * log(n))
 */
set<int> AlgorithmDeepSearch::getCover() {
	set<int> cover;
	if (m_graph.getVertexCount() > 0) {
		int root = m_graph.getBeginGraph()->first;
		//cout << "test" << endl;
		cover = depthFirstSearch(m_graph, root);
	}
	return cover;

}
