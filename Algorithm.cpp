/*
 * Algorithm.cpp
 *
 *  Created on: 27 oct. 2011
 *      Author: rferrouk
 */

#include "Algorithm.h"

Algorithm::Algorithm(Graph g) {
		graph = g;
}

Algorithm::~Algorithm() {
	delete graph;
}
