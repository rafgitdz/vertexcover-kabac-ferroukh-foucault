#include "TreeDynamicSons.h"

using namespace std;

TreeDynamicSonsAndRoots::TreeDynamicSonsAndRoots(int vertexC) : Tree() {
    
    vertexCount = vertexC;
    
    int numberOfSons = 0;
    vector<int> list(0);
    vector<int> list2(0);
    
    list.push_back(addVertex()); // create the root ;)

    int end = 1;

    while (end < vertexCount) {
        for (unsigned int i = 0; i < list.size(); ++i) {
            numberOfSons = rand() % end + 1;
            constructEdgesTree(numberOfSons, vertexCount, i, end, list, list2);
        }
        updateList(list, list2);
    }
}

TreeDynamicSonsAndRoots::~TreeDynamicSonsAndRoots() {
}
