#ifndef TREE_H_
#define TREE_H_

#include "Graph.h"

class Tree: public Graph {
public:
	Tree();
	Tree(int VertexCount);
	virtual ~Tree();

	void createTree();

private :
	int vertexCount;

};

#endif /* TREE_H_ */
