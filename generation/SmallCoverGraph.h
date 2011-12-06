#ifndef SMALLCOVERGRAPH_H_
#define SMALLCOVERGRAPH_H_

#include <iostream>
#include "SimpleGraph.h"

class SmallCoverGraph : public SimpleGraph {
public:
	SmallCoverGraph(unsigned vertexCount, float edgeProba, unsigned coverSize);
	~SmallCoverGraph();
private:
	std::set<int> verticesInVC;
	std::set<int> verticesOutOfVC;
};

#endif /* SMALLCOVERGRAPH_H_ */
