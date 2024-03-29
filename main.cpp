#include <iostream>
#include <cstring>
#include <sys/time.h>
#include <cstdlib>

#include <sstream>
#include <fstream>

#include "generation/BipartiteGraph.h"
#include "generation/SimpleGraph.h"
#include "generation/SmallCoverGraph.h"
#include "generation/Graph.h"
#include "generation/TreeDynamicSons.h"
#include "generation/SmallCoverBipartiteGraph.h"

#include "vertexCover/AlgorithmCoverEdges.h"
#include "vertexCover/SearchAlgorithm.h"
#include "vertexCover/AlgorithmDeepSearch.h"
#include "vertexCover/AlgorithmBipartiteOptimal.h"
#include "vertexCover/Parametric.h"
#include "vertexCover/AlgorithmGlouton.h"
#include "vertexCover/AlgorithmGloutonSimple.h"
#include "vertexCover/OptimalTreeAlgorithm.h"
#include "vertexCover/Minisat.h"
#include "draw/drawGraph.h"
#include "test.h"

using namespace std;

long diff_ms(timeval t1, timeval t2) {
	return (((t1.tv_sec - t2.tv_sec) * 1000000) + (t1.tv_usec - t2.tv_usec))
			/ 1000;
}

void usage() {
	cout
			<< "usage: VertexCover { -in inputFile | [ -g graphType <args>]} [-a algorithm <args>] [options ...]"
			<< endl;
	cout << "read the manual for more details" << endl;
}

void generateDot(Graph g, set<int> cover) {
	DrawGraph dg;
	dg.drawGraph(g, cover, "graph.png");
}

int main(int argc, char* argv[]) {

	set<int> cover;
	bool saveGraph;
	char* savePath;
	bool visualizeGraph = false;
	bool graphGenerated = false;
	Graph* graph = NULL;
	Tree* tree = NULL;
	BipartiteGraph* bGraph = NULL;

	if (argc == 2
			&& (strcmp(argv[1], "-t") == 0 || strcmp(argv[1], "--test") == 0)) {
		if (testAll()) {
			cout << "Everything is working fine" << endl;
			return EXIT_SUCCESS;
		} else
			return EXIT_FAILURE;
	}
	for (int i = 1; i < argc; ++i) {
		if (strcmp(argv[i], "-dot") == 0)
			visualizeGraph = true;
		else if (strcmp(argv[i], "-out") == 0) {
			saveGraph = true;
			savePath = argv[i + 1];
		}
	}

	for (int i = 1; i < argc; ++i)
		if (strcmp(argv[i], "-in") == 0) {
			char* loadPath = argv[i + 1];
			graph = new Graph(loadPath);
			graphGenerated = true;
		} else if (strcmp(argv[i], "-g") == 0
				|| strcmp(argv[i], "--generate-graph") == 0) {

			if (argc < i + 3 || graphGenerated) {
				usage();
				return EXIT_FAILURE;
			}

			timeval t1, t2;
			unsigned long time;
			gettimeofday(&t1, NULL);

			int graphType = atoi(argv[i + 1]);
			int graphSize = atoi(argv[i + 2]);
			switch (graphType) {

			case 0: { //SimpleGraph
				float edgeProba = atof(argv[i + 3]) / 100;
				graph = new SimpleGraph(graphSize, edgeProba);

				break;
			}
			case 1: { //SmallCoverGraph
				float edgeProba = atof(argv[i + 3]) / 100;
				int coverSize = atoi(argv[i + 4]);
				graph = new SmallCoverGraph(graphSize, edgeProba, coverSize);

				break;
			}
			case 2: { //BipartiteGraph
				float edgeProba = atof(argv[i + 3]) / 100;
				float partRatio = atof(argv[i + 4]) / 100;
				bGraph = new BipartiteGraph(graphSize, edgeProba, partRatio);

				break;
			}
			case 3: { //Tree
				if (argc < i + 5) {
					usage();
					return EXIT_FAILURE;
				}

				int minSons = atoi(argv[i + 3]);
				int maxSons = atoi(argv[i + 4]);
				tree = new TreeDynamicSons(graphSize, minSons, maxSons);
				break;

			}
			case 4: { //Bipartite with a small cover
				if (argc < i + 7) {
					usage();
					return EXIT_FAILURE;
				}
				float edgeProba = atof(argv[i + 3]) / 100;
				float partRatio = atof(argv[i + 4]) / 100;
				int coverSize = atoi(argv[i + 5]);
				float coverRatio = atof(argv[i + 6]) / 100;
				bGraph = new SmallCoverBipartiteGraph(graphSize,
						edgeProba, partRatio, coverSize, coverRatio);
				break;
			}
			default: {
				usage();
				return EXIT_FAILURE;
			}

			}

			gettimeofday(&t2, NULL);
			graphGenerated = true;
			cout << "graph generated in " << diff_ms(t2, t1) << " milliseconds"
					<< endl;

		} // endif --generate-graph
		else if (strcmp(argv[i], "-a") == 0
				|| strcmp(argv[i], "--algorithm") == 0) {

			if (argc < i + 1 || !graphGenerated) {
				usage();
				return EXIT_FAILURE;
			}

			timeval t3, t4;

			gettimeofday(&t3, NULL);
			int algoType = atoi(argv[i + 1]);
			switch (algoType) {
			case 0: { //Greedy
				if (graph != NULL) {
					AlgorithmGlouton algo(*graph);
					cover = algo.getCover();
				} else if (bGraph != NULL) {
					AlgorithmGlouton algo(*bGraph);
					cover = algo.getCover();
				} else if (tree != NULL) {
					AlgorithmGlouton algo(*tree);
					cover = algo.getCover();
				} else {
					usage();
					return EXIT_FAILURE;
				}

				break;
			}
			case 1: { //GreedySimple
				if (graph != NULL) {
					AlgorithmGloutonSimple algo(*graph);
					cover = algo.getCover();
				} else if (bGraph != NULL) {
					AlgorithmGloutonSimple algo(*bGraph);
					cover = algo.getCover();
				} else if (tree != NULL) {
					AlgorithmGloutonSimple algo(*tree);
					cover = algo.getCover();
				} else {
					usage();
					return EXIT_FAILURE;
				}
				break;
			}
			case 2: { //CoverEdges
				if (graph != NULL) {
					AlgorithmCoverEdges algo(*graph);
					cover = algo.getCover();
				} else if (bGraph != NULL) {
					AlgorithmCoverEdges algo(*bGraph);
					cover = algo.getCover();
				} else if (tree != NULL) {
					AlgorithmCoverEdges algo(*tree);
					cover = algo.getCover();
				} else {
					usage();
					return EXIT_FAILURE;
				}
				break;
			}
			case 3: { //DeepSearch
				if (graph != NULL) {
					AlgorithmDeepSearch algo(*graph);
					cover = algo.getCover();
				} else if (bGraph != NULL) {
					AlgorithmDeepSearch algo(*bGraph);
					cover = algo.getCover();
				} else if (tree != NULL) {
					AlgorithmDeepSearch algo(*tree);
					cover = algo.getCover();
				} else {
					usage();
					return EXIT_FAILURE;
				}

				break;
			}
			case 4: { //BipartiteOptimal
				if (bGraph != NULL) {
					AlgorithmBipartiteOptimal algo(*bGraph);
					cover = algo.getCover();
				} else {
					usage();
					return EXIT_FAILURE;
				}
				break;
			}
			case 5: { //TreeOptimal
				if (tree != NULL) {
					OptimalTreeAlgorithm algo(*tree);
					cover = algo.getVertexCover();
				} else {
					usage();
					return EXIT_FAILURE;
				}
				break;
			}
			case 6: { //Parametric
				if (argc < i + 3) {
					usage();
					return EXIT_FAILURE;
				}
				unsigned maxCoverSize = atoi(argv[i + 2]);
				bool coverFound;

				if (graph != NULL) {
					Parametric algo(*graph);
					coverFound = algo.tryGetCover(maxCoverSize, cover);
				} else if (bGraph != NULL) {
					Parametric algo(*bGraph);
					coverFound = algo.tryGetCover(maxCoverSize, cover);
				} else if (tree != NULL) {
					Parametric algo(*tree);
					coverFound = algo.tryGetCover(maxCoverSize, cover);
				} else {
					usage();
					return EXIT_FAILURE;
				}

				if (!coverFound)
					cout << "The parametric algorithm failed to find a cover"
							<< endl;

				break;
			}
			case 7: { //ParametricBis

				if (argc < i + 3) {
					usage();
					return EXIT_FAILURE;
				}
				unsigned maxCoverSize = atoi(argv[i + 2]);
				bool coverFound;

				if (graph != NULL) {
					Parametric algo(*graph);
					coverFound = algo.tryGetCoverBis(maxCoverSize, cover);
				} else if (bGraph != NULL) {
					Parametric algo(*bGraph);
					coverFound = algo.tryGetCoverBis(maxCoverSize, cover);
				} else if (tree != NULL) {
					Parametric algo(*tree);
					coverFound = algo.tryGetCoverBis(maxCoverSize, cover);
				} else {
					usage();
					return EXIT_FAILURE;
				}

				if (!coverFound)
					cout << "The parametric algorithm failed to find a cover"
							<< endl;

				break;
			}
			case 8: { // Minisat simple
				Minisat algo;

				if (graph != NULL) {
					cover = algo.getMinisatCoverFromSimpleSAT(*graph,
							"minisat.in", "minisat.out");
				} else if (bGraph != NULL) {
					cover = algo.getMinisatCoverFromSimpleSAT(*bGraph,
							"minisat.in", "minisat.out");
				} else if (tree != NULL) {
					cover = algo.getMinisatCoverFromSimpleSAT(*tree,
							"minisat.in", "minisat.out");
				} else {
					usage();
					return EXIT_FAILURE;
				}
				break;
			}
			case 9: { // MINISAT complex
				if (argc < i + 3) {
					usage();
					return EXIT_FAILURE;
				}
				Minisat algo;
				unsigned maxCoverSize = atoi(argv[i + 2]);

				if (graph != NULL) {
					cover = algo.getMinisatCoverFromComplexSAT(*graph,
							maxCoverSize, "minisat.in", "minisat.out");
				} else if (bGraph != NULL) {
					cover = algo.getMinisatCoverFromComplexSAT(*bGraph,
							maxCoverSize, "minisat.in", "minisat.out");
				} else if (tree != NULL) {
					cover = algo.getMinisatCoverFromComplexSAT(*tree,
							maxCoverSize, "minisat.in", "minisat.out");
				} else {
					usage();
					return EXIT_FAILURE;
				}

				if (cover.size() == 0)
					cout << "Minisat failed to find a cover" << endl;

				break;
			}
			default: {
				usage();
				return EXIT_FAILURE;
			}
			} // end algorithm switch

			gettimeofday(&t4, NULL);
			if (cover.size() == 0)
				cout << "cover not found" << endl;
			else {
				cout << "cover found in " << diff_ms(t4, t3) << " milliseconds"
						<< endl;
				cout << "cover size : " << cover.size() << endl;
			}
		}
	if (visualizeGraph)
		if (graph != NULL)
			generateDot(*graph, cover);
		else if (bGraph != NULL)
			generateDot(*bGraph, cover);
		else if (tree != NULL)
			generateDot(*tree, cover);
		else {
			usage();
			return EXIT_FAILURE;
		}
	if (saveGraph) {
		if (graph != NULL)
			graph->saveGraph(savePath);
		else if (bGraph != NULL)
			bGraph->saveGraph(savePath);
		else if (tree != NULL)
			tree->saveGraph(savePath);
		else {
			usage();
			return EXIT_FAILURE;
		}
	}

	delete (graph);
	delete (tree);
	delete (bGraph);
	return EXIT_SUCCESS;
}

