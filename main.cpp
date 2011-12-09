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
#include "vertexCover/Minisat.h"
#include "test.h"

using namespace std;

void usage() {
    cout << "usage: VertexCover inputFile -a algorithm" << endl;
    cout << "read the manual for more details" << endl;
}

void testComplexMinisat() {

    Minisat ms;
    //    TreeDynamicSons t(40);
    //    BipartiteGraph t(80, 0.2, 0.6);
    //    SimpleGraph t(100, 0.2);
    SmallCoverGraph t(20, 0.5, 10);
    cout << "Edge count : " << t.getEdgeCount() << endl;
    set<int> vertexCoverComplex;

    vertexCoverComplex = ms.getMinisatCoverFromComplexSAT(t, 10, "instance/satComplex/satComplex.in", "instance/satComplex/vertexCoverFromSatComplex.out");

    cout << "The complex minisat cover is :";
    for (set<int>::iterator ii = vertexCoverComplex.begin(); ii != vertexCoverComplex.end(); ++ii) {
        cout << *ii << " , ";
    }
    cout << endl;

    set<int> vertexCoverSimple = ms.getMinisatCoverFromSimpleSAT(t, "instance/satSimple/satSimple.in", "instance/satSimple/vertexCoverFromSatSimple.out");
    cout << "The simple minisat cover is :";
    for (set<int>::iterator ii = vertexCoverSimple.begin(); ii != vertexCoverSimple.end(); ++ii) {
        cout << *ii << " , ";
    }
    cout << endl;

    DrawGraph dg;
    dg.drawGraph(t, vertexCoverSimple, "instance/pictureGraph/graphSimple.png");
    dg.drawGraph(t, vertexCoverComplex, "instance/pictureGraph/graphComplex.png");
}

int main(int argc, char* argv[]) {

    if (argc == 1) {
        testComplexMinisat();
    } else
        if (argc == 2
            && (strcmp(argv[1], "-t") == 0 || strcmp(argv[1], "--test") == 0)) {
        if (testAll())
            cout << "Everything is working fine" << endl;

    } else if (argc >= 4 && (strcmp(argv[1], "-g") == 0)) {
        int graphType = atoi(argv[2]);
        int graphSize = atoi(argv[3]);
        Graph* graph;
        switch (graphType) {

            case 0:
            { //SimpleGraph
                float edgeProba = atof(argv[4]);
                graph = new SimpleGraph(graphSize, edgeProba);

                break;
            }
            case 1:
            { //SmallCoverGraph
                float edgeProba = atof(argv[4]);
                int coverSize = atoi(argv[5]);
                graph = new SmallCoverGraph(graphSize, edgeProba, coverSize);

                break;
            }
            case 2:
            { //BipartiteGraph
                float edgeProba = atof(argv[4]);
                float partRatio = atof(argv[5]);
                graph = new BipartiteGraph(graphSize, edgeProba, partRatio);

                break;
            }
            case 3:
            { //TreeDynamic

                graph = new TreeDynamicSons(graphSize);
                break;

            }
            case 4:
            { //TreeStatic

                int sonsCount = atoi(argv[4]);
                graph = new TreeStaticSons(graphSize, sonsCount);
                break;
            }
            default:
            {
                usage();
                return EXIT_FAILURE;
            }

        }

        cout << *graph << endl;
        delete (graph);

    } else {
        usage();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
