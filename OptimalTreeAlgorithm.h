#ifndef OPTIMALTREEALGORITHM_H_
#define OPTIMALTREEALGORITHM_H_

#include "Algorithm.h"
#include "Tree.h"
#include "SearchAlgorithm.h"

class OptimalTreeAlgorithm : public Algorithm {
public:
	OptimalTreeAlgorithm(Tree tree);
	virtual ~OptimalTreeAlgorithm();
	std::set<int> getVertexCover();
	bool setContains(int vertex, std::set<int> set);
	int getParent(int vertex);

private:
	std::list<int> _graphWithoutLeaves;
	SearchAlgorithm* _algorithm;

};

#endif /* OPTIMALTREEALGORITHM_H_ */
