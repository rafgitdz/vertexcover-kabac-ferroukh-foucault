#ifndef PARAMETRIC_H_
#define PARAMETRIC_H_

#include "../generation/Graph.h"

class Parametric {
public:
	Parametric();
	virtual ~Parametric();
	bool tryGetCover(Graph g, unsigned maxCoverSize, std::set<int> &cover);
};

#endif /* PARAMETRIC_H_ */
