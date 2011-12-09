#ifndef BIPARTITEGRAPH_H_
#define BIPARTITEGRAPH_H_

#include "Graph.h"

class BipartiteGraph: public Graph {
	public:
		BipartiteGraph(int graphSize, float edgeProba, float partRatio = 0.5);
		inline const std::set<int>& getLeftPart() {return m_leftPart;}
		inline const std::set<int>& getRightPart() {return m_rightPart;}

	private:
		std::set<int> m_leftPart;
		std::set<int> m_rightPart;
};

#endif /* BIPARTITEGRAPH_H_ */
