/*    *Project of Complexity and Applicated Algorithms*
 * 
 * Authors : 
 *      Milan Kabac (milan.kabac@etu.u-bordeaux1.fr)
 *      Matthieu Foucault (matthieu.foucault@etu.u-bordeaux1.fr)
 *      Ferroukh Rafik (rafik.ferroukh@etu.u-bordeaux1.fr)
 * 
 *     University Bordeaux 1, Software Engineering, Master 2
 *                       *2011/2012*
 * --------------------------------------------------------------
 * Goal => Create a tree graph
 * Parameters => the number of vertices that the graph will have and the number
 * of sons for each vertex
 * Include : It's a Tree, inherit the class Tree and uses all its the methods
 */

#ifndef TREE_STATIC_SONS_H
#define	TREE_STATIC_SONS_H

#include "Tree.h"

class TreeStaticSons : public Tree {
public:
	TreeStaticSons(int VertexCount, int numOfSons);
	virtual ~TreeStaticSons();

private:
        int _vertexCount;
	int _numberOfSons;
};

#endif /* TREE_STATIC_SONS_H_ */
