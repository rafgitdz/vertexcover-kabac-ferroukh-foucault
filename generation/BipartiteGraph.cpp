#include "BipartiteGraph.h"
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

BipartiteGraph::BipartiteGraph() : Graph(), m_leftPart(), m_rightPart() {
	for (int i = 1; i < 8 ; ++i) {
		addVertex(i);
		addVertex(i+10);
		m_leftPart.insert(i);
		m_rightPart.insert(i+10);
	}
	addEdge(1,12);
	addEdge(1,16);
	addEdge(2,12);
	addEdge(2,14);
	addEdge(3,11);
	addEdge(3,13);
	addEdge(3,15);
	addEdge(4,11);
	addEdge(4,13);
	addEdge(4,15);
	addEdge(5,12);
	addEdge(5,14);
	addEdge(5,16);
	addEdge(6,12);
	addEdge(6,13);
	addEdge(6,14);
	addEdge(6,15);
	addEdge(6,16);
	addEdge(6,17);
	addEdge(7,16);


}

BipartiteGraph::BipartiteGraph(int graphSize, float edgeProba, float partRatio) :
		Graph(), m_leftPart(), m_rightPart() {
	srand(time(NULL));

	int leftPartSize = graphSize * partRatio;
	int rightPartSize = graphSize - leftPartSize;

	for (int i = 0; i<leftPartSize; ++i) {
		m_leftPart.insert(addVertex());
	}

	for (int i = 0; i < rightPartSize; ++i) {
		int vertex = addVertex();
		m_rightPart.insert(vertex);
		for (set<int>::iterator jj = m_leftPart.begin() ;  jj != m_leftPart.end() ; ++jj) {
			if (rand() % 100 < edgeProba * 100) {
				addEdge(vertex, *jj);
			}
		}

	}
}


