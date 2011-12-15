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
 * DrawGraph.cpp                                                               *
 * GraphViz (DOT) link : http://www.graphviz.org/                              *
 * Goal : draw a graph and export it in a png format file with DOT             *
 * Parameters : none                                                           *
 *____________________________________________________________________________*/

using namespace std;

#include "drawGraph.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>

void DrawGraph::drawGraph(Graph graph, set<int> vertexCover, char *pictureFile) {

    // Build the file ".dot" to be treated by dot to draw
    int first;
    string text = "";
    text.operator +=("graph G {");

    // distinguish the vertices of the cover from the others
    for (set<int>::iterator ii = vertexCover.begin(); ii != vertexCover.end(); ++ii)
        text.operator +=(convertToString(*ii) + " [color = red];\n");

    for (map<int, set<int> >::const_iterator ii = graph.getBeginGraph(); ii != graph.getEndGraph(); ++ii) {

        first = (*ii).first;
        set<int> neigh = (*ii).second;
        /*
         * set in the file ".dot" all the connections in the graph
         * note : an edge (a,b) is represented bye ("a -- b") in the file
         */
        if ((ii->second).empty()) {

            text.operator +=(convertToString((*ii).first));
            text.operator +=(";\n");
            graph.removeVertex((*ii).first);

        } else {
            for (set<int>::iterator jj = neigh.begin(); jj != neigh.end(); ++jj) {

                text.operator +=(convertToString(first));
                text.operator +=(" -- ");
                text.operator +=(convertToString(*jj));
                text.operator +=(";\n");
                graph.removeEdge(first, *jj);
            }
        }
    }

    text.operator +=("}");
    // end building

    // launch dot with the "graph.dot" where we set the "text" string in it
    ofstream graphFile("graph.dot", ios::out | ios::trunc);

    graphFile << text;
    graphFile.close();
    string out = this->convertToString(pictureFile);
    string launchGraphViz = "dot -Tpng -o " + out + " graph.dot";
    system(launchGraphViz.c_str()); // launch DOT
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
