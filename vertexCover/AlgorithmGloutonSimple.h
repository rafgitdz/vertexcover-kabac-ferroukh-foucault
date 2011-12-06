/*
 * AlgorithmGloutonSimple.h
 *
 *  Created on: 18 nov. 2011
 *      Author: milan
 */


#ifndef ALGORITHMGLOUTONSIMPLE_H_
#define ALGORITHMGLOUTONSIMPLE_H_

#include "AlgorithmGlouton.h"

using namespace std;

class AlgorithmGloutonSimple : public AlgorithmGlouton {
public:
	AlgorithmGloutonSimple(Graph graph);
	virtual ~AlgorithmGloutonSimple();
	virtual void findMinimalVertexCover();
private:
	multimap<int, int> vertexDegree;
};

#endif /* ALGORITHMGLOUTONSIMPLE_H_ */
