/*-----------------------------------------------------------------------------*
 *            *Project of Complexity and Applicated Algorithms*                *
 *-----------------------------------------------------------------------------*
 *        Authors :                                                            *
 *                  Milan Kabac (milan.kabac@etu.u-bordeaux1.fr)               *
 *             Matthieu Foucault (matthieu.foucault@etu.u-bordeaux1.fr)        *
 *                 Ferroukh Rafik (rafik.ferroukh@etu.u-bordeaux1.fr)          *
 *-----------------------------------------------------------------------------*
 *              University Bordeaux 1, Software Engineering, Master 2          *
 *                                *2011/2012*                                  *
 * ----------------------------------------------------------------------------*
 * Minisat.h                                                                   *
 * MINISAT is available at : http://minisat.se/                                *
 * Goal : get a cover from a graph given based on minisat tool algorithm       *
 * Parameters : none                                                           *
 * Include => class Graph, a Tree is a Graph, inherits all methods from Graph  *
 *____________________________________________________________________________*/

#ifndef MINISAT_H
#define	MINISAT_H

#include "../generation/Graph.h"

class Minisat {
public:

    Minisat() {
    }

    virtual ~Minisat() {
    }

    /*
     * get a cover from a graph given as enter base on MINISAT tool
     * generate the SAT instance in the "inFile"
     * generate the cover instance in the "outFile"
     */

    /*
     * build a complex SAT instance, based on matrix and the graph
     * <see the Minisat.cpp for more details> 
     * 
     * Complexity => O(n² * log(n) + COMPLEXITY(MINISAT))
     */
    std::set<int> getMinisatCoverFromSimpleSAT(Graph graph, char * inFile,
            char *outFile);
    /*
     * build a simple SAT instance, based the graph only, and the maximum size
     * of the cover that the MINISAT will give
     * if(UNSAT) ==> it returns a null set
     * <see the Minisat.cpp for more details> 
     * 
     * Complexity => O(n² * log(n) + COMPLEXITY(MINISAT))
     */
    std::set<int> getMinisatCoverFromComplexSAT(Graph graph, int maxSizeCover,
            char * inFile, char *outFile);

private:
    // build the SAT instance (file) step by step
    // Complexity => constant
    void buildingSAT(std::string &SAT, int toConvert, std::string toInsert);
    std::string convertToString(int toConvert);
    std::string convertToString(char *toConvert);
};

#endif	/* MINISAT_H */

