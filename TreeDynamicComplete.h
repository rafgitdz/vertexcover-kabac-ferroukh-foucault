
#ifndef TREE_DYNAMIC_COMPLETE_H_
#define TREE_DYNAMIC_COMPLETE_H_

#include "Tree.h"

class TreeDynamicComplete : public Tree {
public:
	TreeDynamicComplete(int VertexCount);
	virtual ~TreeDynamicComplete();

	void createTree();
	bool verifyExistPathFromAlltoAll();

private :
//	int vertexCount;

};

#endif /* TREE_DYNAMIC_COMPLETE_H_ */
