
#ifndef ALGORITHMCOVEREDGES_H_
#define ALGORITHMCOVEREDGES_H_

#include "Algorithm.h"

class AlgorithmCoverEdges  : public Algorithm {
public:
	AlgorithmCoverEdges(Graph graph);
	virtual ~AlgorithmCoverEdges();

	std::set<int> getCover();
};

#endif /* ALGORITHMCOVEREDGES_H_ */
