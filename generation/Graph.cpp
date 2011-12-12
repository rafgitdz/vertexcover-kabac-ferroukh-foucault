#include "Graph.h"
#include <cstdlib>

using namespace std;

Graph::Graph(int vertexCount) :
m_graph(), m_vertexCount(0), m_edgeCount(0), m_graphInitialSize(
vertexCount) {


    srand(time(NULL));
    for (int i = 0; i < vertexCount; i++)
        addVertex();
}

Graph::Graph(const Graph& graph) :
m_graph(), m_edgeCount(graph.getEdgeCount()) {
    set<int> vertices = graph.getVertices();
    for (set<int>::const_iterator ii = vertices.begin(); ii != vertices.end();
            ++ii)
        m_graph[*ii] = graph.getNeighbours(*ii);
}

int Graph::addVertex() {

    set<int> s;
    int graphSize = m_graph.size() + 1;

    int vertex = rand() % (max(m_graphInitialSize, graphSize) * 10);
    while (m_graph.find(vertex) != m_graph.end()) {
        vertex = rand() % (max(m_graphInitialSize, graphSize) * 10);
    }
    m_graph[vertex] = s;
    return vertex;
}

void Graph::addVertex(int vertexNum) {

    set<int> s;
    m_graph[vertexNum] = s;
}

void Graph::addEdge(int vertex1, int vertex2) {
    m_graph[vertex1].insert(vertex2);
    m_graph[vertex2].insert(vertex1);
    ++m_edgeCount;
}

void Graph::removeEdge(int vertex1, int vertex2) {
    m_graph[vertex1].erase(vertex2);
    m_graph[vertex2].erase(vertex1);
    --m_edgeCount;
}


void Graph::removeVertexAndIsolatedNeighbour(int vertex) {

    set<int> neigh = m_graph[vertex];

    for (set<int>::iterator ii = neigh.begin(); ii != neigh.end(); ++ii) {
        m_graph[*ii].erase(vertex);
        if (m_graph[*ii].empty()) {
            m_graph.erase(*ii);
        }
        --m_edgeCount;
    }
    m_graph.erase(vertex);
}

set<int> Graph::getVertices() const {

    set<int> vertices;
    map<int, set<int> >::const_iterator it;
    for (it = m_graph.begin(); it != m_graph.end(); ++it)
        vertices.insert((*it).first);
    return vertices;
}


bool Graph::isCover(set<int> cover) const {

    map<int, set<int> >::const_iterator ii;
    set<int>::const_iterator jj;
    for (ii = m_graph.begin(); ii != m_graph.end(); ++ii)
        for (jj = ii->second.begin(); jj != ii->second.end(); ++jj) {
            if (cover.find(ii->first) == cover.end()
                    && cover.find(*jj) == cover.end())
                return false;
        }
    return true;
}

void Graph::trim() {
    for (map<int, set<int> >::const_iterator ii = m_graph.begin();
            ii != m_graph.end();) {
        if (ii->second.size() == 0) {
            int vertex = ii->first;
            ++ii;
            m_graph.erase(vertex);
        }
        ++ii;
    }
}

std::ostream &operator<<(std::ostream &out, const Graph& g) {

    for (map<int, set<int> >::const_iterator ii = g.m_graph.begin();
            ii != g.m_graph.end(); ++ii) {
        int vertex = (*ii).first;
        out << vertex << " : ";
        set<int> neigh = (*ii).second;
        for (set<int>::iterator jj = neigh.begin(); jj != neigh.end(); ++jj) {
            out << (*jj) << " ";
        }
        out << endl;

    }
    return out;
}

