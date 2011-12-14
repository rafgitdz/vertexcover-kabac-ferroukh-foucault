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
 * Include => class Graph that enable inherits all methods and use them        *
 *----------------------------------------------------------------------------*/

#ifndef SEARCHALGORITHM_H
#define	SEARCHALGORITHM_H

class Graph;
#include <list>
#include <set>

// the constants for the state of a visited vertex in depth and breadht search
#define WHITE 1
#define BLACK 2
#define GREY  3
#define NULLE -1

class SearchAlgorithm {
public:

    SearchAlgorithm() : m_queue() {
    }

    virtual ~SearchAlgorithm() {
    };

    /*
     * Get the breadth search of the graph given as enter, we launch from root 
     * and stop at the target (if different of -1) 
     */
    std::set<int> breadthFirstSearch(const Graph &g, int root, int target);

    /* 
     * Get the depth search of the graph given as enter, we launch from root and
     * build a tree at the same time 
     */
    void depthFirstSearch(const Graph &g, Graph &tree, int vertex);

    std::list<int> breadthFirstSearchWithoutLeaves(const Graph &g, int root);
    std::list<int> getImprovingPath(const Graph &g, int root, int target);
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
    std::list<int> m_queue;
    std::map<int, vertexInfo> m_numColorVertex;
};

#endif	/* SEARCHALGORITHM_H */

