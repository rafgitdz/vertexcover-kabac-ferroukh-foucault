#ifndef PARAMETRIC_H_
#define PARAMETRIC_H_

#include "../generation/Graph.h"

class Parametric {
public:
	Parametric(const Graph&);

	bool tryGetCover(unsigned maxCoverSize, std::set<int> &cover);
	bool tryGetCoverBis(unsigned maxCoverSize, std::set<int> &cover);
private:
	Graph m_graph;
	bool tryGetCover(Graph g, unsigned maxCoverSize, std::set<int> &cover);
	bool tryGetCoverBis(Graph g, unsigned maxCoverSize, std::set<int> &cover);
};

#endif /* PARAMETRIC_H_ */
