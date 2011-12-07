#include "AlgorithmDeepSearch.h"

using namespace std;

AlgorithmDeepSearch::AlgorithmDeepSearch(Graph graph) : Algorithm(graph), SearchAlgorithm() {
}

set<int> AlgorithmDeepSearch::getCover() {
    return getCover(m_graph.getBeginGraph()->first);
}

set<int> AlgorithmDeepSearch::getCover(int treeRoot) {

    Graph tree;
    set<int> cover;
    tree.addVertex(treeRoot);
    depthFirstSearch(m_graph, tree, treeRoot);
    set<int> vertices = tree.getVertices();
    
    for (set<int>::iterator ii = vertices.begin(); ii != vertices.end(); ii++) {
        
        if (*ii == treeRoot || (tree.getNeighbours(*ii).size() > 1)) // if ii is not a leaf
                cover.insert(*ii);
    }
    return cover;
}

AlgorithmDeepSearch::~AlgorithmDeepSearch() {
}

