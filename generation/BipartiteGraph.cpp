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
 * Goal : Represents a bipartite graph                                         *
 * Constructor Parameters : the number of vertices that the graph will have,   *
 * the probability to draw an edge between two vertices,                       *
 * the ratio between the size of the two parts of the graph                    *
 *____________________________________________________________________________*/
#include "BipartiteGraph.h"
#include <cstdlib>

using namespace std;

BipartiteGraph::BipartiteGraph(const BipartiteGraph &bGraph) :
		Graph(bGraph), m_leftPart(), m_rightPart() {
	m_leftPart = bGraph.getLeftPart();
	m_rightPart = bGraph.getRightPart();
}

/*
 * Constructor
 * Parameters : the size of the graph, the probability to draw an edge
 * between two vertices, the ratio between the parts of the graph
 * Complexity : O(n²log(n))
 */
BipartiteGraph::BipartiteGraph(int graphSize, float edgeProba, float partRatio) :
		Graph(), m_leftPart(), m_rightPart() {

	int leftPartSize = graphSize * partRatio;
	int rightPartSize = graphSize - leftPartSize;
	/*
	 * We add the vertices of the first part in the graph
	 */
	for (int i = 0; i < leftPartSize; ++i) {
		m_leftPart.insert(addVertex());
	}

	/*
	 * We add the vertices of the second part
	 */
	for (int i = 0; i < rightPartSize; ++i) {

		int vertex = addVertex();
		m_rightPart.insert(vertex);
		/*
		 * And check if we have to draw an edge between the current vertex,
		 * and the vertices of the fist part
		 */
		for (set<int>::iterator jj = m_leftPart.begin(); jj != m_leftPart.end();
				++jj) {
			if (rand() % 100 < edgeProba * 100) {
				addEdge(vertex, *jj);
			}
		}
	}
}

