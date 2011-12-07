#ifndef MINISAT_H
#define	MINISAT_H

#include <iostream>
#include <string>
#include <fstream>
#include"Graph.h"

class Minisat {
public:
    Minisat();
    virtual ~Minisat();

    std::string getSAT(Graph graph);
    void launchMinisat(char *inFile, char *outFile, Graph graph);
    std::list<int> getVertexCover(char* path);

private:
    void buildingSAT(std::string &SAT, int toConvert, std::string toInsert);
    std::string convertToString(int toConvert);
    std::string convertToString(char *toConvert);
};

#endif	/* MINISAT_H */

