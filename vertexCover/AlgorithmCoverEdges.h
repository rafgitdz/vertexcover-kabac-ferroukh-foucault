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
 * Include => It's an algorithm, it inherit class Algorithm                    *
 *____________________________________________________________________________*/

#ifndef ALGORITHMCOVEREDGES_H_
#define ALGORITHMCOVEREDGES_H_

#include "Algorithm.h"

class AlgorithmCoverEdges : public Algorithm {
public:
    // Constructor that copy the content of the graph in a temporary graph

    AlgorithmCoverEdges(const Graph &graph) : Algorithm(graph) {
    }

    virtual ~AlgorithmCoverEdges() {
    }

    /* Get the cover from the graph given as enter, get already the two first
     * vertices of the graph, erase their neighbors and their edge link, and insert
     * them in the cover
     */
    std::set<int> getCover();

};

#endif /* ALGORITHMCOVEREDGES_H_ */
