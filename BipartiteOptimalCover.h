#ifndef BIPARTITEOPTIMALCOVER_H_
#define BIPARTITEOPTIMALCOVER_H_

class OrientedGraph;
class BipartiteGraph;
class BipartiteOptimalCover {
public:
	BipartiteOptimalCover(BipartiteGraph&);
	virtual ~BipartiteOptimalCover();

private :
	OrientedGraph m_flowGraph;

};

#endif /* BIPARTITEOPTIMALCOVER_H_ */
