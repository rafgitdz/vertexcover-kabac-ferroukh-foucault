#ifndef BIPARTITEOPTIMALCOVER_H_
#define BIPARTITEOPTIMALCOVER_H_

#include "OrientedGraph.h"
#include "SearchAlgorithm.h"
#include "../generation/BipartiteGraph.h"



class AlgorithmBipartiteOptimal {
public:
	AlgorithmBipartiteOptimal(const BipartiteGraph&);
	std::set<int> getCover();

private :
	void buildMaxFlow();

	BipartiteGraph m_graph;
	OrientedGraph m_flowGraph;
	int m_sourceVertex;
	int m_targetVertex;
	SearchAlgorithm m_search;

};

#endif /* BIPARTITEOPTIMALCOVER_H_ */
