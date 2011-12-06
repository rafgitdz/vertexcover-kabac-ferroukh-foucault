#include "AlgorithmGlouton.h"

using namespace std;

AlgorithmGlouton::AlgorithmGlouton(Graph graph) : Algorithm(graph) {

	m_graph = graph;
	/* removing isolated vertices from the graph */
}

AlgorithmGlouton::~AlgorithmGlouton() {
	// TODO Auto-generated destructor stub
}

void AlgorithmGlouton::removeIsolatedVertices() {
	std::map<int,std::set<int> >::const_iterator it;
	for(it = m_graph.getBeginGraph(); it != m_graph.getEndGraph();) {
		cout << "Vertex : " << it->first << endl;
		cout << "NeighSize : " << (it->second).size() << endl;

		if((it->second).empty()) {
			m_graph.removeVertex((it++)->first);
			cout << "Vertex Removed. Graph size : " << m_graph.getVertexCount() << endl;
		}else
			++it;
	}
}

int AlgorithmGlouton::addVertexToVC() {
	int vertexPosition(0);
	unsigned int maxDegree(0);

	std::map<int,std::set<int> >::const_iterator it;
	for(it = m_graph.getBeginGraph(); it != m_graph.getEndGraph(); it++){
		if (maxDegree < ((it->second).size())) {
			maxDegree = ((it->second).size());
			vertexPosition = it->first;
		}
	}
	vertexCover_.insert(vertexPosition);
	cout <<"Inserted the vertex " << vertexPosition << " into the VC set" << endl;
	return vertexPosition;
}

void AlgorithmGlouton::findMinimalVertexCover() {
	removeIsolatedVertices();
		cout << "Removed the isolated vertices" << endl;

		/* removing vertices from the graph choosing always the vertex with
		 * the highest degree;
		 * this vertex is written to the vertexCover set
		 * when removing a vertex the program removes the reference from the
		 * adjacent lists of the left vertices;
		 * the program stops when there are no more vertices in the graph
		 */

		while(m_graph.getVertexCount() > 0) {
			m_graph.removeVertexAndIsolatedNeighbour(addVertexToVC());
		}

		cout << "The found vertex cover has size : " << vertexCover_.size() << endl
					<< "Vertex cover : ";
		for(set<int>::iterator it = vertexCover_.begin(); it != vertexCover_.end(); it++)
			cout << *it << ", ";
		cout << endl << endl;
}
