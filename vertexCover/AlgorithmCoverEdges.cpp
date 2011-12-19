/*-----------------------------------------------------------------------------*
 *               *Project of Complexity and Applied Algorithmic*               *
 *-----------------------------------------------------------------------------*
 *        Authors :                                                            *
 *                  Milan Kabac (milan.kabac@etu.u-bordeaux1.fr)               *
 *             Matthieu Foucault (matthieu.foucault@etu.u-bordeaux1.fr)        *
 *                 Rafik Ferroukh (rafik.ferroukh@etu.u-bordeaux1.fr)          *
 *-----------------------------------------------------------------------------*
 *              University Bordeaux 1, Software Engineering, Master 2          *
 *                                *2011/2012*                                  *
 * ----------------------------------------------------------------------------*
 * Goal => gives the vertex cover of the graph given as enter                  *
 * Parameters : the graph to be handled                                        *
 * Description : get two first vertices, erase all their neighbours and        *
 * continue iteratively to do it until it hasn't vertices.                     *
 *____________________________________________________________________________*/

#include "AlgorithmCoverEdges.h"

using namespace std;

// Complexity => O(n * log(n))
std::set<int> AlgorithmCoverEdges::getCover() {

    // Init the data
    std::set<int> cover;
    int firstVertex = 0;
    int secondVertex = 0;

    // While the graph has a vertices, do!
    while (m_graph.getEdgeCount() > 0) {

        /* 
         * get the first vertex and the second 
         * (first neighbour of the first vertex)
         */
        firstVertex = m_graph.getBeginGraph()->first;

        // if the first vertex of the graph hasn't neighbours, delete it
        if (m_graph.getBeginGraph()->second.size() == 0) {
            m_graph.removeVertex(firstVertex);

        }// if it has neighbours, take the first and delete them
        else {
            secondVertex = *(m_graph.getBeginGraph()->second.begin());
            // insert them in the cover
            cover.insert(firstVertex);
            cover.insert(secondVertex);
            // erase them => erase all their edges between them et their neigh.
            m_graph.removeVertex(firstVertex);
            m_graph.removeVertex(secondVertex);
        }
    }
    return cover;
} // end of getCover
