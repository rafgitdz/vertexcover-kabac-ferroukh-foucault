#include "AlgorithmCoverEdges.h"

using namespace std;

AlgorithmCoverEdges::AlgorithmCoverEdges(Graph graph) : Algorithm(graph) {

    graphTemp = graph;
    for (int i = 0; i < graph.getVertexCount(); i++)
        verticesToCover.insert(i + 1);
}

std::set<int> AlgorithmCoverEdges::getCover() {

    std::set<int> cover;
    std::set<int> coverTemp;

    while (existsEdges()) {

        coverTemp = getSelectedEdge();

        for (std::set<int>::iterator ii = coverTemp.begin(); ii != coverTemp.end(); ii++) {

            cover.insert(*ii);
            verticesToCover.erase(*ii);
            eraseCoveredEdges(*ii);
        }
    }
    return cover;
}

std::set<int> AlgorithmCoverEdges::getSelectedEdge() {

    int firstSelectedVertex = 0;
    int secondSelectedVertex = 0;
    std::set<int> selectedEdge;

    firstSelectedVertex = rand() % verticesToCover.size();
    int jj = 0;

    for (std::set<int>::iterator ii = verticesToCover.begin(); ii != verticesToCover.end(); ++ii) {

        if (jj == firstSelectedVertex) {
            firstSelectedVertex = *ii;
            break;
        }
        jj++;
    }
    selectedEdge = graphTemp.getNeighbours(firstSelectedVertex);
    secondSelectedVertex = *(selectedEdge.begin()); // choice the first neighbour in the list

    selectedEdge.clear();
    selectedEdge.insert(firstSelectedVertex);
    selectedEdge.insert(secondSelectedVertex);

    return selectedEdge;
}

void AlgorithmCoverEdges::eraseCoveredEdges(int coveredVertex) {

    std::set<int> erasedVertex = graphTemp.getNeighbours(coveredVertex);

    for (std::set<int>::iterator ii = erasedVertex.begin(); ii != erasedVertex.end(); ii++) {

        verticesToCover.erase(*ii);
        graphTemp.removeEdge(*ii, coveredVertex);
    }
}

bool AlgorithmCoverEdges::existsEdges() {

    for (map<int, set<int> >::const_iterator ii = graphTemp.getBeginGraph(); ii != graphTemp.getEndGraph(); ++ii) {

        set<int> neigh = (*ii).second;
        for (set<int>::iterator jj = neigh.begin(); jj != neigh.end(); ++jj) return true;
    }
    return false;
}

AlgorithmCoverEdges::~AlgorithmCoverEdges() {
}
