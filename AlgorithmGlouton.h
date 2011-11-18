#ifndef ALGORITHMGLOUTON_H_
#define ALGORITHMGLOUTON_H_

#include "Algorithm.h"

class AlgorithmGlouton : public Algorithm {
public:
	AlgorithmGlouton(Graph graph);
	virtual ~AlgorithmGlouton();
	void removeIsolatedVertices();
	virtual void findMinimalVertexCover();
	int addVertexToVC();

private:
	Graph graph_;
	std::set<int> vertexCover_;
};

#endif /* ALGORITHMGLOUTON_H_ */
