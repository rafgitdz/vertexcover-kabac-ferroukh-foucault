#include "AlgorithmGlouton.h"

using namespace std;

AlgorithmGlouton::AlgorithmGlouton(Graph graph) :
		Algorithm(graph) {

	m_graph = graph;
	/* removing isolated vertices from the graph */
}

int AlgorithmGlouton::addVertexToVC() {
	int vertexPosition(0);
	unsigned int maxDegree(0);

	std::map<int, std::set<int> >::const_iterator it;
	for (it = m_graph.getBeginGraph(); it != m_graph.getEndGraph(); it++) {
		if (maxDegree < ((it->second).size())) {
			maxDegree = ((it->second).size());
			vertexPosition = it->first;
		}
	}
	vertexCover_.insert(vertexPosition);
	return vertexPosition;
}

set<int> AlgorithmGlouton::getCover() {
	m_graph.trim();

	/* removing vertices from the graph choosing always the vertex with
	 * the highest degree;
	 * this vertex is written to the vertexCover set
	 * when removing a vertex the program removes the reference from the
	 * adjacent lists of the left vertices;
	 * the program stops when there are no more vertices in the graph
	 */

	while (m_graph.getVertexCount() > 0) {
		m_graph.removeVertexAndIsolatedNeighbour(addVertexToVC());
	}

	return vertexCover_;
}

