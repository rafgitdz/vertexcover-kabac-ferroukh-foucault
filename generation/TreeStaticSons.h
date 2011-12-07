
#ifndef TREE_STATIC_SONS_H
#define	TREE_STATIC_SONS_H

#include "Tree.h"

class TreeStaticSons : public Tree {
public:
	TreeStaticSons(int VertexCount, int numOfSons);
	virtual ~TreeStaticSons();

private:
        int vertexCount;
	int numberOfSons;
};

#endif /* TREE_STATIC_SONS_H_ */
