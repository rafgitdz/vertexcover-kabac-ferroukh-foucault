#ifndef TREE_DYNAMIC_SONS_H_
#define	TREE_DYNAMIC_SONS_H_


#include "Tree.h"
#include <vector>


class TreeDynamicSons : public Tree{
public:
    TreeDynamicSons(int VertexCount);
    virtual ~TreeDynamicSons();


private:
    int vertexCount;

};


#endif	/* TREE_DYNAMIC_SONS_H_ */
