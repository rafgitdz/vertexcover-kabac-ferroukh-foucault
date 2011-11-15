#include <iostream>
#include "TreeDynamicSons.h"
#include "TreeStaticSons.h"
#include "AlgorithmCoverEdges.h"
#include "SearchAlgorithm.h"
#include "AlgorithmDeepSearch.h"

using namespace std;

void display(Graph g) {
    cout << g << endl;
}

void testDynamicTree() {

    TreeDynamicSons t(15);
    display(t);
}

void testStaticTree() {

    TreeStaticSons t2(15, 2);
    display(t2);
}

void testAlgoCoverEdges() {

    TreeDynamicSons t2(10);
    display(t2);
    AlgorithmCoverEdges ace(t2);
    std::set<int> cover = ace.getCover();

    cout << "\n The cover is : ";
    for (set<int>::iterator jj = cover.begin(); jj != cover.end(); ++jj)
        cout << *jj << ",";
    cout << endl;
}

void testExistsEdges() {

    Graph g;
    g.addVertex();
    g.addVertex();
    g.addVertex();
    //    g.addEdge(1,2);
    AlgorithmCoverEdges ace(g);
    if (ace.existsEdges()) cout << "YES ! " << endl;
    else cout << "NO ! " << endl;
}

void testBreadhtSearch() {

    TreeDynamicSons t(10);
    cout << t;
    SearchAlgorithm searchAlg;
    list<int> result = searchAlg.breadhtFirstSearch(t, 1);
    cout << "The search of breadht result is : ";
    for (list<int>::iterator ii = result.begin(); ii != result.end(); ++ii) {
        cout << *ii << ",";
    }
    cout << endl;
}

void testDepthSearch() {

    TreeDynamicSons t(10);
    cout << t;
    AlgorithmDeepSearch AlgDeep(t);
    set<int> result = AlgDeep.getCover(1);
    "The cover of search depth is : ";
    for (set<int>::iterator ii = result.begin(); ii != result.end(); ++ii) {
        cout << *ii << ",";
    }
}

void testDepthSearch2() {

    TreeStaticSons t(20,2);
    cout << t;
    SearchAlgorithm sa;
    list<int> result = sa.depthFirstSearch(t, 1);
    "The search depth result is : ";
    for (list<int>::iterator ii = result.begin(); ii != result.end(); ++ii) {
        cout << *ii << ",";
    }

}

int main() {

//    testDynamicTree();
//    testStaticTree();
//    testAlgoCoverEdges();
//    testBreadhtSearch();
//    testDepthSearch();
    testDepthSearch2();
    return 0;
}
