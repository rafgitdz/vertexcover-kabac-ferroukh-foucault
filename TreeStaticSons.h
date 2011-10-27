
#ifndef TREE_STATIC_SONS_AND_ROOTS_H
#define	TREE_STATIC_SONS_AND_ROOTS_H

#include "Tree.h"

class TreeStaticSonsAndRoots : public Tree {
public:
	TreeStaticSonsAndRoots(int VertexCount, int numOfSons);
	virtual ~TreeStaticSonsAndRoots();

private:
        int vertexCount;
	int numberOfSons;
};

#endif /* TREESTATICSONSANSROOTS_H_ */
