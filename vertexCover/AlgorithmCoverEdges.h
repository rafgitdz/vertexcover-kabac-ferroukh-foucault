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
 * Goal => gives the vertex cover of the graph given as enter
 * Parameters => the graph to be handled
 * Include => It's an algorithm, it inherit class Algorithm
 */

#ifndef ALGORITHMCOVEREDGES_H_
#define ALGORITHMCOVEREDGES_H_

#include "Algorithm.h"

class AlgorithmCoverEdges : public Algorithm {
public:
    AlgorithmCoverEdges(Graph graph);
    virtual ~AlgorithmCoverEdges();

    std::set<int> getCover();

private:
    Graph graphTemp; // Copy of the original graph
};

#endif /* ALGORITHMCOVEREDGES_H_ */
