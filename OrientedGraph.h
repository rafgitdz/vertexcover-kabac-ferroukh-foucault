#ifndef ORIENTEDGRAPH_H_
#define ORIENTEDGRAPH_H_
#include "Graph.h"

class OrientedGraph : public Graph {
public:
	virtual void addEdge(int src,int dest);
};

#endif /* ORIENTEDGRAPH_H_ */
