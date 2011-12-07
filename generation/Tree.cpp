/*    *Project of Complexity and Applicated Algorithms*
 * 
 * Authors : 
 *      Milan Kabac (milan.kabac@etu.u-bordeaux1.fr)
 *      Matthieu Foucault (matthieu.foucault@etu.u-bordeaux1.fr)
 *      Ferroukh Rafik (rafik.ferroukh@etu.u-bordeaux1.fr)
 * 
 *   University Bordeaux 1, Software Engineering, Master 2
 *                      *2011/2012*
 * --------------------------------------------------------------
 * Goal : Create a tree graph
 * Parameters : the number of vertex that the graph will have
 * Is a parent class for TreeDynamicSons and TreeStaticDynamics 
 * Has a methods to be used by the childs class
 */

#include "Tree.h"

using namespace std;

Tree::Tree(int vertexCount) : Graph(vertexCount) {
}

/*
 * Method => constructEdgesTree
 * Goal => create edges between the root and sons given
 * Description => "numberOfSons" is the number of vertex to create 
 * and to link with the root founded in the "listRoot" with index => 
 * "indexOfRoot", without exceed the limit that is "vertexCount" and it's 
 * controled by the "end" integer, each son that was created, it's stocked in 
 * the "fixedVertices"
 */
void Tree::buildEdgesTree(int numberOfSons, int vertexCount, int indexOfRoot
        , int &end, vector<int> &listRoot, vector<int> &fixedVertices) {

    for (int j = 0; j < numberOfSons; ++j) {

        if (end < vertexCount) {

            int createdVertex = addVertex();
            end++;
            addEdge(listRoot[indexOfRoot], createdVertex);
            fixedVertices.push_back(createdVertex);
        }
    }
}

/*
 * Method => updateList
 * Goal => put the vertices that were fixed in the graph, in the list 
 * of the future roots to be handled
 * Description => none
 */
void Tree::updateList(vector<int>& newRoots, vector<int>& markedVertices) {
    newRoots = markedVertices;
    markedVertices.clear();
}

Tree::~Tree() {
}

