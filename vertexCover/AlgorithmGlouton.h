#ifndef ALGORITHMGLOUTON_H_
#define ALGORITHMGLOUTON_H_

#include "Algorithm.h"
#include <set>

class AlgorithmGlouton : public Algorithm {
public:
	AlgorithmGlouton(const Graph& graph) : Algorithm(graph) {};
	virtual std::set<int> getCover();
	int addVertexToVC();

protected:
	std::set<int> vertexCover_;
};

#endif /* ALGORITHMGLOUTON_H_ */
