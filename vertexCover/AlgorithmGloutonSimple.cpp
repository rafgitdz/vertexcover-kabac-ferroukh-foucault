/*
 * AlgorithmGloutonSimple.cpp
 *
 *  Created on: 18 nov. 2011
 *      Author: milan
 */

#include "AlgorithmGloutonSimple.h"

using namespace std;

AlgorithmGloutonSimple::AlgorithmGloutonSimple(Graph graph) :
		AlgorithmGlouton(graph) {
}

set<int> AlgorithmGloutonSimple::getCover() {
	m_graph.trim();
	map<int, set<int> >::const_iterator it;
	multimap<int, int>::const_iterator it1;

	for (it = m_graph.getBeginGraph(); it != m_graph.getEndGraph(); it++)
		vertexDegree.insert(pair<int, int>((it->second).size(), it->first));

	it1 = vertexDegree.end();
	do {
		it1--;
		vertexCover_.insert(it1->second);
		m_graph.removeVertexAndIsolatedNeighbour(it1->second);
	} while ((m_graph.getVertexCount() > 0) && (it1 != vertexDegree.begin()));

	return vertexCover_;
}
