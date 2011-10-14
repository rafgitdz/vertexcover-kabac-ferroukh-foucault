#include "Graph.h"

using namespace std;

Graph::Graph() : m_graph(), m_vertexCount(0) {}

int Graph::addVertex() {
	m_vertexCount++;
	set<int> s;
	m_graph[m_vertexCount] = s;
	return m_vertexCount;
}

void Graph::addEdge(int vertex1, int vertex2) {
	m_graph[vertex1].insert(vertex2);
	m_graph[vertex2].insert(vertex1);
}

void Graph::removeEdge(int vertex1,int vertex2) {
	m_graph[vertex1].erase(vertex2);
	m_graph[vertex2].erase(vertex1);
}
void Graph::removeVertex(int); //TODO


set<int> Graph::getNeighbours(int vertex) {
	return m_graph[vertex];
}

Graph::~Graph() {
}
