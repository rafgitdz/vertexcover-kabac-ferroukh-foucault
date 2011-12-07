/* 
 * File:   Tree4.h
 * Author: Rafik
 *
 * Created on 25 octobre 2011, 19:08
 */

#ifndef TREE_DYNAMIC_SONS_H_
#define	TREE_DYNAMIC_SONS_H_

#include "Tree.h"
#include <vector>

class TreeDynamicSons : public Tree{
public:
    TreeDynamicSons(int VertexCount);
    virtual ~TreeDynamicSons();
    
    int getRoot();

private:
    int vertexCount;
    int root;

};

#endif	/* TREE_DYNAMIC_SONS_H_ */

