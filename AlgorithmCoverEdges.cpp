
#include "AlgorithmCoverEdges.h"

AlgorithmCoverEdges::AlgorithmCoverEdges(Graph graph) : Algorithm(graph) {

}

std::set<int> AlgorithmCoverEdges::getCover() {

	std::set<int> cover;
	std::set<int> coverTemp;

	int selectedVertex =

	while(selectedVertex = rand()%graph.m_vertexCount) {
		coverTemp = graph.getNeighbours(selectedVertex);
		if(coverTemp!=null) break;
	}

	return cover;
}

AlgorithmCoverEdges::~AlgorithmCoverEdges() {
	delete graph;
}
