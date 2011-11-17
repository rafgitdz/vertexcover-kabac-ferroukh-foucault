
<<<<<<< HEAD
#ifndef TREE_STATIC_SONS_AND_ROOTS_H
#define	TREE_STATIC_SONS_AND_ROOTS_H

#include "Tree.h"

class TreeStaticSonsAndRoots : public Tree {
public:
	TreeStaticSonsAndRoots(int VertexCount, int numOfSons);
	virtual ~TreeStaticSonsAndRoots();
=======
#ifndef TREE_STATIC_SONS_H
#define	TREE_STATIC_SONS_H

#include "Tree.h"

class TreeStaticSons : public Tree {
public:
	TreeStaticSons(int VertexCount, int numOfSons);
	virtual ~TreeStaticSons();
>>>>>>> myRepos/master

private:
        int vertexCount;
	int numberOfSons;
};

<<<<<<< HEAD
#endif /* TREESTATICSONSANSROOTS_H_ */
=======
#endif /* TREE_STATIC_SONS_H_ */
>>>>>>> myRepos/master
