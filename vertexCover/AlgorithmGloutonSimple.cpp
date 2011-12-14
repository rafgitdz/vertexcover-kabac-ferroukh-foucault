#include "AlgorithmGloutonSimple.h"

using namespace std;


set<int> AlgorithmGloutonSimple::getCover() {
	map<int, set<int> >::const_iterator it;
	multimap<int, int>::const_iterator it1;

	for (it = m_graph.getBeginGraph(); it != m_graph.getEndGraph(); it++)
		vertexDegree.insert(pair<int, int>((it->second).size(), it->first));

	it1 = vertexDegree.end();
	do {
		it1--;
		vertexCover_.insert(it1->second);
		m_graph.removeVertex(it1->second);
	} while ((m_graph.getEdgeCount() > 0) && (it1 != vertexDegree.begin()));

	return vertexCover_;
}
