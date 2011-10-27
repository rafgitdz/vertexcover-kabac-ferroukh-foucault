#include "TreeSpecial.h"

using namespace std;

TreeSpecial::TreeSpecial(int vertexCount) : Tree(vertexCount) {
    
}

void TreeSpecial::constructEdgesTree(int numberOfSons, int vertexCount, int indexOfRoot, int &end, vector<int> &list, vector<int> &list2) {

    for(int j=0; j<numberOfSons; ++j) {
        if(end<vertexCount) {
            
            int createdVertex = addVertex();
            end++;
            addEdge(list[indexOfRoot], createdVertex);
            list2.push_back(createdVertex);
        }
    }
}

void TreeSpecial::updateList(vector<int>& list, vector<int>& list2) {
    
     list = list2;
     list2.clear();
}

TreeSpecial::~TreeSpecial() {
}

