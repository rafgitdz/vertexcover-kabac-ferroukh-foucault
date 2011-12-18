/*-----------------------------------------------------------------------------*
 *               *Project of Complexity and Applied Algorithmic*               *
 *-----------------------------------------------------------------------------*
 *        Authors :                                                            *
 *                  Milan Kabac (milan.kabac@etu.u-bordeaux1.fr)               *
 *             Matthieu Foucault (matthieu.foucault@etu.u-bordeaux1.fr)        *
 *                 Rafik Ferroukh (rafik.ferroukh@etu.u-bordeaux1.fr)          *
 *-----------------------------------------------------------------------------*
 *              University Bordeaux 1, Software Engineering, Master 2          *
 *                                *2011/2012*                                  *
 * ----------------------------------------------------------------------------*
 * Goal : Create a tree graph                                                  *
 * Parameters : the number of vertex that the graph will have                  *
 * It's a parent class for TreeStaticDynamics                                  *
 * It has a methods to be used by the childs class                             *
 *____________________________________________________________________________*/

#include "Tree.h"

using namespace std;

// Complexity => Constant
Tree::Tree(int vertexCount) : Graph() {
    m_vertexCountTree = vertexCount;
}
