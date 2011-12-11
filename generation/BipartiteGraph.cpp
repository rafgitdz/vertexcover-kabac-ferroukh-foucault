#include "BipartiteGraph.h"
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

BipartiteGraph::BipartiteGraph(const BipartiteGraph &bGraph) :
		Graph(bGraph), m_leftPart(), m_rightPart() {
	m_leftPart = bGraph.getLeftPart();
	m_rightPart = bGraph.getRightPart();
}

BipartiteGraph::BipartiteGraph(int graphSize, float edgeProba, float partRatio) :
		Graph(), m_leftPart(), m_rightPart() {
	srand(time(NULL));
	int leftPartSize = graphSize * partRatio;
	int rightPartSize = graphSize - leftPartSize;
	for (int i = 0; i < leftPartSize; ++i) {
		m_leftPart.insert(addVertex());
	}
	for (int i = 0; i < rightPartSize; ++i) {

		int vertex = addVertex();
		m_rightPart.insert(vertex);
		for (set<int>::iterator jj = m_leftPart.begin(); jj != m_leftPart.end();
				++jj) {
			if (rand() % 100 < edgeProba * 100) {
				addEdge(vertex, *jj);
			}
		}
	}
}

