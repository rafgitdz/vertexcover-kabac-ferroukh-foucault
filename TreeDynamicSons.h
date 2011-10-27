/* 
 * File:   Tree4.h
 * Author: Rafik
 *
 * Created on 25 octobre 2011, 19:08
 */

#ifndef TREE_DYNAMIC_SONS_AND_ROOTS_H_
#define	TREE_DYNAMIC_SONS_AND_ROOTS_H_

#include "TreeSpecial.h"
#include <vector>

class TreeDynamicSonsAndRoots : public TreeSpecial {
public:
    TreeDynamicSonsAndRoots(int VertexCount);
    virtual ~TreeDynamicSonsAndRoots();

private:
    int vertexCount;

};

#endif	/* TREE_DYNAMIC_SONS_AND_ROOTS_H_ */

