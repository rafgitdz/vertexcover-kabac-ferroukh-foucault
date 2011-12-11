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
	std::set<int> getCover();
	std::set<int> getCover(int treeRoot);

private:

};

#endif /* ALGORITHMDEEPSEARCH_H_ */
