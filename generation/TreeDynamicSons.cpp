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
 * Goal => Create a tree graph                                                 *
 * Parameters => the number of vertex that the graph will have                 *
 * Description => Create a tree graph with a dynamic number of sons for each   *
 * vertex of the vertexCount vertices                                          *
 *____________________________________________________________________________*/

#include "TreeDynamicSons.h"
#include <cstdlib>

using namespace std;

// Constructor that build the tree with a dynamic number of sons 

TreeDynamicSons::TreeDynamicSons(int vertexCnt, int maxSons, int minSons) : Tree() {

    // init the data
    m_vertexCount = vertexCnt;
    m_maxSons = maxSons;
    m_minSons = minSons;

    int numberOfSons = 0;
    vector<int> verticesToHaveSons(0);
    vector<int> newVerticesToHaveSons(0);

    m_root = addVertex();
    verticesToHaveSons.push_back(m_root); // create the root and save it

    int limitCreateVertices = 1;

    while (limitCreateVertices < m_vertexCount) {
        // control the limit of the vertices to create
        for (unsigned int i = 0; i < verticesToHaveSons.size(); ++i) {

            /* get a dynamic number of sons, between min and max, to link with 
             * the root "i" and build the edges between them */
            numberOfSons = m_minSons + (rand() % (m_maxSons - m_minSons));
            buildEdgesTree(numberOfSons, m_vertexCount, i, limitCreateVertices,
                    verticesToHaveSons, newVerticesToHaveSons);
        }
        /* put the vertices that don't has again a sons, the list of fixed 
         vertices */
        updateList(verticesToHaveSons, newVerticesToHaveSons);
    }
} // end of TreeDynamicsSons constructor

TreeDynamicSons::~TreeDynamicSons() {
}

