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
 * Goal => Create a tree graph
 * Parameters => the number of vertices that the graph will have and the number
 * of sons for each vertex
 * Description => Create a tree graph with a static number of sons for each
 * vertex of the vertexCount vertices
 */

#include "TreeStaticSons.h"

using namespace std;

TreeStaticSons::TreeStaticSons(int vertexCnt, int numOfSons) : Tree() {

    // init the data
    _vertexCount = vertexCnt;
    _numberOfSons = numOfSons;
    vector<int> verticesToHaveSons(0);
    vector<int> newVerticesToHaveSons(0);

    _root = addVertex();
    verticesToHaveSons.push_back(_root); // create the root and save it
    int end = 1;

    while (end < _vertexCount) {
        /* control the limit of the vertices to create */
        for (unsigned int i = 0; i < verticesToHaveSons.size(); ++i)
            /* link the number of sons with the root "i" and
             * build the edges between them */
            buildEdgesTree(_numberOfSons, _vertexCount, i, end, verticesToHaveSons
                , newVerticesToHaveSons);

        /* put the vertices that don't has again a sons, the list of fixed 
         vertices */
        updateList(verticesToHaveSons, newVerticesToHaveSons);
    }
}// end of TreeStaticSons constructor

TreeStaticSons::~TreeStaticSons() {
}

