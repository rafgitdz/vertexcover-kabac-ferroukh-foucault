#include "Graph.h"
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

Graph::Graph(int vertexCount) :
m_graph(), m_vertexCount(0), m_edgeCount(0), m_graphInitialSize(
vertexCount) {

    srand(time(NULL));
    for (int i = 0; i < vertexCount; i++)
        addVertex();
}

Graph::Graph(const Graph& graph) :
m_graph(graph.m_graph), m_edgeCount(graph.getEdgeCount()) {
}

/*
 * Constructor of a graph that is built by passing the path of the file that
 * contains the structure of the graph
 */
Graph::Graph(char *pathFile) :
m_graph(), m_vertexCount(0), m_edgeCount(0), m_graphInitialSize(0) {

    string vertexFile;
    int currentRoot;
    int currentNeighbour;
    set<int> neighbours;
    string line;

    ifstream file(pathFile, ios::in);

    while (getline(file, line)) { // until it hasn't a line in the file

        istringstream iss(line);

        iss >> vertexFile; // get the root vertex of the line
        currentRoot = atoi(vertexFile.c_str());
        iss >> vertexFile; // avoid ":"

        while (iss) {

            iss >> vertexFile; // get the neighbours one bye one
            currentNeighbour = atoi(vertexFile.c_str());
            if(currentNeighbour!=0) neighbours.insert(currentNeighbour);
        }

        m_graph[currentRoot] = neighbours; // set the connections
        m_edgeCount += neighbours.size();
        neighbours.clear();
    } // end while
    m_edgeCount /= 2;
} // end constructor Graph(chr * File)

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

/*
 * Complexity : logarithmic in the graph size, plus logarithmic
 * in the number of neighbors of each endpoint of the edge
 */
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

/*
 * O(n*log(n))
 * Recuperates the vertices of the graph
 */
set<int> Graph::getVertices() const {

    set<int> vertices;
    map<int, set<int> >::const_iterator it;
    // O(n)
    for (it = m_graph.begin(); it != m_graph.end(); ++it)
        // O(log(n))
        vertices.insert((*it).first);
    return vertices;
}

void Graph::removeVertex(int vertex) {
    set<int> neigh = m_graph[vertex];
    for (set<int>::iterator ii = neigh.begin(); ii != neigh.end(); ++ii) {
        m_graph[*ii].erase(vertex);
        --m_edgeCount;
    }
    m_graph.erase(vertex);
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

// Complexity => o(n*log(n))

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

/*
 * get the the pathFile as parameter, to save the current built graph in it
 */
void Graph::saveGraph(char *pathFile) const {

    ofstream file(pathFile, ios::out | ios::trunc);
    file << *this;
    file.close();
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

