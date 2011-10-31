#ifndef BIPARTITEGRAPH_H_
#define BIPARTITEGRAPH_H_

#include "Graph.h"

class BipartiteGraph: public Graph {
	public:
		BipartiteGraph(int graphSize, float edgeProba, float partRatio = 0.5);
};

#endif /* BIPARTITEGRAPH_H_ */
