#include "OrientedGraph.h"
#include "Graph.h"

using namespace std;

void OrientedGraph::addEdge(int src, int dest) {
	m_graph[src].insert(dest);
}

bool OrientedGraph::edgeIsFree(int src, int dest){
	pair<int,int> edge(src,dest);
	return (m_filledEdges.find(edge)==m_filledEdges.end());
}

void OrientedGraph::fillEdge(int src, int dest) {
	pair<int, int> edge(src,dest);
	m_filledEdges.insert(edge);
	removeEdge(src,dest);
	addEdge(dest,src);
}

void OrientedGraph::freeEdge(int src, int dest){
	pair <int,int> edge(dest,src);
	m_filledEdges.erase(edge);
	removeEdge(src,dest);
	addEdge(dest,src);
}

void OrientedGraph::reverseEdge(int src, int dest) {
	removeEdge(src,dest);
	addEdge(dest,src);
}
