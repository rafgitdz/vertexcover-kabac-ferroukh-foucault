#include "OrientedGraph.h"

OrientedGraph::OrientedGraph(vertexCover = 0) : Graph(vertexcover) {
}

OrientedGraph::~OrientedGraph() {

}

void OrientedGraph::addEdge(int src, int dest) {
	m_graph[src].insert(dest);
}
