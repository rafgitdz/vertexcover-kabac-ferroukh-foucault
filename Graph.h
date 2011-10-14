
#ifndef GRAPH_H_
#define GRAPH_H_

#include <list>

class Graph {
public:
	Graph();
	virtual ~Graph();
	int addVertex();
	void addEdge(int, int);
	void removeVertex(int);
	void removeEdge(int,int);
	std::list<int> getNeighbours(int);

protected:
	std::list<std::list<int>> m_graph;
};

#endif /* GRAPH_H_ */
