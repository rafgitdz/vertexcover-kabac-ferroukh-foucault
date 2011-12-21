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
 * Goal : Represents a bipartite graph with a small cover                      *
 *____________________________________________________________________________*/
#include "SmallCoverBipartiteGraph.h"
#include <cstdlib>

using namespace std;

SmallCoverBipartiteGraph::SmallCoverBipartiteGraph(int graphSize,
		float edgeProba, float partRatio, int coverSize, float coverRatio) :
		BipartiteGraph(coverSize, edgeProba, coverRatio) {

	m_vcLeft = getLeftPart();
	m_vcRight = getRightPart();
	int leftPartSize = graphSize * partRatio - m_vcLeft.size();
	int rightPartSize = graphSize - leftPartSize - m_vcRight.size();

	/*
	 * We add the vertices of the first part in the graph
	 */
	for (int i = 0; i < leftPartSize; ++i) {
		int vertex = addVertex();
		m_leftPart.insert(vertex);
		/*
		 * And check if we have to draw an edge between the current vertex,
		 * and the vertices of the second part in the vertex cover
		 */
		for (set<int>::const_iterator ii = m_vcRight.begin();
				ii != m_vcRight.end(); ++ii) {
			if (rand() % 100 < edgeProba * 100)
				addEdge(vertex, *ii);
		}
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
		for (set<int>::iterator jj = m_vcLeft.begin(); jj != m_vcLeft.end();
				++jj) {
			if (rand() % 100 < edgeProba * 100) {
				addEdge(vertex, *jj);
			}
		}
	}
}

