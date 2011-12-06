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
	void buildMinCut();

	OrientedGraph m_flowGraph;
	int m_sourceVertex;
	int m_targetVertex;
	std::list<int> m_S;
	std::list<int> m_T;
	SearchAlgorithm m_search;
	BipartiteGraph m_graph;
};

#endif /* BIPARTITEOPTIMALCOVER_H_ */
