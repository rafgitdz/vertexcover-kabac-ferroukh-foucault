/* 
 * File:   Minisat.cpp
 * Author: Rafik
 * 
 * Created on 4 décembre 2011, 21:15
 */

#include "Minisat.h"
#include <string>
#include <sstream>

using namespace std;

Minisat::Minisat() {
}

std::string Minisat::getSAT(Graph graph) {

    string SAT;
    int vertex;

    set<int> markedVertices;
    SAT.operator =("c this is the SAT instance from the graph \n");
    SAT.operator +=("p cnf ");
    set<int> vertices = graph.getVertices();

    this->buildingSAT(SAT, vertices.size(), " ");
    this->buildingSAT(SAT, graph.getEdgeCount(), "\n");

    for (set<int>::iterator ii = vertices.begin(); ii != vertices.end(); ++ii) {

        vertex = *ii;
        markedVertices = graph.getNeighbours(vertex);

        for (set<int>::iterator jj = markedVertices.begin(); jj != markedVertices.end(); ++jj) {

            this->buildingSAT(SAT, *ii, " ");
            this->buildingSAT(SAT, *jj, " 0\n");
            graph.removeEdge(*ii, *jj);
        }
    }
    return SAT;
}

void Minisat::launchMinisat(char * inFile, char *outFile, Graph graph) {

    ofstream file("cnf.in", ios::out | ios::trunc);
    if (file) {
        cout << "Success to open file !" << endl;
    } else cerr << "Failed to open file!";

    file << this->getSAT(graph);
    file.close();

    string in = this->convertToString(inFile);
    string out = this->convertToString(outFile);
    string launchMinisat = "minisat " + in + " " + out;
    system(launchMinisat.c_str());
}

list<int> Minisat::getVertexCover(char* pathFile) {

    list<int> vertexCover;

    ifstream file(pathFile, ios::in);
    if (file) {
        cout << "Success to open file !" << endl;
    } else cerr << "Failed to open file!";

    string get;
    int getInt;

    while (!file.eof()) {

        file >> get;
        getInt = atof(get.c_str());
        if (getInt > 0) vertexCover.push_back(getInt);
    }

    file.close();
    return vertexCover;
}

void Minisat::buildingSAT(string &SAT, int toConvert, std::string toInsert) {

    std::ostringstream oss;
    oss << toConvert;
    string converted = oss.str();
    SAT.operator +=(converted);
    SAT.operator +=(toInsert);
}

string Minisat::convertToString(int toConvert) {
    std::ostringstream oss;
    oss << toConvert;
    return oss.str();
}

string Minisat::convertToString(char* toConvert) {
    std::ostringstream oss;
    oss << toConvert;
    return oss.str();
}

Minisat::~Minisat() {
}

