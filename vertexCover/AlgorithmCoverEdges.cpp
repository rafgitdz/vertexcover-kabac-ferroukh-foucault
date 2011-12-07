/*    *Project of Complexity and Applicated Algorithms*
 * 
 * Authors : 
 *      Milan Kabac (milan.kabac@etu.u-bordeaux1.fr)
 *      Matthieu Foucault (matthieu.foucault@etu.u-bordeaux1.fr)
 *      Ferroukh Rafik (rafik.ferroukh@etu.u-bordeaux1.fr)
 * 
 *   University Bordeaux 1, Software Engineering, Master 2
 *                      *2011/2012*
 * --------------------------------------------------------------
 * Goal : gives the vertex cover of the graph given as enter
 * Parameters : the graph to be handled
 * Description : get two first vertices, erase all the neighbours of them
 * and continue iteratively to do it until it hasn't vertices.
 */

#include "AlgorithmCoverEdges.h"

using namespace std;

AlgorithmCoverEdges::AlgorithmCoverEdges(Graph graph) : Algorithm(graph) {

    graphTemp = graph;
    for (int i = 0; i < graph.getVertexCount(); i++)
        verticesToCover.insert(i + 1);
}

std::set<int> AlgorithmCoverEdges::getCover() {

    std::set<int> cover;
    int firstVertex = 0;
    int secondVertex = 0;

    while (graphTemp.getVertexCount() > 0) {

        firstVertex = graphTemp.getBeginGraph()->first;
        secondVertex = *(graphTemp.getBeginGraph()->second.begin());
        cover.insert(firstVertex);
        cover.insert(secondVertex);
        graphTemp.removeVertexAndIsolatedNeighbour(firstVertex);
        graphTemp.removeVertexAndIsolatedNeighbour(secondVertex);
    }
    return cover;
}

AlgorithmCoverEdges::~AlgorithmCoverEdges() {
}
