
#include "TreeStaticSons.h"

using namespace std;

TreeStaticSons::TreeStaticSons(int vertexC, int numOfSons) : Tree() {
    vertexCount = vertexC;
    numberOfSons = numOfSons;
    
    vector<int> list(0);
    vector<int> list2(0);

    list.push_back(addVertex()); // create the root ;)

    int end = 1;

    while (end < vertexCount) {
        for (unsigned int i = 0; i < list.size(); ++i)
            constructEdgesTree(numberOfSons, vertexCount, i, end, list, list2);
        
        updateList(list, list2);
    }
}

TreeStaticSons::~TreeStaticSons() {
}

