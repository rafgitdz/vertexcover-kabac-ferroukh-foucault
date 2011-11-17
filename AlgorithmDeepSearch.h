#ifndef ALGORITHMDEEPSEARCH_H_
#define ALGORITHMDEEPSEARCH_H_

#include "Algorithm.h"
#include "SearchAlgorithm.h"
#include "Graph.h"
#include <set>

class AlgorithmDeepSearch : public Algorithm, SearchAlgorithm {
public:
	AlgorithmDeepSearch(Graph graph);
	virtual ~AlgorithmDeepSearch();

	std::set<int> getCover();
	std::set<int> getCover(int treeRoot);

private:

};

#endif /* ALGORITHMDEEPSEARCH_H_ */
