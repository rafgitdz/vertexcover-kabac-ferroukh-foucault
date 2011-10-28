#include "SimpleGraph.h"
#include <cstdlib>

using namespace std;

SimpleGraph::SimpleGraph(int vertexCount, float edgeProba):Graph() {
	for(int i = 0; i < vertexCount; i++)
		addVertex();

	srand((unsigned)time(0));
	probability = (int)(edgeProba*100);

	for(int i = 1; i < vertexCount; i++)
		for(int j = i+1; j <= vertexCount; j++)
			if (rand() % 100 < probability)
				addEdge(i,j);
}

SimpleGraph::~SimpleGraph() {}
