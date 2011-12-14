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
 * Goal : Optimal vertex cover algorithm for trees   	  	   				   *
 *____________________________________________________________________________*/

#include "OptimalTreeAlgorithm.h"

using namespace std;

OptimalTreeAlgorithm::OptimalTreeAlgorithm(Tree tree) : Algorithm(tree) {
    _algorithm = new SearchAlgorithm();
    _graphWithoutLeaves = _algorithm->breadthFirstSearchWithoutLeaves
            										(tree, tree.getRoot());
}

OptimalTreeAlgorithm::~OptimalTreeAlgorithm() {
    delete _algorithm;
}

bool OptimalTreeAlgorithm::setContains(int vertex, set<int> set) {
    return set.find(vertex) != set.end();
}

int OptimalTreeAlgorithm::getParent(int vertex) {
    return _algorithm->pi(vertex);
}

set<int> OptimalTreeAlgorithm::getVertexCover() {
    set<int> vertexCoverSet;
    list<int>::const_iterator graphIterator = _graphWithoutLeaves.end();

    do {
        --graphIterator;
        set<int> neighbours = m_graph.getNeighbours(*graphIterator);

        set<int>::const_iterator neighbourIterator;
        for (neighbourIterator = neighbours.begin();
                neighbourIterator != neighbours.end();
                neighbourIterator++) {
            if ((!setContains(*neighbourIterator, vertexCoverSet)) &&
                    (getParent(*graphIterator) != *neighbourIterator)) {
                vertexCoverSet.insert(*graphIterator);
                break;
            }
        }

    } while (graphIterator != _graphWithoutLeaves.begin());

    return vertexCoverSet;
}
