#ifndef BIPARTITEOPTIMALCOVER_H_
#define BIPARTITEOPTIMALCOVER_H_

#include "OrientedGraph.h"
class BipartiteGraph;
class BipartiteOptimalCover {
public:
	explicit BipartiteOptimalCover(BipartiteGraph&);

private :
	OrientedGraph m_flowGraph;

};

#endif /* BIPARTITEOPTIMALCOVER_H_ */
