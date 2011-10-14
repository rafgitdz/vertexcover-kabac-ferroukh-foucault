/*
 * SimpleGraph.h
 *
 *  Created on: 13 oct. 2011
 *      Author: mfoucaul
 */

#ifndef SIMPLEGRAPH_H_
#define SIMPLEGRAPH_H_

#include "Graph.h"

class SimpleGraph: protected Graph {
public:
	SimpleGraph(int vertexNum, float edgeProba);
	virtual ~SimpleGraph();
};

#endif /* SIMPLEGRAPH_H_ */
