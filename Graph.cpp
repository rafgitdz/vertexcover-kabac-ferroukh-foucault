#include "Graph.h"
#include <algorithm>

using namespace std;

Graph::Graph(int vertexCount) : m_graph(), m_vertexCount(0) {

    for (int i = 0; i < vertexCount; i++)
        addVertex();
}

int Graph::addVertex() {
    m_vertexCount++;
    set<int> s;
    m_graph[m_vertexCount] = s;
    return m_vertexCount;
}

void Graph::addEdge(int vertex1, int vertex2) {
    m_graph[vertex1].insert(vertex2);
    m_graph[vertex2].insert(vertex1);
}

void Graph::removeEdge(int vertex1, int vertex2) {
    m_graph[vertex1].erase(vertex2);
    m_graph[vertex2].erase(vertex1);
}

void Graph::removeVertex(int vertex) {

    set<int> neigh = m_graph[vertex];
    for (set<int>::iterator ii = neigh.begin(); ii != neigh.end(); ++ii) {
        m_graph[*ii].erase(vertex);
    }

    m_graph.erase(vertex);
}

bool Graph::hasEdge(int vertex1, int vertex2) {
     
    return m_graph[vertex1].find(vertex2) != m_graph[vertex1].end();
}

bool Graph::hasPath(int vertex1, int vertex2, int precedentVertex) {

    if (hasEdge(vertex1, vertex2))
        return true;
    else {

        for (set<int>::iterator currentVertex = m_graph[vertex1].begin(); currentVertex != m_graph[vertex1].end(); ++currentVertex) {

            if (*currentVertex != precedentVertex) {
                if (hasPath(*currentVertex, vertex2, vertex1))
                    return true;
            }
        }
        return false;
    }
}

set<int> Graph::getNeighbours(int vertex) {
    return m_graph[vertex];
}

set<int> Graph::getVertices() {

    set<int> vertices;
    std::map<int, std::set<int> >::iterator it;

    for (it = m_graph.begin(); it != m_graph.end(); it++) {
        vertices.insert(it->first);
    }

    return vertices;
}

int Graph::getVertexCount() {
    return m_vertexCount;
}

map<int, set<int> >::const_iterator Graph::getBeginGraph() {
    return m_graph.begin();
}

map<int, set<int> >::const_iterator Graph::getEndGraph() {
    return m_graph.end();
}

Graph::~Graph() {
}

std::ostream &operator<<(std::ostream &out, const Graph& g) {

    for (map<int, set<int> >::const_iterator ii = g.m_graph.begin(); ii != g.m_graph.end(); ++ii) {
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


