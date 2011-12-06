#ifndef BIPARTITEOPTIMALCOVER_H_
#define BIPARTITEOPTIMALCOVER_H_

#include "OrientedGraph.h"
#include "SearchAlgorithm.h"
#include "../generation/BipartiteGraph.h"



class BipartiteOptimalCover {
public:
	BipartiteOptimalCover(BipartiteGraph&);
	std::set<int> getCover(BipartiteGraph&);

private :
	void buildMaxFlow();

	OrientedGraph m_flowGraph;
	int m_sourceVertex;
	int m_targetVertex;
	SearchAlgorithm m_search;
};

#endif /* BIPARTITEOPTIMALCOVER_H_ */
