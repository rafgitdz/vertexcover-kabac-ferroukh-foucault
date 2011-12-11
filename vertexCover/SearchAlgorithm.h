/*-----------------------------------------------------------------------------*
 *            *Project of Complexity and Applicated Algorithms*                *
 *-----------------------------------------------------------------------------*
 *        Authors :                                                            *
 *                  Milan Kabac (milan.kabac@etu.u-bordeaux1.fr)               *
 *             Matthieu Foucault (matthieu.foucault@etu.u-bordeaux1.fr)        *
 *                 Ferroukh Rafik (rafik.ferroukh@etu.u-bordeaux1.fr)          *
 *-----------------------------------------------------------------------------*
 *              University Bordeaux 1, Software Engineering, Master 2          *
 *                                *2011/2012*                                  *
 * ----------------------------------------------------------------------------*
 * Goal => has a functions that gives different type of research               *
 *      => DEAPTH SEARCH                                                       *
 *      => BREADHT SEARCH                                                      *
 *                                                                             *
 * It's a class that is used by the Algorithms classes to get some             *
 * course in the graph.                                                        *
 * Parameters => none                                                          *
 * Include => class Graph that enable inherits all methods and use them         *
 *----------------------------------------------------------------------------*/

#ifndef SEARCHALGORITHM_H
#define	SEARCHALGORITHM_H

class Graph;
#include <list>
#include <set>

#define WHITE 1
#define BLACK 2
#define GREY  3
#define NULLE -1

class SearchAlgorithm {
public:

    SearchAlgorithm();
    virtual ~SearchAlgorithm();

    std::set<int> breadthFirstSearch(Graph g, int root, int target);
    std::list<int> breadthFirstSearchWithoutLeaves(Graph g, int root);
    void depthFirstSearch(Graph g, Graph &tree, int vertex);
    std::list<int> getImprovingPath(Graph g, int root, int target);
    int pi(int vertex);

private:
    void setPi(int vertex, int father);
    int color(int vertex);
    void setColor(int vertex, int color);
    int numVertexSearch(int vertex);
    void setNumVertexSearch(int vertex, int num);

    struct vertexInfo {
        int vertexNumSearch;
        int father;
        int color;
    };
    Graph graph;
    std::list<int> m_queue;
    std::set<int> m_markedVertices;
    std::map<int, vertexInfo> m_numColorVertex;
};

#endif	/* SEARCHALGORITHM_H */

