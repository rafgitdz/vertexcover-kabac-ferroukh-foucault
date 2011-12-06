
#ifndef SEARCHALGORITHM_H
#define	SEARCHALGORITHM_H

class Graph;
#include <list>

#define WHITE 1
#define BLACK 2
#define GREY  3
#define NULLE -1

class SearchAlgorithm {
    
public:
    SearchAlgorithm();
    virtual ~SearchAlgorithm();

    std::list<int> breadhtFirstSearch(Graph g, int root, int target);
    void depthFirstSearch(Graph g, Graph &tree, int vertex);
    std::list<int> depthFirstSearch(Graph g, int vertex);
    std::list<int> getImprovingPath(Graph g, int root, int target);

private:
    int pi(int vertex);
    void setPi(int vertex, int father);
    int color(int vertex);
    void setColor(int vertex, int color);
    int numVertexSearch(int vertex);
    void setNumVertexSearch(int vertex, int num);
    bool exist(std::list<int> l, int v);

    struct vertexInfo {
        int vertexNumSearch;
        int father;
        int color;
    };
    Graph graph;
    std::list<int> m_queue;
    std::list<int> m_stack;
    std::map<int, vertexInfo> m_numColorVertex;
    std::set<int> m_markedVertices;
};

#endif	/* SEARCHALGORITHM_H */

