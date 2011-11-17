#include "OrientedGraph.h"
#include "Graph.h"



void OrientedGraph::addEdge(int src, int dest) {
	m_graph[src].insert(dest);
}
