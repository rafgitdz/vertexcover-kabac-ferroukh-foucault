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
     * Complexity => o(vertexCount * moy(numberOfEdgesPerVertex * log(n))
     */
    std::set<int> breadthFirstSearch(const Graph &g, int root, int target);

    /* 
     * Get the depth search of the graph given as enter, we launch from root and
     * build a tree at the same time 
     * Complexity => o(vertexCount * moy(numberOfEdgesPerVertex * log(n))
     */
    std::set<int> depthFirstSearch(const Graph &g, int vertex);

    /*
     * This method provides the breadth first search algorithm for trees.
     * The algorithm ignores the leaves of the tree.
     * Parameters : graph - the graph to look over
     * 				root - the root vertex of the graph
     * Return : the list of found vertices
     * Complexity :	O(n*log(n) + gray(log(n) + n(log(gray) + log(n))) )
     * 					n -	number of vertices in the graph
     * 					gray - number of vertice's marked as gray
     */
    std::list<int> breadthFirstSearchWithoutLeaves(const Graph &g, int root);
    std::list<int> getImprovingPath(const Graph &g, int root, int target);

    /*
     * Returns the parent of the vertex passed by parameter.
     * Parameters : vertex - the vertex whose parent we need
     * Return : the parent of the vertex
     * Complexity : O(log(n)) where
     *			 		n -	number of vertices in the graph
     */
    int pi(int vertex);

private:
    /*
     * Sets the parent of the vertex passed by parameter.
     * Parameters : vertex - the vertex whose parent we need to set
     * 				fath - the parent of the vertex
     * Complexity : O(log(n)) where
     *			 		n -	number of vertices in the graph
     *
     */
    void setPi(int vertex, int father);
    int color(int vertex);

    /*
     * Sets the color of the vertex passed by parameter
     * Complexity : O(log(n)) where
     * 					n -	number of vertices in the graph
     */
    void setColor(int vertex, int color);

    struct vertexInfo {
        int father;
        int color;
    };
    std::list<int> m_queue;
    std::map<int, vertexInfo> m_numColorVertex;
};

#endif	/* SEARCHALGORITHM_H */

