
#ifndef GRAPH_H_
#define GRAPH_H_

#include <map>
#include <set>

class Graph {
public:
	Graph();
	virtual ~Graph();
	int addVertex();
	void addEdge(int, int);
	void removeVertex(int);
	void removeEdge(int,int);
	std::set<int> getNeighbours(int vertex);

protected:
	std::map<int,std::set<int> > m_graph;
	int m_vertexCount;
};

#endif /* GRAPH_H_ */
