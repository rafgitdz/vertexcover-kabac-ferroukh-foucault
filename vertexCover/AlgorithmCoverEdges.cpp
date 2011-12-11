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
 * Description : get two first vertices, erase all their neighbours and 
 * continue iteratively to do it until it hasn't vertices.
 */

#include "AlgorithmCoverEdges.h"

using namespace std;


/* Get the cover from the graph given as enter, get already the two first 
   vertices of the graph, erase their neighbours and their edge link, and insert
   them in the cover */
std::set<int> AlgorithmCoverEdges::getCover() {

    // Init the data
    std::set<int> cover;
    int firstVertex = 0;
    int secondVertex = 0;

    // While the graph has a vertices, do!
    while (m_graph.getVertexCount() > 0) {
        // get the first vertex and the second (first neighbour of the first)
        firstVertex = m_graph.getBeginGraph()->first;
        secondVertex = *(m_graph.getBeginGraph()->second.begin());
        // insert them in the cover
        cover.insert(firstVertex);
        cover.insert(secondVertex);
        // erase their neighbours and their edge link
        m_graph.removeVertexAndIsolatedNeighbour(firstVertex);
        m_graph.removeVertexAndIsolatedNeighbour(secondVertex);
    }
    return cover;
} // end of getCover

