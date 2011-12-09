#include <iostream>
#include <cstring>
#include "generation/TreeDynamicSons.h"
#include "generation/TreeStaticSons.h"
#include "vertexCover/AlgorithmCoverEdges.h"
#include "vertexCover/SearchAlgorithm.h"
#include "vertexCover/AlgorithmDeepSearch.h"
#include "vertexCover/BipartiteOptimalCover.h"
#include "generation/BipartiteGraph.h"
#include "generation/SmallCoverGraph.h"
#include "vertexCover/Parametric.h"
#include "vertexCover/AlgorithmGlouton.h"
#include "vertexCover/AlgorithmGloutonSimple.h"
#include "draw/drawGraph.h"
#include "vertexCover/OptimalTreeAlgorithm.h"
#include "test.h"

using namespace std;

void usage() {
	cout << "usage: VertexCover inputFile -a algorithm" << endl;
	cout << "read the manual for more details" << endl;
}

int main(int argc, char* argv[]) {

	if (argc == 2
			&& (strcmp(argv[1], "-t") == 0 || strcmp(argv[1], "--test") == 0)) {
		if (testAll())
			cout << "Everything is working fine" << endl;

	} else if (argc >= 5 && (strcmp(argv[1], "-g") == 0)) {
		int graphType = atoi(argv[2]);
		Graph* graph;
		switch (graphType) {

		case 0: { //SimpleGraph
			int graphSize = atoi(argv[3]);
			float edgeProba = atof(argv[4]);
			graph = new SimpleGraph(graphSize, edgeProba);

			break;
		}
		case 1: { //SmallCoverGraph
			int graphSize = atoi(argv[3]);
			float edgeProba = atof(argv[4]);
			int coverSize = atoi(argv[5]);
			graph = new SmallCoverGraph(graphSize, edgeProba, coverSize);

			break;
		}
		case 2: { //BipartiteGraph
			int graphSize = atoi(argv[3]);
			float edgeProba = atof(argv[4]);
			float partRatio = atof(argv[5]);
			graph = new BipartiteGraph(graphSize, edgeProba, partRatio);

			break;
		}
		case 3: { //TreeDynamic

			break;
		}
		case 4: { //TreeStatic

			break;
		}
		default: {
			usage();
			return EXIT_FAILURE;
		}

		}

		cout << *graph << endl;
		delete (graph);
	}

	else {
		usage();
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
