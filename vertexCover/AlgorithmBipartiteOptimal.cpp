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
 * Goal : Gets the optimal cover of a bipartite graph				    	   *
 *____________________________________________________________________________*/
#include "AlgorithmBipartiteOptimal.h"
#include "SearchAlgorithm.h"

using namespace std;

/*
 * To get the cover of a bipartite graph, we use an algorithm based on
 * the max flow and min cut, of an oriented graph where all the vertices
 * of the first part are connected to the source, and all the vertices of
 * the second part are connected to the target
 * Complexity : a bit less than the generation of a random bipartite graph,
 * because we already know which edges to add,
 * but basically O(nlog(n)+n²log(n))
 */
AlgorithmBipartiteOptimal::AlgorithmBipartiteOptimal(
		const BipartiteGraph &graph) :
		m_graph(graph), m_flowGraph(), m_search() {

	m_graph.trim();
	set<int> vertices = m_graph.getVertices();
	/*
	 * we add to the flow graph the vertices of the bipartite graph
	 */
	for (set<int>::const_iterator ii = vertices.begin(); ii != vertices.end();
			++ii) {
		m_flowGraph.addVertex(*ii);
	}

	/*
	 * plus a source and a target vertices
	 */
	m_sourceVertex = m_flowGraph.addVertex();
	m_targetVertex = m_flowGraph.addVertex();

	/*
	 * We add an edge between the source vertex and each vertex of the first part
	 */
	for (set<int>::const_iterator ii = m_graph.getLeftPart().begin();
			ii != m_graph.getLeftPart().end(); ++ii) {
		m_flowGraph.addEdge(m_sourceVertex, *ii);
	}

	/*
	 * We add an edge between each vertex of the second part and the target vertex
	 */
	for (set<int>::const_iterator ii = m_graph.getRightPart().begin();
			ii != m_graph.getRightPart().end(); ++ii) {
		m_flowGraph.addEdge(*ii, m_targetVertex);

		/*
		 *  we copy the edges of the bipartite graph, but only
		 *  oriented from the first part to the second
		 */
		for (set<int>::const_iterator jj = m_graph.getNeighbours(*ii).begin();
				jj != m_graph.getNeighbours(*ii).end(); ++jj) {
			m_flowGraph.addEdge(*jj, *ii);
		}
	}

}


/*
 * Returns an optimal cover for the bipartite graph
 */
set<int> AlgorithmBipartiteOptimal::getCover() {
	/*
	 * well, we build the max flow...
	 */
	buildMaxFlow();

	/*
	 * And a last breadth search to get the min cut
	 */
	set<int> S = m_search.breadthFirstSearch(m_flowGraph, m_sourceVertex,
			m_targetVertex);

	set<int> cover;

	/*
	 * We add to the cover the vertices of
	 * the right part that are in the ensemble S
	 */
	for (set<int>::const_iterator ii = S.begin(); ii != S.end(); ++ii) {
		if (m_graph.getRightPart().find(*ii) != m_graph.getRightPart().end())
			cover.insert(*ii);
	}

	/*
	 * Rather than creating the T ensemble, we just add in the vertex cover
	 * the vertices of the left part that aren't in S
	 */
	for (set<int>::const_iterator ii = m_graph.getLeftPart().begin();
			ii != m_graph.getLeftPart().end(); ++ii)
		if (S.find(*ii) == S.end())
			cover.insert(*ii);

	return cover;
}

void AlgorithmBipartiteOptimal::buildMaxFlow() {
	list<int> improvingPath;
	// tant qu'on trouve un chemin améliorant
	for (improvingPath = m_search.getImprovingPath(m_flowGraph, m_sourceVertex,
			m_targetVertex);
			improvingPath.size() > 0;
			improvingPath = m_search.getImprovingPath(m_flowGraph,
					m_sourceVertex, m_targetVertex))

		/*
		 * on remplit/vide les aretes par lequelles on est passé,
		 * en inversant les aretes du graphe
		 */

		while (improvingPath.size() > 1) {
			int src = improvingPath.front();
			improvingPath.pop_front();
			int dest = improvingPath.front();
			m_flowGraph.reverseEdge(src, dest);
		}

}

