#include "SimpleGraph.h"
#include <cstdlib>

using namespace std;

SimpleGraph::SimpleGraph(int vertexCount, float edgeProba):Graph(vertexCount) {

	// this is done in the parent constructor already
	//for(int i = 0; i < vertexCount; i++)
		//addVertex();

	srand((unsigned)time(0));
	probability = (int)(edgeProba*100);

	std::map<int, std::set<int> >::const_iterator it1;
	std::map<int, std::set<int> >::const_iterator it2;
	for(it1 = getBeginGraph(); it1 != getEndGraph(); it1++) {
		it2 = it1;
		it2++;
		for(; it2 != getEndGraph(); it2++) {
			if (rand() % 100 < probability)
			addEdge(it1->first, it2->first);
		}
	}

	/* because of creating random vertex indices i had to change this
	 * to the version above
	for(int i = 1; i < vertexCount; i++)
		for(int j = i+1; j <= vertexCount; j++)
			if (rand() % 100 < probability)
				addEdge(i,j);
	*/
}

SimpleGraph::~SimpleGraph() {}
