/*
 * BipartiteGraph.h
 *
 *  Created on: 13 oct. 2011
 *      Author: mfoucaul
 */

#ifndef BIPARTITEGRAPH_H_
#define BIPARTITEGRAPH_H_

#include "Graph.h"

class BipartiteGraph: protected Graph {
	public:
		BipartiteGraph(); // add params
		virtual ~BipartiteGraph();
	private:
		std::list<int> m_partA;
		std::list<int> m_partB;
};

#endif /* BIPARTITEGRAPH_H_ */
