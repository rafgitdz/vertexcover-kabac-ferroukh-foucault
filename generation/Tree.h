#ifndef TREE_H
#define	TREE_H

#include "Graph.h"
#include <vector>

class Tree: public Graph {
public:
    Tree(int vertexCount = 0);

    void constructEdgesTree(int numberOfSons, int vertexCount, int indexOfRoot, int &end, std::vector<int> &list, std::vector<int> &list2);
    void updateList(std::vector<int> &list, std::vector<int> &list2);

    virtual ~Tree();
    inline const int getRoot() { return _root; };
    inline void setRoot(int root) { _root = root; };
    
private:
    int _root;
};

#endif	/* TREE_H */
