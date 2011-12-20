#ifndef ALGORITHMDEEPSEARCH_H_
#define ALGORITHMDEEPSEARCH_H_

#include "Algorithm.h"
#include "SearchAlgorithm.h"
#include "../generation/Graph.h"
#include <set>

class AlgorithmDeepSearch : public Algorithm, SearchAlgorithm {
public:
	AlgorithmDeepSearch(const Graph &graph) : Algorithm(graph), SearchAlgorithm(){};
	virtual ~AlgorithmDeepSearch() {};

	/*
	 * returns a 2-approached cover, based on a deep search of the graph
	 * complexity: O(|E| * log(n))
	 */
	std::set<int> getCover();
	std::set<int> getCover(int treeRoot);

private:

};

#endif /* ALGORITHMDEEPSEARCH_H_ */
