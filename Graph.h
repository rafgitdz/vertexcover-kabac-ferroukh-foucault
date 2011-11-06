
#ifndef GRAPH_H_
#define GRAPH_H_

#include <map>
#include <set>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Graph {
public:
    Graph(int vertexCount = 0);
    virtual ~Graph();
    int addVertex();
    void addVertex(int vertexNum);
    void addEdge(int, int);
    void removeVertex(int);
    void removeVertexAndIsolatedNeighbour(int);
    void removeEdge(int, int);
    bool hasEdge(int, int);
    bool hasPath(int, int, int);
    std::set<int> getNeighbours(int vertex);
    std::set<int> getVertices();
    int getVertexCount();
    std::map<int, std::set<int> >::const_iterator getBeginGraph();
    std::map<int, std::set<int> >::const_iterator getEndGraph();
    friend std::ostream &operator<<(std::ostream &out, const Graph&);

protected:
    std::map<int, std::set<int> > m_graph;
};

std::ostream &operator<<(std::ostream &out, const Graph&);

#endif /* GRAPH_H_ */
