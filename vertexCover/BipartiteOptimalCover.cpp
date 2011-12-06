#include "BipartiteOptimalCover.h"
#include "SearchAlgorithm.h"
#include <list>
#include <cassert>

using namespace std;

BipartiteOptimalCover::BipartiteOptimalCover(BipartiteGraph &graph) : m_flowGraph(), m_S(), m_T(), m_search(){

	set<int> vertices = graph.getVertices();
	for (set<int>::const_iterator ii = vertices.begin();
			ii != vertices.end();
			++ii) {
		m_flowGraph.addVertex(*ii);
	}

	/* On construit le graphe orienté à partir du graphe bipartit */
	m_sourceVertex = m_flowGraph.addVertex();

	// on construit les aretes entre la source et la premiere partie
	for (set<int>::const_iterator ii = graph.getLeftPart().begin();
			ii != graph.getLeftPart().end();
			++ii) {
		m_flowGraph.addEdge(m_sourceVertex, *ii);
	}

	m_targetVertex = m_flowGraph.addVertex();
	// on construit les aretes entre la deuxieme partie et la destination
	for (set<int>::const_iterator ii = graph.getRightPart().begin();
			ii != graph.getRightPart().end();
			++ii) {
		m_flowGraph.addEdge(*ii, m_targetVertex);

		//et on ajoute au passage les aretes entre les deux parties
		for (set<int>::const_iterator jj = graph.getNeighbours(*ii).begin();
				jj != graph.getNeighbours(*ii).end();
				++jj) {
			m_flowGraph.addEdge(*jj, *ii);
		}
	}

}

set<int> BipartiteOptimalCover::getCover(BipartiteGraph &graph){
	buildMaxFlow();
	cout << "flow built" << endl;
	buildMinCut();

	set<int> cover;
	for (list<int>::const_iterator ii = m_S.begin();
			ii != m_S.end(); ++ii) {
		if (graph.getRightPart().find(*ii) != graph.getRightPart().end())
			cover.insert(*ii);
	}
	for (list<int>::const_iterator ii = m_T.begin();
				ii != m_T.end(); ++ii) {
			if (graph.getLeftPart().find(*ii) != graph.getLeftPart().end())
				cover.insert(*ii);
		}
	return cover;
}

void BipartiteOptimalCover::buildMaxFlow() {
	//list<int> searchResult;
	list<int> improvingPath;
	list<int> searchResult;

	for (searchResult = m_search.breadhtFirstSearch(m_flowGraph,m_sourceVertex,m_targetVertex);
			searchResult.back() == m_targetVertex;
			searchResult = m_search.breadhtFirstSearch(m_flowGraph,m_sourceVertex,m_targetVertex)) {
		cout << "graphe : " << endl << m_flowGraph << endl;
		cout << "on reconstruit le chemin à partir du résultat du parcours en largeur" << endl;

		improvingPath = m_search.getImprovingPath(m_flowGraph, m_sourceVertex, m_targetVertex);

		// on remplit/vide les aretes par lequelles on est passé
		while (improvingPath.size() > 1) {
			int src = improvingPath.front();
			improvingPath.pop_front();
			int dest = improvingPath.front();
			m_flowGraph.reverseEdge(src, dest);
		}
	}
}

void BipartiteOptimalCover::buildMinCut() {
	list<int> searchResult = m_search.breadhtFirstSearch(m_flowGraph, m_sourceVertex, m_targetVertex);
	searchResult.pop_back();
	m_S.push_front(m_targetVertex);
	while (searchResult.size() > 0) {
		cout << "test" << endl;
		int vertex = searchResult.back();
		if (m_flowGraph.hasEdge(searchResult.back(), m_S.front()))
			m_S.push_front(vertex);
		 else
			m_T.push_front(vertex);


		searchResult.pop_back();
	}
	cout << "min cut" << endl;
	for (list<int>::iterator ii = m_S.begin(); ii != m_S.end(); ++ii) {
		cout << *ii << endl;
	}

}

