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
#include <vector>

using namespace std;

/* 
 * Constructor that build the tree with a dynamic number of sons 
 * Complexity => O((n-1)*log(n))
 */
TreeDynamicSons::TreeDynamicSons(int vertexCount, int maxSons, int minSons) : Tree(vertexCount) {

    // init the data
    m_maxSons = maxSons;
    m_minSons = minSons;

    int createdVertex;
    int selectedVertexToHaveSons;
    int numberOfSons;
    int limitCreateVertices = 1;
    vector<int> verticesToHaveSons;

    m_root = addVertex();

    // create the root and save it to have sons
    verticesToHaveSons.push_back(m_root);

    // control the limit of the vertices to create
    while (limitCreateVertices < m_vertexCountTree) {

        vector<int> newVerticesToHaveSons;
        for (unsigned int i = 0; i < verticesToHaveSons.size(); ++i) {

            /* get a dynamic number of sons, between min and max, to link with 
             * the root "i" and build the edges between them */
            if (m_maxSons == m_minSons)
                numberOfSons = m_maxSons;
            else
                numberOfSons = m_minSons + (rand() % (m_maxSons - m_minSons));

            selectedVertexToHaveSons = verticesToHaveSons.at(i);

            /* "numberOfSons" is the number of vertex to create 
             * and to link with the selected vertex to have sons */
            for (int j = 0; j < numberOfSons; ++j) {

                createdVertex = addVertex();
                ++limitCreateVertices;
                addEdge(selectedVertexToHaveSons, createdVertex);

                /* control the limit doesn't reachs the number max of 
                 * vertexCover to create */
                if (limitCreateVertices == m_vertexCountTree) return;

                /* add the created vertex in the list of vertices that will have 
                 * sons */
                newVerticesToHaveSons.push_back(createdVertex);
            }
        }
        /* put the vertices that don't has again a sons, the list of fixed 
         * vertices */
        verticesToHaveSons.swap(newVerticesToHaveSons);
    }
} // end of the TreeDynamicsSons constructor
