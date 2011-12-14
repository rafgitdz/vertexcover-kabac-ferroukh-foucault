/*-----------------------------------------------------------------------------*
 *            *Project of Complexity and Applicated Algorithmic*               *
 *-----------------------------------------------------------------------------*
 *        Authors :                                                            *
 *                  Milan Kabac (milan.kabac@etu.u-bordeaux1.fr)               *
 *             Matthieu Foucault (matthieu.foucault@etu.u-bordeaux1.fr)        *
 *                 Ferroukh Rafik (rafik.ferroukh@etu.u-bordeaux1.fr)          *
 *-----------------------------------------------------------------------------*
 *              University Bordeaux 1, Software Engineering, Master 2          *
 *                                *2011/2012*                                  *
 * ----------------------------------------------------------------------------*
 * Goal : Create a tree graph                                                  *
 * Parameters : the number of vertex that the graph will have                  *
 * It's a parent class for TreeDynamicSons and TreeStaticDynamics              *
 * It has a methods to be used by the childs class                             *
 * Include => class Graph, a Tree is a Graph, inherits all methods from Graph  *
 * Include => vector, to handle the object vector and all the methods          *
 *____________________________________________________________________________*/

#ifndef TREE_H
#define	TREE_H

#include "Graph.h"
#include <vector>

class Tree : public Graph {
public:
    // Complexity => o(n*log(n))
    Tree(int vertexCount = 0);

    virtual ~Tree() {
    };

    /*
     * Method => constructEdgesTree
     * Goal => create edges between the root and sons given
     * Description => "numberOfSons" is the number of vertex to create 
     * and to link with the root founded in the "listRoot" with index => 
     * "indexOfRoot", without exceed the limit that is "vertexCount" and it's 
     * controled by the "end" integer, each son that was created, it's stocked 
     * in the "fixedVertices"
     * Complexity = o(numberOfSons * log(n)) 
     */
    void buildEdgesTree(int numberOfSons, int vertexCount, int indexOfRoot,
            int &end, std::vector<int> &list, std::vector<int> &list2);

    /*
     * Method => updateList
     * Goal => put the vertices that were fixed in the graph, in the list 
     * of the future roots to be handled
     * Description => none
     * Complexity => o(n)
     */
    void updateList(std::vector<int> &list, std::vector<int> &list2);

    inline const int getRoot() {
        return m_root;
    };

    inline void setRoot(int root) {
        m_root = root;
    };

protected:
    int m_root;
};

#endif	/* TREE_H */
