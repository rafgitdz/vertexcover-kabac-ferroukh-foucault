/*-----------------------------------------------------------------------------*
 *            *Project of Complexity and Applied Algorithmic*                  *
 *-----------------------------------------------------------------------------*
 *        Authors :                                                            *
 *                  Milan Kabac (milan.kabac@etu.u-bordeaux1.fr)               *
 *             Matthieu Foucault (matthieu.foucault@etu.u-bordeaux1.fr)        *
 *                 Ferroukh Rafik (rafik.ferroukh@etu.u-bordeaux1.fr)          *
 *-----------------------------------------------------------------------------*
 *              University Bordeaux 1, Software Engineering, Master 2          *
 *                                *2011/2012*                                  *
 * ----------------------------------------------------------------------------*
 * Goal => Create a tree graph                                                 *
 * Parameters => the number of vertex that the graph will have                 *
 * Include => It's a Tree, inherit the class Tree and uses all its methods     *
 *____________________________________________________________________________*/

#ifndef TREE_DYNAMIC_SONS_H_
#define	TREE_DYNAMIC_SONS_H_

#include "Tree.h"
#include <vector>

class TreeDynamicSons : public Tree {
public:
    TreeDynamicSons(int VertexCount);
    virtual ~TreeDynamicSons();

private:
    int _vertexCount;
};

#endif	/* TREE_DYNAMIC_SONS_H_ */
