#include "Graph.h"
<<<<<<< HEAD
#include <algorithm>
#include <limits>
#include <cassert>

using namespace std;

Graph::Graph(int vertexCount) : m_graph() {

    srand(time(NULL));
    for (int i = 0; i < vertexCount; i++) 
=======
#include "SearchAlgorithm.h"
#include <algorithm>

using namespace std;

Graph::Graph(int vertexCount) : m_graph(), m_vertexCount(0) {

    for (int i = 0; i < vertexCount; i++)
>>>>>>> myRepos/master
        addVertex();
}

int Graph::addVertex() {
<<<<<<< HEAD

	set<int> s;
	int vertex = rand()%numeric_limits<int>::max();
	while (m_graph.find(vertex) != m_graph.end()) {
		vertex = rand()%numeric_limits<int>::max();
	}
	m_graph[vertex] = s;
	return vertex;
}

void Graph::addVertex(int vertexNum) {
	assert(m_graph.find(vertexNum) == m_graph.end());

	set<int> s;

	m_graph[vertexNum] = s;
=======
    m_vertexCount++;
    set<int> s;
    m_graph[m_vertexCount] = s;
    return m_vertexCount;
}

//int Graph::addVertex() {
//
//        set<int> s;
//        int vertex = rand()%numeric_limits<int>::max();
//        while (m_graph.find(vertex) != m_graph.end()) {
//                vertex = rand()%numeric_limits<int>::max();
//        }
//        m_graph[vertex] = s;
//        return vertex;
//}
//

void Graph::addVertex(int vertexNum) {
    assert(m_graph.find(vertexNum) == m_graph.end());

    set<int> s;

    m_graph[vertexNum] = s;
>>>>>>> myRepos/master
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

<<<<<<< HEAD
void Graph::removeVertexAndIsolatedNeighbour(int vertex) {

    set<int> neigh = m_graph[vertex];
    for (set<int>::iterator ii = neigh.begin(); ii != neigh.end(); ++ii) {
        m_graph[*ii].erase(vertex);
        if(m_graph[*ii].empty()) {
        	m_graph.erase(*ii);
        	cout << "Removed isolated neighbor. Graph size is : " << getVertexCount() << endl;
        }
    }

    m_graph.erase(vertex);
    cout << "Removed VC node. Graph size is : " << getVertexCount() << endl;
}

bool Graph::hasEdge(int vertex1, int vertex2) {
	return m_graph[vertex1].find(vertex2) != m_graph[vertex1].end();
=======
bool Graph::hasEdge(int vertex1, int vertex2) {

    return m_graph[vertex1].find(vertex2) != m_graph[vertex1].end();
>>>>>>> myRepos/master
}

bool Graph::hasPath(int vertex1, int vertex2, int precedentVertex) {

<<<<<<< HEAD

=======
>>>>>>> myRepos/master
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
<<<<<<< HEAD

	return m_graph[vertex];
=======
    return m_graph[vertex];
}

list<int> Graph::getNeighboursList(int vertex) {

    list<int> list;
    for (set<int>::iterator it = m_graph[vertex].begin(); it != m_graph[vertex].end(); ++it)
        list.push_front(*it);

    return list;
>>>>>>> myRepos/master
}

set<int> Graph::getVertices() {

    set<int> vertices;
<<<<<<< HEAD
    map<int, set<int> >::const_iterator it;
    for (it = m_graph.begin(); it!= m_graph.end(); ++it)
    	vertices.insert((*it).first);
    	
=======
    std::map<int, std::set<int> >::iterator it;

    for (it = m_graph.begin(); it != m_graph.end(); it++) {
        vertices.insert(it->first);
    }

>>>>>>> myRepos/master
    return vertices;
}

int Graph::getVertexCount() {
<<<<<<< HEAD
    return m_graph.size();
=======
    return m_vertexCount;
>>>>>>> myRepos/master
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


