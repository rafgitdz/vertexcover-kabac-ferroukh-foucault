#include <iostream>
#include <cstring>
#include <sys/time.h>
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
#include "vertexCover/Minisat.h"
#include "test.h"

using namespace std;

long diff_ms(timeval t1, timeval t2) {
	return (((t1.tv_sec - t2.tv_sec) * 1000000) + (t1.tv_usec - t2.tv_usec))
			/ 1000;
}

void usage() {
	cout
			<< "usage: VertexCover { inputFile | [ -g graphType <args>]} [-a algorithm <args>]"
			<< endl;
	cout << "read the manual for more details" << endl;
}

void generateDot(Graph g) {
	DrawGraph dg;
	set<int> vc;
	dg.drawGraph(g,vc, "graph.png");
}

int main(int argc, char* argv[]) {

	bool visualizeGraph = false;
	bool graphGenerated = false;

	if (argc == 2
			&& (strcmp(argv[1], "-t") == 0 || strcmp(argv[1], "--test") == 0)) {
		if (testAll())
			cout << "Everything is working fine" << endl;

	} else {
		for (int i = 1; i < argc; ++i)
			if (strcmp(argv[i], "-dot") == 0) {
				visualizeGraph = true;
				break;
			}

		for (int i = 1; i < argc; ++i)

			if (strcmp(argv[i], "-g") == 0
					|| strcmp(argv[i], "--generate-graph") == 0) {

				if (argc < i + 3) {
					usage();
					return EXIT_FAILURE;
				}

				timeval t1, t2;
				unsigned long time;
				gettimeofday(&t1, NULL);

				int graphType = atoi(argv[i + 1]);
				int graphSize = atoi(argv[i + 2]);
				Graph* graph;
				switch (graphType) {

				case 0: { //SimpleGraph
					float edgeProba = atof(argv[i + 3]);
					graph = new SimpleGraph(graphSize, edgeProba);

					break;
				}
				case 1: { //SmallCoverGraph
					float edgeProba = atof(argv[i + 3]);
					int coverSize = atoi(argv[i + 4]);
					graph = new SmallCoverGraph(graphSize, edgeProba,
							coverSize);

					break;
				}
				case 2: { //BipartiteGraph
					float edgeProba = atof(argv[i + 3]);
					float partRatio = atof(argv[i + 4]);
					graph = new BipartiteGraph(graphSize, edgeProba, partRatio);

					break;
				}
				case 3: { //TreeDynamic

					graph = new TreeDynamicSons(graphSize);
					break;

				}
				case 4: { //TreeStatic

					int sonsCount = atoi(argv[i + 4]);
					graph = new TreeStaticSons(graphSize, sonsCount);
					break;
				}
				default: {
					usage();
					return EXIT_FAILURE;
				}

				}

				gettimeofday(&t2, NULL);
				cout << "graph generated in " << diff_ms(t2, t1)
						<< " miliseconds" << endl;
				if (visualizeGraph)
					generateDot(*graph);
				//cout << *graph << endl;
				delete (graph);

			} // endif --generate-graph
			else if (strcmp(argv[i], "-a") == 0
					|| strcmp(argv[i], "--algorithm") == 0) {

				if (argc < i + 3) {
					usage();
					return EXIT_FAILURE;
				}

			}
	}

	return EXIT_SUCCESS;
}
