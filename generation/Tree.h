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
    // Complexity => Constant
    Tree(int vertexCount = 0);

    virtual ~Tree() {
    };

    inline const int getRoot() {
        return m_root;
    };

    inline void setRoot(int root) {
        m_root = root;
    };

protected:
    int m_vertexCountTree;
    int m_root;
};

#endif	/* TREE_H */
