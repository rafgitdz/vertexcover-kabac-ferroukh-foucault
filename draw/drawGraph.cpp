/* 
 * File:   drawGraph.cpp
 * Author: Rafik
 * 
 * Created on 7 décembre 2011, 23:07
 */

using namespace std;

#include "drawGraph.h"
#include <sstream>
#include <iostream>
#include <fstream>

DrawGraph::DrawGraph(Graph graph) {
    _graph = graph;
}

string DrawGraph::generateTextToDraw() {

    int first;
    string text = "";
    text.operator +=("graph G {");
    for (map<int, set<int> >::const_iterator ii = _graph.getBeginGraph(); ii != _graph.getEndGraph(); ++ii) {

        first = (*ii).first;
        set<int> neigh = (*ii).second;
        for (set<int>::iterator jj = neigh.begin(); jj != neigh.end(); ++jj) {
            text.operator +=(convertToString(first));
            text.operator +=(" -- ");
            text.operator +=(convertToString(*jj));
            text.operator +=(";\n");
        }
    }
    text.operator +=("}");
    return text;
}

void DrawGraph::launchGraphViz(string file) {

    ofstream graph("graph.dot", ios::out | ios::trunc);
    if (graph) {
        cout << "Success to open file !" << endl;
    } else cerr << "Failed to open file!";

    graph << file;
    graph.close();
    system("dot -Tpng -o graph.png graph.dot");
}

string DrawGraph::convertToString(int toConvert) {
    std::ostringstream oss;
    oss << toConvert;
    return oss.str();
}

DrawGraph::~DrawGraph() {
}

