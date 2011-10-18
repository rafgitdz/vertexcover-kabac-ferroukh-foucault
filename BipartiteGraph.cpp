#include "BipartiteGraph.h"
#include <cstdlib>
#include <ctime>


using namespace std;

BipartiteGraph::BipartiteGraph(int vertexNumber, float edgeProba) :Graph() {
	srand(time(NULL));

	int vertices[vertexNumber];
	for(int i = 0; i < vertexNumber; ++i) {
		vertices[i] = addVertex();
	}
	for (int i = 0; i < vertexNumber; i+=2) {
		for(int j = 1; j < vertexNumber; j+=2) {
			if (rand() % 100 < edgeProba*100)
				addEdge(i,j);
		}
	}
}

