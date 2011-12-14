/*-----------------------------------------------------------------------------*
 *               *Project of Complexity and Applied Algorithmic*               *
 *-----------------------------------------------------------------------------*
 *        Authors :                                                            *
 *                  Milan Kabac (milan.kabac@etu.u-bordeaux1.fr)               *
 *             Matthieu Foucault (matthieu.foucault@etu.u-bordeaux1.fr)        *
 *                 Rafik Ferroukh (rafik.ferroukh@etu.u-bordeaux1.fr)          *
 *-----------------------------------------------------------------------------*
 *              University Bordeaux 1, Software Engineering, Master 2          *
 *                                *2011/2012*                                  *
 * ----------------------------------------------------------------------------*
 * Goal : Create a tree graph                                                  *
 * Parameters : the number of vertex that the graph will have                  *
 * It's a parent class for TreeStaticDynamics                                  *
 * It has a methods to be used by the childs class                             *
 *____________________________________________________________________________*/

#include "Tree.h"

using namespace std;

Tree::Tree(int vertexCount) : Graph(vertexCount) {
}

void Tree::buildEdgesTree(int numberOfSons, int vertexCount, int indexOfRoot
        , int &limit, vector<int> &listRoot, vector<int> &fixedVertices) {

    int createdVertex;

    /* 
     * add an edge between the first vertex in the list root and and 
     * a number of sons fixed by numberOfSons
     */
    for (int j = 0; j < numberOfSons; ++j) {

        /* 
         * while the limit doesn't reachs the number max of vertexCover to 
         * create
         */
        if (limit < vertexCount) {

            createdVertex = addVertex();
            limit++;
            addEdge(listRoot[indexOfRoot], createdVertex);
            /* 
             * add the created vertex in the list of vertices that will have 
             * sons
             */
            fixedVertices.push_back(createdVertex);
        }
    }
}

void Tree::updateList(vector<int>& newRoots, vector<int>& markedVertices) {
    /* 
     * refresh the list of the vertices that are fixed by the list that will be 
     * fixed
     */
    newRoots = markedVertices;
    markedVertices.clear();
}
