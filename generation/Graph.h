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
 * Goal : Represents a graph as an adjacent list, which is a STL map where we  *
 * have the number of a vertex as the key, 				       *
 * and a set of his neighbors as the value      			       *
 * Parameters : the number of vertices that the graph will have                *
 * It's a parent class for all classes representing a graph                    *
 *____________________________________________________________________________*/

#ifndef GRAPH_H_
#define GRAPH_H_

#include <map>
#include <set>
#include <iostream>
#include <list>

class Graph {

public:
	/*
	 * Constructor
	 * Complexity : TODO
	 */
	Graph(int vertexCount = 0);

	/*
	 * Copy constructor
	 * Complexity : TODO
	 */
	Graph(const Graph&);
	virtual ~Graph() {
	}
	;

	/*
	 * Load a graph from a graphTextFile
	 */
	Graph(char* pathFile);

	/*
	 * Complexity : logarithmic in the graph size
	 */
	int addVertex();

	/*
	 * Complexity : logarithmic in the graph size
	 */
	void addVertex(int vertexNum);

	/*
	 * Complexity : logarithmic in the graph size, plus logarithmic
	 * in the number of neighbors of each endpoint of the edge
	 */
	virtual void addEdge(int, int);

	/*
	 * Complexity : logarithmic in the graph size
	 */
	void removeVertexAndIsolatedNeighbour(int);
	void removeVertex(int);
	/*
	 * Removes the vertices which degree is 0
	 * i.e. the ones which have no neighbor,
	 * and therefore no interest for the vertex cover
	 * Complexity : n * log(n)
	 */
	void trim();

	/*
	 * Removes the edge with the endpoints given in parameter
	 * Complexity : TODO
	 */
	void removeEdge(int, int);

	/*
	 * Return the neighbors of a vertex
	 * Complexity : Logarithmic in the size of the graph
	 */
	inline const std::set<int>& getNeighbours(int vertex) const {
		return m_graph.find(vertex)->second;
	}

	/*
	 * Return the degree of a vertex
	 * Complexity : Logarithmic in the size of the graph
	 */
	int getVertexDegree(int vertex) const {
		return m_graph.find(vertex)->second.size();
	}

	/*
	 * Returns the vertices of the graph
	 * Complexity : linear in the graph size
	 */
	std::set<int> getVertices() const;

	/*
	 * Return the number of vertices in the graph
	 * Complexity : Constant
	 */
	inline int getVertexCount() const {
		return m_graph.size();
	}

	/*
	 * Checks if the set of vertices passed in parameter
	 * covers all the edges of the graph
	 * Complexity : TODO
	 */
	bool isCover(std::set<int> cover) const;

	/*
	 * Return an iterator to the first vertex of the graph
	 * Complexity : constant
	 */
	std::map<int, std::set<int> >::const_iterator getBeginGraph() const {
		return m_graph.begin();
	}

	/*
	 * Return an iterator to the end of the graph
	 * Complexity: constant
	 */
	std::map<int, std::set<int> >::const_iterator getEndGraph() const {
		return m_graph.end();
	}

	/*
	 * Returns the number of edges in the graph
	 * Complexity : Constant
	 */
	const int& getEdgeCount() const {
		return m_edgeCount;
	}

	void saveGraph(char* pathFile) const;

	friend std::ostream &operator<<(std::ostream &out, const Graph&);

protected:
	std::map<int, std::set<int> > m_graph;
	int m_vertexCount;
	int m_edgeCount;
	int m_graphInitialSize;
};

#endif /* GRAPH_H_ */
