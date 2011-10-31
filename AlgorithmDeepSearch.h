/*
 * AlgorithmDeepSearch.h
 *
 *  Created on: 31 oct. 2011
 *      Author: matthieu
 */

#ifndef ALGORITHMDEEPSEARCH_H_
#define ALGORITHMDEEPSEARCH_H_

#include "Algorithm.h"
#include "Graph.h"
#include <set>

class AlgorithmDeepSearch : protected Algorithm {
public:
	AlgorithmDeepSearch(Graph graph);
	virtual ~AlgorithmDeepSearch();
	void depthFirstSearch(Graph &tree, int vertex);
	std::set<int> getCover();
	std::set<int> getCover(int treeRoot);

private:
	std::set<int> m_markedVertices;

};

#endif /* ALGORITHMDEEPSEARCH_H_ */
