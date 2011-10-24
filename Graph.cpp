#include "Graph.h"
#include <algorithm>


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
void Graph::removeVertex(int vertex) {
	set<int> neigh = m_graph[vertex];
	for(set<int>::iterator ii= neigh.begin(); ii != neigh.end(); ++ii) {
		m_graph[*ii].erase(vertex);
	}

	m_graph.erase(vertex);
}

bool Graph::hasEdge(int vertex1, int vertex2) {

	return m_graph[vertex1].find(vertex2) != m_graph[vertex1].end();

}

bool Graph::hasPath(int vertex1, int vertex2, int precedentVertex) {

	for (set<int>::iterator currentVertex = m_graph[vertex1].begin(); currentVertex != m_graph[vertex1].end(); ++currentVertex ) {

		if(*currentVertex!=precedentVertex) {

			if(!hasEdge(*currentVertex, vertex2))
					hasPath(*currentVertex,vertex2,vertex1); // recursive call
			else return true; // detect that this edge will create a cycle in the graph
		}

	}
	return false;

}

set<int> Graph::getNeighbours(int vertex) {
	return m_graph[vertex];
}

set<int> Graph::getVertices() {
    set<int> vertices;

    return vertices;
}

map<int,set<int> > Graph::getGraph() {
	return m_graph;
}

Graph::~Graph() {
}

std::ostream &operator<< (std::ostream &out, const Graph& g) {

	for (map<int, set<int> >::const_iterator ii = g.m_graph.begin(); ii != g.m_graph.end(); ++ii ) {
		int vertex = (*ii).first;
		out << vertex << " : ";
		set<int> neigh = (*ii).second;
		for (set<int>::iterator jj = neigh.begin(); jj != neigh.end(); ++jj) {
			out << (*jj) << " ";
		}
		out << endl;

	}

	return out;
}


