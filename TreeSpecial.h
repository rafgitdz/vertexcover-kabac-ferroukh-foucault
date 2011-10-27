
#ifndef TREESPECIAL_H
#define	TREESPECIAL_H

#include "Tree.h"
#include <vector>

class TreeSpecial: public Tree {
public:
    TreeSpecial(int vertexCount = 0);
    virtual ~TreeSpecial();

    void createRoots(int numbOfRoots, std::vector<int> &list);
    void constructEdgesTree(int numberOfSons, int vertexCount, int indexOfRoot, int &end, std::vector<int> &list, std::vector<int> &list2);
    void addEdgesRoots(int numberOfRoots);
    void updateList(std::vector<int> &list, std::vector<int> &list2);
    
private:

};

#endif	/* TREESPECIAL_H */

