#ifndef TEST_H_
#define TEST_H_

#include <iostream>
#include <cstring>
#include <cassert>
#include "generation/TreeDynamicSons.h"
#include "generation/TreeStaticSons.h"
#include "vertexCover/AlgorithmCoverEdges.h"
#include "vertexCover/SearchAlgorithm.h"
#include "vertexCover/AlgorithmDeepSearch.h"
#include "vertexCover/AlgorithmBipartiteOptimal.h"
#include "generation/BipartiteGraph.h"
#include "generation/SmallCoverGraph.h"
#include "vertexCover/Parametric.h"
#include "vertexCover/AlgorithmGlouton.h"
#include "vertexCover/AlgorithmGloutonSimple.h"
#include "draw/drawGraph.h"
#include "vertexCover/Minisat.h"
#include "vertexCover/OptimalTreeAlgorithm.h"

using namespace std;

bool testGreedy() {

	for (int i = 0; i < 50; ++i) {
		SimpleGraph g(100, 0.2);
		AlgorithmGlouton algo(g);
		set<int> cover = algo.getCover();

		if (!g.isCover(cover)) {
			cout << "The Greedy algorithm doesn't work" << endl;
			return false;
		}
	}
	cout << "The Greedy algorithm works" << endl;
	return true;
}

bool testGreedySimple() {

	for (int i = 0; i < 50; ++i) {
		SimpleGraph g(100, 0.2);
		AlgorithmGloutonSimple algo(g);
		set<int> cover = algo.getCover();

		if (!g.isCover(cover)) {
			cout << "The Greedy Simple algorithm doesn't work" << endl;
			return false;
		}
	}
	cout << "The Greedy Simple algorithm works" << endl;
	return true;
}

bool testDeepSearch() {

	for (int i = 0; i < 50; ++i) {
		SimpleGraph g(10, 0.5);
		AlgorithmDeepSearch algo(g);
		set<int> cover = algo.getCover();

		if (!g.isCover(cover)) {
			cout << "The Deep Search algorithm doesn't work" << endl;
			return false;
		}
	}
	cout << "The Deep Search algorithm works" << endl;
	return true;
}

bool testCoverEdges() {

	for (int i = 0; i < 50; ++i) {
		SimpleGraph g(100, 0.2);
		AlgorithmCoverEdges algo(g);
		set<int> cover = algo.getCover();

		if (!g.isCover(cover)) {
			cout << "The Cover Edges algorithm works" << endl;
			return false;
		}
	}
	cout << "The Cover Edges algorithm works" << endl;
	return true;
}

bool testBipartiteOptimal() {

	for (int i = 0; i < 50; ++i) {
		BipartiteGraph g(100, 0.2, 0.4);
		AlgorithmBipartiteOptimal algo(g);
		set<int> cover = algo.getCover();

		if (!g.isCover(cover)) {
			cout << "The Bipartite Optimal algorithm doesn't work" << endl;
			return false;
		}
	}
	cout << "The Bipartite Optimal algorithm works" << endl;
	return true;
}

bool testTreeOptimal() {

	for (int i = 0; i < 50; ++i) {

		TreeDynamicSons t(100,100,0);
		OptimalTreeAlgorithm algo(t);
		set<int> cover = algo.getVertexCover();

		if (!t.isCover(cover)) {
			cout << "The Tree optimal algorithm doesn't work" << endl;
			return false;
		}

		TreeStaticSons t2(100, 2);
		OptimalTreeAlgorithm algo2(t2);
		set<int> cover2 = algo2.getVertexCover();

		if (!t2.isCover(cover2)) {
			cout << "The Tree optimal algorithm doesn't work" << endl;
			return false;
		}
	}
	cout << "The Tree optimal algorithm works" << endl;
	return true;

}
bool testParametric() {

	for (int i = 0; i < 50; ++i) {

		SmallCoverGraph g(10, 0.2, 5);
		Parametric algo(g);
		set<int> cover;

		if (!(algo.tryGetCover(5, cover) && g.isCover(cover))) {
			cout << "The Parametric algorithm doesn't work" << endl;
			return false;
		}

		cover.clear();
		if (!(algo.tryGetCoverBis(5, cover) && g.isCover(cover))) {
			cout << "The Parametric Bis algorithm doesn't work" << endl;
			return false;
		}
	}

	cout << "The Parametric algorithm works" << endl;
	return true;
}
bool testMinisat() {

	for (int i = 0; i < 50; ++i) {
	SmallCoverGraph g(10, 0.6, 3);
	Minisat algo;
	set<int> cover = algo.getMinisatCoverFromComplexSAT(g, 5, "minisat.in", "minisat.out");

	if (!g.isCover(cover)) {
		cout << "The minisat doesn't work" << endl;
		return false;
	}

	set<int> cover2 = algo.getMinisatCoverFromSimpleSAT(g, "minisat.in", "minisat.out");

	}

	cout << "The minisat works" << endl;
	return true;

}

bool testAll() {

	return (testGreedy() && testGreedySimple() && testDeepSearch()
			&& testCoverEdges() && testBipartiteOptimal() && testTreeOptimal()
			&& testParametric() && testMinisat());
}

#endif // TEST_H_
