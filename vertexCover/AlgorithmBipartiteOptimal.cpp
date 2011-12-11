#include "AlgorithmBipartiteOptimal.h"
#include "SearchAlgorithm.h"

using namespace std;

AlgorithmBipartiteOptimal::AlgorithmBipartiteOptimal(const BipartiteGraph &graph) :
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

	// on crée les aretes entre la source et la premiere partie
	for (set<int>::const_iterator ii = m_graph.getLeftPart().begin();
			ii != m_graph.getLeftPart().end(); ++ii) {
		m_flowGraph.addEdge(m_sourceVertex, *ii);
	}

	// on crée les aretes entre la deuxième partie et la destination
	for (set<int>::const_iterator ii = m_graph.getRightPart().begin();
			ii != m_graph.getRightPart().end(); ++ii) {
		m_flowGraph.addEdge(*ii, m_targetVertex);

		//et on ajoute au passage les aretes entre les deux parties
		for (set<int>::const_iterator jj = m_graph.getNeighbours(*ii).begin();
				jj != m_graph.getNeighbours(*ii).end(); ++jj) {
			m_flowGraph.addEdge(*jj, *ii);
		}
	}

}

set<int> AlgorithmBipartiteOptimal::getCover() {
	// on construit le flot max, en inversant les aretes remplies
	buildMaxFlow();

	//on fait un dernier parcours en profondeur pour en déduire la coupe min
	set<int> S = m_search.breadthFirstSearch(m_flowGraph, m_sourceVertex,
			m_targetVertex);

	set<int> cover;

	/*
	 * On ajoute à la couverture les sommets
	 * de la partie droite qui sont dans T
	 */
	for (set<int>::const_iterator ii = S.begin(); ii != S.end(); ++ii) {
		if (m_graph.getRightPart().find(*ii) != m_graph.getRightPart().end())
			cover.insert(*ii);
	}

	/*
	 * plutot que de créer le sous ensemble T de la coupe min, on se contente
	 * d'ajouter à la couverture les sommets de la partie gauche qui ne sont pas dans S
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

