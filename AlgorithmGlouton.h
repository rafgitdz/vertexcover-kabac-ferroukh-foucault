/*
 * AlgorithmGlouton.h
 *
 *  Created on: 6 nov. 2011
 *      Author: milan
 */

#ifndef ALGORITHMGLOUTON_H_
#define ALGORITHMGLOUTON_H_

#include "Algorithm.h"

class AlgorithmGlouton : public Algorithm {
public:
	AlgorithmGlouton(Graph graph);
	virtual ~AlgorithmGlouton();
	void removeIsolatedVertices();
	int addEdgeToVC();

private:
	Graph graph_;
	std::set<int> vertexCover_;
};

#endif /* ALGORITHMGLOUTON_H_ */
