/*
 * AlgorithmDeepSearch.cpp
 *
 *  Created on: 31 oct. 2011
 *      Author: matthieu
 */

#include "AlgorithmDeepSearch.h"

using namespace std;

AlgorithmDeepSearch::AlgorithmDeepSearch(Graph graph) : Algorithm(graph), m_markedVertices() {

}

void AlgorithmDeepSearch::depthFirstSearch(Graph &tree, int vertex) {

	m_markedVertices.insert(vertex);
	set<int> neighbours = m_graph.getNeighbours(vertex);
	for (set<int>::iterator ii = neighbours.begin(); ii != neighbours.end() ; ii++ ) {

		if (m_markedVertices.find(*ii) == m_markedVertices.end()) {
			tree.addVertex(*ii);
			tree.addEdge(vertex,*ii);
			depthFirstSearch(tree,*ii);
		}
	}
}

set<int> AlgorithmDeepSearch::getCover() {

	return getCover(m_graph.getBeginGraph()->first);
}

set<int> AlgorithmDeepSearch::getCover(int treeRoot) {

	Graph tree;
	set<int> cover;
	tree.addVertex(treeRoot);
	depthFirstSearch(tree, treeRoot);
	set<int> vertices = tree.getVertices();
	for (set<int>::iterator ii = vertices.begin(); ii != vertices.end() ; ii++) {
		if (*ii == treeRoot || (tree.getNeighbours(*ii).size() > 1) ) { // if ii is not a leaf

			cover.insert(*ii);
		}
	}

	return cover;
}



AlgorithmDeepSearch::~AlgorithmDeepSearch() {
}

