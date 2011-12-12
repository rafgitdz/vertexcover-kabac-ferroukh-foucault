#include "SmallCoverGraph.h"
#include <cstdlib>

using namespace std;

SmallCoverGraph::SmallCoverGraph(unsigned vertexCount, float edgeProba, unsigned coverSize): SimpleGraph(coverSize, edgeProba) {

	verticesInVC = getVertices();
	for(unsigned i = 0; i < (vertexCount - coverSize); i++)
		verticesOutOfVC.insert(addVertex());

	set<int>::iterator it1;
	set<int>::iterator it2;
	for(it1 = verticesOutOfVC.begin(); it1 != verticesOutOfVC.end(); it1++)
		for(it2 = verticesInVC.begin(); it2 != verticesInVC.end(); it2++) {
			if (rand() % 100 < probability)
				addEdge(*it1,*it2);
		}
}
