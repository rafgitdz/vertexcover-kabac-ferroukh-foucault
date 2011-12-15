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

set<int> AlgorithmDeepSearch::getCover() {
    return getCover(m_graph.getBeginGraph()->first);
}


/*
 * Uses the covering tree based on a deep search to find a vertex cover
 * This algorithms return a 2-approached vertex cover
 * Complexity: TODO
 */
set<int> AlgorithmDeepSearch::getCover(int treeRoot) {

    Graph tree;
    set<int> cover;
    depthFirstSearch(m_graph, tree, treeRoot);
    set<int> vertices = tree.getVertices();

    for (set<int>::iterator ii = vertices.begin(); ii != vertices.end(); ii++) {

        if (*ii == treeRoot || (tree.getNeighbours(*ii).size() > 1)) // if ii is not a leaf
            cover.insert(*ii);
    }
    return cover;
}
