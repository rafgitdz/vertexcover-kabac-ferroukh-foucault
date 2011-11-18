#include "BipartiteOptimalCover.h"
#include "BipartiteGraph.h"
#include <list>

using namespace std;

BipartiteOptimalCover::BipartiteOptimalCover(BipartiteGraph &graph) : m_flowGraph() {

	for (set<int>::const_iterator ii = graph.getVertices().begin();
			ii != graph.getVertices().end();
			++ii) {
		m_flowGraph.addVertex(*ii);
	}

	/* On construit le graphe orienté à partir du graphe bipartit */
	int sourceVertex = m_flowGraph.addVertex();

	// on construit les aretes entre la source et la premiere partie
	for (list<int>::const_iterator ii = graph.getLeftPart().begin();
			ii != graph.getLeftPart().end();
			++ii) {
		m_flowGraph.addEdge(sourceVertex, *ii);
	}

	int destVertex = m_flowGraph.addVertex();
	// on construit les aretes entre la deuxieme partie et la destination
	for (list<int>::const_iterator ii = graph.getRightPart().begin();
			ii != graph.getRightPart().end();
			++ii) {
		m_flowGraph.addEdge(*ii, destVertex);

		//et on ajoute au passage les aretes entre les deux parties
		for (set<int>::iterator jj = graph.getNeighbours(*ii).begin();
				jj != graph.getNeighbours(*ii).end();
				++jj) {
			m_flowGraph.addEdge(*jj, *ii);
		}
	}

	cout << endl << endl << "Graphe orienté:" << endl << m_flowGraph;
}


