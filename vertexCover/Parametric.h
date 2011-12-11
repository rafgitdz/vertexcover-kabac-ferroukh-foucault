#ifndef PARAMETRIC_H_
#define PARAMETRIC_H_

#include "../generation/Graph.h"
#include "Algorithm.h"

class Parametric : public Algorithm {
public:
	Parametric(const Graph& graph) : Algorithm(graph){};

	bool tryGetCover(unsigned maxCoverSize, std::set<int> &cover);
	bool tryGetCoverBis(unsigned maxCoverSize, std::set<int> &cover);
private:
	bool tryGetCover(Graph g, unsigned maxCoverSize, std::set<int> &cover);
	bool tryGetCoverBis(Graph g, unsigned maxCoverSize, std::set<int> &cover);
};

#endif /* PARAMETRIC_H_ */
