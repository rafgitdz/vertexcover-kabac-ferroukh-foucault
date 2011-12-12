#include "SimpleGraph.h"
#include <cstdlib>

using namespace std;

SimpleGraph::SimpleGraph(int vertexCount, float edgeProba) : Graph() {

    probability = (int) (edgeProba * 100);
    std::map<int, std::set<int> >::iterator ii;
    for (int i = 0; i < vertexCount; ++i) {
        set<int> neigh;
        int graphSize = m_graph.size() + 1;

        int vertex = rand() % (max(m_graphInitialSize, graphSize) * 10);
        while (m_graph.find(vertex) != m_graph.end()) {
            vertex = rand() % (max(m_graphInitialSize, graphSize) * 10);
        }
        for (ii = m_graph.begin(); ii != getEndGraph(); ii++) {
            if (rand() % 100 < probability) {
            	ii->second.insert(vertex);
            	neigh.insert(ii->first);
            }
        }
        m_graph[vertex] = neigh;
    }
}
