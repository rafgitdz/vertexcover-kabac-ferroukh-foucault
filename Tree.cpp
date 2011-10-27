#include "Tree.h"

using namespace std;

Tree::Tree(int vertexCount) : Graph(vertexCount) {
}

void Tree::constructEdgesTree(int numberOfSons, int vertexCount, int indexOfRoot, int &end, vector<int> &list, vector<int> &list2) {

    for(int j=0; j<numberOfSons; ++j) {
        if(end<vertexCount) {

            int createdVertex = addVertex();
            end++;
            addEdge(list[indexOfRoot], createdVertex);
            list2.push_back(createdVertex);
        }
    }
}

void Tree::updateList(vector<int>& list, vector<int>& list2) {

     list = list2;
     list2.clear();
}

Tree::~Tree() {
}
