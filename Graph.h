
#ifndef GRAPH_H_
#define GRAPH_H_

#include <map>
#include <set>
#include <iostream>
<<<<<<< HEAD
#include <cstdlib>
#include <ctime>
=======

#include <cstdlib>
#include <ctime>
#include <list>
>>>>>>> myRepos/master

class Graph {
public:
    Graph(int vertexCount = 0);
    virtual ~Graph();
    int addVertex();
    void addVertex(int vertexNum);
    void addEdge(int, int);
    void removeVertex(int);
<<<<<<< HEAD
    void removeVertexAndIsolatedNeighbour(int);
=======
>>>>>>> myRepos/master
    void removeEdge(int, int);
    bool hasEdge(int, int);
    bool hasPath(int, int, int);
    std::set<int> getNeighbours(int vertex);
<<<<<<< HEAD
=======
    std::list<int> getNeighboursList(int vertex);
>>>>>>> myRepos/master
    std::set<int> getVertices();
    int getVertexCount();
    std::map<int, std::set<int> >::const_iterator getBeginGraph();
    std::map<int, std::set<int> >::const_iterator getEndGraph();
    friend std::ostream &operator<<(std::ostream &out, const Graph&);

protected:
    std::map<int, std::set<int> > m_graph;
<<<<<<< HEAD
=======
    int m_vertexCount;
>>>>>>> myRepos/master
};

std::ostream &operator<<(std::ostream &out, const Graph&);

<<<<<<< HEAD
=======

>>>>>>> myRepos/master
#endif /* GRAPH_H_ */
