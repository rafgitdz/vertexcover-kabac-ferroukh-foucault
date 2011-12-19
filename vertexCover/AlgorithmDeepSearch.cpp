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
#include <iostream>
using namespace std;

set<int> AlgorithmDeepSearch::getCover() {
    return getCover(m_graph.getBeginGraph()->first);
}


/*
 * Uses the covering tree based on a deep search to find a vertex cover
 * This algorithms return a 2-approached vertex cover
 * Complexity: O(|E| * log(n))
 */
set<int> AlgorithmDeepSearch::getCover(int treeRoot) {
	//cout << "test" << endl;
    set<int> cover = depthFirstSearch(m_graph, treeRoot);
    return cover;
}
