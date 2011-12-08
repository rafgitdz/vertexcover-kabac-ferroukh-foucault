/* 
 * File:   drawGraph.h
 * Author: Rafik
 *
 * Created on 7 décembre 2011, 23:07
 */

#ifndef DRAWGRAPH_H
#define	DRAWGRAPH_H

#include "../generation/Graph.h"

class DrawGraph {
public:
    DrawGraph(Graph graph);
    virtual ~DrawGraph();

    std::string generateTextToDraw();
    std::string convertToString(int toConvert);
    void launchGraphViz(std::string file);

private:
    Graph _graph;
};

#endif	/* DRAWGRAPH_H */

