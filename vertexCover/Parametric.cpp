#include "Parametric.h"
#include <cassert>

using namespace std;

Parametric::Parametric() {
}
Parametric::~Parametric() {
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

	if (tryC1 || c1.size() < c2.size()) {
		cover = c1;
		cover.insert(v1);
		cout << "cover 1" << endl << "size " << maxCoverSize << endl;
		for (set<int>::iterator ii = cover.begin(); ii != cover.end(); ++ii)
			cout << *ii << endl;
		cout << "done" << endl;
		assert(g.isCover(cover));
		return true;
	}
	cover = c2;
	cover.insert(v2);
	cout << "cover 2" << endl  << "size " << maxCoverSize << endl;
	for (set<int>::iterator ii = cover.begin(); ii != cover.end(); ++ii)
		cout << *ii << endl;
	cout << "done" << endl;
	assert(g.isCover(cover));
	return true;

}



