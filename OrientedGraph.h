#ifndef ORIENTEDGRAPH_H_
#define ORIENTEDGRAPH_H_
#include "Graph.h"
#include <set>

class OrientedGraph : public Graph {
public:
	virtual void addEdge(int src,int dest);
	bool edgeIsFree(int,int);
	void fillEdge(int,int);
	void freeEdge(int,int);
	void reverseEdge(int, int);
	std::list<int> getSources(int vertex);
private:
	std::set< std::pair<int,int> > m_filledEdges;
};

#endif /* ORIENTEDGRAPH_H_ */
