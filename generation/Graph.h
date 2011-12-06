
#ifndef GRAPH_H_
#define GRAPH_H_

#include <map>
#include <set>
#include <iostream>
#include <cstdlib>
#include <list>

class Graph {
public:
    Graph(int vertexCount = 0);
    virtual ~Graph();
    int addVertex();
    void addVertex(int vertexNum);
    virtual void addEdge(int, int);
    void removeVertex(int);
    void removeVertexAndIsolatedNeighbour(int);

    void removeEdge(int, int);
    bool hasEdge(int, int);
    inline const std::set<int>& getNeighbours(int vertex) { return m_graph[vertex]; }
    std::list<int> getNeighboursList(int vertex);
    int getVertexDegree(int vertex);

    std::set<int> getVertices();
    int getVertexCount();

    bool isCover(std::set<int> cover);

    std::map<int, std::set<int> >::const_iterator getBeginGraph();
    std::map<int, std::set<int> >::const_iterator getEndGraph();
    friend std::ostream &operator<<(std::ostream &out, const Graph&);

protected:
    std::map<int, std::set<int> > m_graph;

};

std::ostream &operator<<(std::ostream &out, const Graph&);


#endif /* GRAPH_H_ */
