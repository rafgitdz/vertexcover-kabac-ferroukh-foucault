/*-----------------------------------------------------------------------------*
 *            *Project of Complexity and Applied Algorithmic*                  *
 *-----------------------------------------------------------------------------*
 *        Authors :                                                            *
 *                  Milan Kabac (milan.kabac@etu.u-bordeaux1.fr)               *
 *             Matthieu Foucault (matthieu.foucault@etu.u-bordeaux1.fr)        *
 *                 Rafik Ferroukh (rafik.ferroukh@etu.u-bordeaux1.fr)          *
 *-----------------------------------------------------------------------------*
 *              University Bordeaux 1, Software Engineering, Master 2          *
 *                                *2011/2012*                                  *
 * ----------------------------------------------------------------------------*
 * Goal : Builds a graph defined by the number of vertices and the			   *
 * 		  probability of an edge between two vertices						   *
 *____________________________________________________________________________*/

#include "SimpleGraph.h"
#include <cstdlib>

using namespace std;

/*
 * Generates a random graph, with vertexCount vertices,
 * and a probability edgeProba to draw and edge between two vertices
 * Parameters:	vertexCount - number of vertices in the graph
 * 			   	edgeProba - probability of drawing an edge between
 * 			   				two vertices
 * Complexity:	O(n*log(n) + n²*log(n)) where
 * 					n - number of vertices in the graph
 */
SimpleGraph::SimpleGraph(int vertexCount, float edgeProba) : Graph() {

    probability = (int) (edgeProba * 100);
    std::map<int, std::set<int> >::iterator ii;

    // O(n)
    for (int i = 0; i < vertexCount; ++i) {
        set<int> neigh;
        int graphSize = m_graph.size() + 1;

        /*
         *  generates randomly a vertex which does not yet exist in the graph
         *	O(log(n))
         */
        int vertex = rand() % (max(m_graphInitialSize, graphSize) * 10);
        while (m_graph.find(vertex) != m_graph.end()) {
            vertex = rand() % (max(m_graphInitialSize, graphSize) * 10);
        }

        /*
         * creates an edge between two vertices in function of the generated
         * probability
         * O(n*log(n))
         */
        for (ii = m_graph.begin(); ii != getEndGraph(); ii++) {
            if (rand() % 100 < probability) {
            	++m_edgeCount;
            	ii->second.insert(vertex);
            	neigh.insert(ii->first);
            }
        }
        m_graph[vertex] = neigh;
    }
}
