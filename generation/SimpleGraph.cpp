#include "SimpleGraph.h"
#include <ctime>

using namespace std;

SimpleGraph::SimpleGraph(int vertexCount, float edgeProba) : Graph(vertexCount) {

    srand((unsigned) time(0));
    probability = (int) (edgeProba * 100);

    std::map<int, std::set<int> >::const_iterator it1;
    std::map<int, std::set<int> >::const_iterator it2;
    for (it1 = getBeginGraph(); it1 != getEndGraph(); it1++) {
        it2 = it1;
        it2++;
        for (; it2 != getEndGraph(); it2++) {
            if (rand() % 100 < probability)
                addEdge(it1->first, it2->first);
        }
    }
}
