#include "Parametric.h"

using namespace std;

Parametric::Parametric(const Graph &g) : m_graph(g) {
	m_graph.trim();
}

bool Parametric::tryGetCover(unsigned maxCoverSize, std::set<int> &cover) {
	return tryGetCover(m_graph, maxCoverSize, cover);
}
bool Parametric::tryGetCoverBis(unsigned maxCoverSize, std::set<int> &cover) {
	return tryGetCoverBis(m_graph,maxCoverSize,cover);
}

bool Parametric::tryGetCover(Graph g, unsigned maxCoverSize, set<int> &cover) {

	if (g.getVertexCount() == 0)
		return true;
	if (maxCoverSize == 0)
		return false;

	Graph g1(g);
	int v1 = g.getBeginGraph()->first;
	int v2 = *(g.getBeginGraph()->second.begin());

	g.removeVertexAndIsolatedNeighbour(v1);
	g1.removeVertexAndIsolatedNeighbour(v2);

	set<int> c1, c2;
	bool tryC1 = tryGetCover(g, maxCoverSize -1, c1);
	bool tryC2 = tryGetCover(g1, maxCoverSize -1, c2);

	if (!tryC1 && !tryC2)
		return false;

	if (tryC1) {
		cover = c1;
		cover.insert(v1);

		return true;
	}

	cover = c2;
	cover.insert(v2);

	return true;

}


bool Parametric::tryGetCoverBis(Graph g, unsigned maxCoverSize, set<int> &cover) {

	if (g.getVertexCount() == 0)
		return true;
	if (maxCoverSize == 0)
		return false;

	Graph g1(g);
	int v1 = g.getBeginGraph()->first;
	set<int> vertices = g.getBeginGraph()->second;

	g.removeVertexAndIsolatedNeighbour(v1);
	for (set<int>::iterator ii = vertices.begin();
			ii != vertices.end();
			++ii)
		g1.removeVertexAndIsolatedNeighbour(*ii);

	set<int> c1, c2;
	bool tryC1 = tryGetCover(g, maxCoverSize -1, c1);
	bool tryC2 = false;
	if (vertices.size() <= maxCoverSize)
		tryC2 = tryGetCover(g1, maxCoverSize - vertices.size(), c2);

	if (!tryC1 && !tryC2)
		return false;

	if (tryC1) {
		cover = c1;
		cover.insert(v1);

		return true;
	}

	cover = c2;
	for (set<int>::iterator ii = vertices.begin();
				ii != vertices.end();
				++ii)
	cover.insert(*ii);

	return true;

}

