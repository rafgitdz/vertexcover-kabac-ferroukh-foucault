
#ifndef TREE_STATIC_SONS_AND_ROOTS_H
#define	TREE_STATIC_SONS_AND_ROOTS_H

#include "TreeSpecial.h"

class TreeStaticSonsAndRoots : public TreeSpecial {
public:
	TreeStaticSonsAndRoots(int VertexCount, int numOfSons);
	virtual ~TreeStaticSonsAndRoots();

private:
        int vertexCount;
	int numberOfSons;
};

#endif /* TREESTATICSONSANSROOTS_H_ */
