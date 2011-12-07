
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
    Graph(const Graph&);
    virtual ~Graph();
    int addVertex();
    void addVertex(int vertexNum);
    virtual void addEdge(int, int);
    void removeVertex(int);
    void removeVertexAndIsolatedNeighbour(int);
    void trim();
    void removeEdge(int, int);
    inline bool hasEdge(int v1, int v2) const {return m_graph.find(v1)->second.find(v2) != m_graph.find(v1)->second.end();}
    inline const std::set<int>& getNeighbours(int vertex) const { return m_graph.find(vertex)->second; }
    std::list<int> getNeighboursList(int vertex);
    int getVertexDegree(int vertex);

    std::set<int> getVertices() const;
    inline int getVertexCount() const { return m_graph.size(); }

    bool isCover(std::set<int> cover);

    std::map<int, std::set<int> >::const_iterator getBeginGraph();
    std::map<int, std::set<int> >::const_iterator getEndGraph();
    friend std::ostream &operator<<(std::ostream &out, const Graph&);

protected:
    std::map<int, std::set<int> > m_graph;

};

std::ostream &operator<<(std::ostream &out, const Graph&);


#endif /* GRAPH_H_ */
