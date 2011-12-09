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
 * DrawGraph.cpp                                                               *
 * Goal :                                                                      *
 * Parameters : none                                                           *
 *____________________________________________________________________________*/   

using namespace std;

#include "drawGraph.h"
#include <sstream>
#include <iostream>
#include <fstream>

DrawGraph::DrawGraph() {
}

void DrawGraph::drawGraph(Graph graph, list<int> vertexCover, char *pictureFile) {

    int first;
    string text = "";
    text.operator +=("graph G {");
    for (map<int, set<int> >::const_iterator ii = graph.getBeginGraph(); ii != graph.getEndGraph(); ++ii) {

        first = (*ii).first;
        set<int> neigh = (*ii).second;

        for (list<int>::iterator ii = vertexCover.begin(); ii != vertexCover.end(); ++ii)
            text.operator +=(convertToString(*ii) + " [color = red];\n");

        for (set<int>::iterator jj = neigh.begin(); jj != neigh.end(); ++jj) {

            text.operator +=(convertToString(first));
            text.operator +=(" -- ");
            text.operator +=(convertToString(*jj));
            text.operator +=(";\n");
            graph.removeEdge(first, *jj);
        }
    }
    text.operator +=("}");

    ofstream graphFile("graph.dot", ios::out | ios::trunc);
    if (graphFile) {
        cout << "Success to open file !" << endl;
    } else cerr << "Failed to open file!";

    graphFile << text;
    graphFile.close();
    string out = this->convertToString(pictureFile);
    string launchGraphViz = "../../GraphViz/bin/dot -Tpng -o " + out + " graph.dot";
    system(launchGraphViz.c_str());
}

string DrawGraph::convertToString(int toConvert) {
    std::ostringstream oss;
    oss << toConvert;
    return oss.str();
}

string DrawGraph::convertToString(char* toConvert) {
    std::ostringstream oss;
    oss << toConvert;
    return oss.str();
}

DrawGraph::~DrawGraph() {
}

