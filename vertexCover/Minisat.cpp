/*-----------------------------------------------------------------------------*
 *               *Project of Complexity and Applicated Algorithms*             *
 *-----------------------------------------------------------------------------*
 *        Authors :                                                            *
 *                  Milan Kabac (milan.kabac@etu.u-bordeaux1.fr)               *
 *             Matthieu Foucault (matthieu.foucault@etu.u-bordeaux1.fr)        *
 *                 Ferroukh Rafik (rafik.ferroukh@etu.u-bordeaux1.fr)          *
 *-----------------------------------------------------------------------------*
 *              University Bordeaux 1, Software Engineering, Master 2          *
 *                                *2011/2012*                                  *
 * ----------------------------------------------------------------------------*
 * Minisat.cpp                                                                 *
 * Goal :                                                                      *
 * Parameters : none                                                           *
 *____________________________________________________________________________*/

#include "Minisat.h"
#include <string>
#include <sstream>

using namespace std;

Minisat::Minisat() {
}

set<int> Minisat::getMinisatCoverFromComplexSAT(Graph graph, int maxSizeCover,
        char * inFile, char *outFile) {

    map<int, int> indexVerticesMatrix;
    set<int> vertices = graph.getVertices();
    int vertexCount = graph.getVertexCount();
    string SAT;

    // Open the file inFile
    ofstream file(inFile, ios::out | ios::trunc);

    // Init of the SAT instance in the file
    SAT.operator =("c this is the SAT instance from the graph \n");
    SAT.operator +=("p cnf ");

    unsigned int numberOfClauses = ((maxSizeCover * vertexCount *
            (vertexCount - 1)) / 2) + (((maxSizeCover * (maxSizeCover - 1)) *
            vertexCount) / 2) + (2 * maxSizeCover * graph.getEdgeCount());

    this->buildingSAT(SAT, numberOfClauses, " ");
    this->buildingSAT(SAT, graph.getEdgeCount(), "\n");

    int jj = 1;

    // build the SAT instance and the matrix
    for (set<int>::iterator ii = vertices.begin(); ii != vertices.end(); ++ii) {
        indexVerticesMatrix[*ii] = jj;
        ++jj;
    }

    int k;
    for (int i = 0; i < maxSizeCover; ++i) {
        k = 0;
        for (int j = k; j + 1 < vertexCount; ++j) {

            this->buildingSAT(SAT, -((i * vertexCount + k) + 1), " ");
            this->buildingSAT(SAT, -((i * vertexCount + j + 1) + 1), " 0\n");
            if (j + 2 == vertexCount) {
                ++k;
                if (k + 1 == vertexCount)
                    break;
                j = k - 1;
            }
        }
    }

    for (int j = 0; j < vertexCount; ++j) {
        k = 0;
        for (int i = k; i + 1 < maxSizeCover; ++i) {

            this->buildingSAT(SAT, -((k * vertexCount + j) + 1), " ");
            this->buildingSAT(SAT, -(((i + 1) * vertexCount + j) + 1), " 0\n");
            if (i + 2 == maxSizeCover) {
                ++k;
                if (k + 1 == maxSizeCover)
                    break;
                i = k - 1;
            }
        }
    }

    int vertex, firstVertex, secondVertex;
    set<int> markedVertices;
    Graph temporaryGraph = graph;

    for (set<int>::iterator ii = vertices.begin(); ii != vertices.end(); ++ii) {

        vertex = *ii;
        firstVertex = indexVerticesMatrix[*ii];
        markedVertices = temporaryGraph.getNeighbours(vertex);

        for (set<int>::iterator jj = markedVertices.begin();
                jj != markedVertices.end(); ++jj) {

            secondVertex = indexVerticesMatrix[*jj];

            for (int i = 0; i < maxSizeCover; ++i) {
                this->buildingSAT(SAT, (i * vertexCount + firstVertex) + 1, " ");
                this->buildingSAT(SAT, (i * vertexCount + secondVertex) + 1, " ");
            }
            SAT.operator +=("0\n");
            temporaryGraph.removeEdge(*ii, *jj);
        }
    }
    /* end of building the matrix and the SAT instance from the graph to pass
     * for minisat */

    /* ------------------------------------*
     * launch minisat on the SAT instance  *
     * ------------------------------------*/
    file << SAT;
    file.close();

    string in = this->convertToString(inFile);
    string out = this->convertToString(outFile);
    string launchMinisat = "minisat -verb=0 " + in + " " + out;
    system(launchMinisat.c_str());

    set<int> vertexCover, vertexCoverFromMinisat;

    ifstream fileOut(outFile, ios::in);
    string get;
    int getInt;

    while (!fileOut.eof()) {

        fileOut >> get;
        getInt = atoi(get.c_str());
        if (getInt > 0)
            vertexCover.insert(getInt);
    }

    fileOut.close();

    /* ------------------------------------*
     * get the vertex cover returned by   *
     * "minisat" if it exists                *
     * ------------------------------------*/
    for (set<int>::iterator ii = vertexCover.begin(); ii != vertexCover.end();
            ++ii) {
        for (map<int, int>::iterator hh = indexVerticesMatrix.begin();
                hh != indexVerticesMatrix.end(); ++hh) {
            if ((*hh).second == ((*ii - 1) % vertexCount))
                vertexCoverFromMinisat.insert((*hh).first);
        }
    }
    return vertexCoverFromMinisat;
}

/*------------------------------------------- SIMPLE SAT --------------------------------------------------------------*/
set<int> Minisat::getMinisatCoverFromSimpleSAT(Graph graph, char * inFile,
        char *outFile) {

    set<int> vertices = graph.getVertices();
    set<int> markedVertices;
    string SAT;
    int vertex;

    SAT.operator =("c this is the SAT instance from the graph \n");
    SAT.operator +=("p cnf ");

    this->buildingSAT(SAT, vertices.size(), " ");
    this->buildingSAT(SAT, graph.getEdgeCount(), "\n");

    for (set<int>::iterator ii = vertices.begin(); ii != vertices.end(); ++ii) {

        vertex = *ii;
        markedVertices = graph.getNeighbours(vertex);

        for (set<int>::iterator jj = markedVertices.begin();
                jj != markedVertices.end(); ++jj) {

            this->buildingSAT(SAT, *ii, " ");
            this->buildingSAT(SAT, *jj, " 0\n");
            graph.removeEdge(*ii, *jj);
        }
    }
    /* ------------------------------------*
     * launch minisat on the SAT instance  *
     * ------------------------------------*/

    // Open the file inFile
    ofstream file(inFile, ios::out | ios::trunc);
    file << SAT;
    file.close();

    string in = this->convertToString(inFile);
    string out = this->convertToString(outFile);
    string launchMinisat = "minisat -verb=0 " + in + " " + out;
    system(launchMinisat.c_str());

    /* ------------------------------------*
     * get the vertex cover returned bye   *
     * "minisat" if it exists              *
     * ------------------------------------*/
    set<int> vertexCover;

    ifstream fileOut(outFile, ios::in);
    string get;
    int getInt;

    while (!fileOut.eof()) {

        fileOut >> get;
        getInt = atoi(get.c_str());
        if (getInt > 0)
            vertexCover.insert(getInt);
    }

    fileOut.close();

    return vertexCover;
}

void Minisat::buildingSAT(string &SAT, int toConvert, std::string toInsert) {

    ostringstream oss;
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

