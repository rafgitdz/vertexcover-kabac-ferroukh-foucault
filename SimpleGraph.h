#ifndef SIMPLEGRAPH_H_
#define SIMPLEGRAPH_H_

#include "Graph.h"

class SimpleGraph: public Graph {
public:
	SimpleGraph(int vertexCount, float edgeProba);
	virtual ~SimpleGraph();

protected:
	int probability;
};

#endif /* SIMPLEGRAPH_H_ */
