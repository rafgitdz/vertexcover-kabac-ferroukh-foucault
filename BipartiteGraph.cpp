#include "BipartiteGraph.h"
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

BipartiteGraph::BipartiteGraph(int graphSize, float edgeProba, float partRatio) :
		Graph() {
	assert(edgeProba >= 0);
	assert(edgeProba <= 1);
	assert(partRatio >= 0);
	assert(partRatio <= 1);

	srand(time(NULL));

	int vertices[graphSize];
	for (int i = 0; i < graphSize; ++i) {
		vertices[i] = addVertex();
	}
	for (int i = 0; i < graphSize * partRatio; ++i) {
		for (int j = graphSize - 1; j >= graphSize * partRatio; --j) {
			if (rand() % 100 < edgeProba * 100)
				addEdge(vertices[i], vertices[j]);
		}
	}
}

