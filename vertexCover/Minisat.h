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
 * Minisat is available at : http://minisat.se/                                *
 * Goal :                                                                      *
 * Parameters :                                                                *
 * ...                                                                         *
 * Include => class Graph, a Tree is a Graph, inherits all methods from Graph  *
 *____________________________________________________________________________*/

#ifndef MINISAT_H
#define	MINISAT_H

#include <iostream>
#include <string>
#include <fstream>
#include "../generation/Graph.h"

class Minisat {
public:
    Minisat();
    virtual ~Minisat();

    std::set<int> getMinisatCoverFromSimpleSAT(Graph graph, char * inFile, char *outFile);
    std::set<int> getMinisatCoverFromComplexSAT(Graph graph, int maxSizeCover, char * inFile, char *outFile);

private:
    void buildingSAT(std::string &SAT, int toConvert, std::string toInsert);
    std::string convertToString(int toConvert);
    std::string convertToString(char *toConvert);
};

#endif	/* MINISAT_H */

