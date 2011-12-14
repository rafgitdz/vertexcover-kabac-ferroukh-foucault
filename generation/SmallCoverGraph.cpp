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
 * Goal : Build a SimpleGraph containing a vertex cover					       *
 *____________________________________________________________________________*/

#include "SmallCoverGraph.h"
#include <cstdlib>

using namespace std;

/*
 * Generates a SimpleGraph containing a vertex cover
 * Parameters:	vertexCount - number of vertices in the graph
 * 			   	edgeProba - probability of drawing an edge between
 * 			   				two vertices
 * 			   	coverSize - size of the vertex cover to be generated
 * Complexity:	SimpleGraph complexity +
 * 				O(|cs| + |n-cs|*log(n-cs) + |n-cs|*|cs|*log(n)) where
 * 					cs - size of the vertex cover
 */
SmallCoverGraph::SmallCoverGraph(unsigned vertexCount, float edgeProba,
		unsigned coverSize) :
		SimpleGraph(coverSize, edgeProba) {

	/*
	 * Recuperates the vertices in the vertex cover
	 * O(cs) where
	 * 		cs - size of the vertex cover
	 */
	verticesInVC = getVertices();

	/*
	 * Adds vertices which are out of the vertex cover
	 * O(|n-cs|*log(n-cs))
	 * 		cs - size of the vertex cover
	 */
	for (unsigned i = 0; i < (vertexCount - coverSize); i++)
		verticesOutOfVC.insert(addVertex());

	/*
	 * Adds an edge between a vertex in the vertex cover
	 * and a vertex out of the vertex cover
	 *  O(|n-cs|*|cs|*log(n))
	 * 		cs - size of the vertex cover
	 */
	set<int>::iterator it1;
	set<int>::iterator it2;
	for (it1 = verticesOutOfVC.begin(); it1 != verticesOutOfVC.end(); it1++)
		for (it2 = verticesInVC.begin(); it2 != verticesInVC.end(); it2++) {
			if (rand() % 100 < probability)
				addEdge(*it1, *it2);
		}
}
