/*
 * AlgorithmGlouton.cpp
 *
 *  Created on: 6 nov. 2011
 *      Author: milan
 */

#include "AlgorithmGlouton.h"

using namespace std;

AlgorithmGlouton::AlgorithmGlouton(Graph graph) : Algorithm(graph) {

	graph_ = graph;

	/* removing isolated vertices from the graph */
	removeIsolatedVertices();
	cout << "Removed the isolated vertices" << endl;

	/* removing vertices from the graph choosing always the vertex with
	 * the highest degree;
	 * this vertex is written to the vertexCover set
	 * when removing a vertex the program removes the reference from the
	 * adjacent lists of the left vertices;
	 * the program stops when there are no more vertices in the graph
	 */

	while(graph_.getVertexCount() > 0) {
		graph_.removeVertexAndIsolatedNeighbour(addEdgeToVC());
	}

	cout << "The found vertex cover has size : " << vertexCover_.size() << endl
				<< "Vertex cover : ";
	for(set<int>::iterator it = vertexCover_.begin(); it != vertexCover_.end(); it++)
		cout << *it << ", ";
	cout << endl << endl;
}

AlgorithmGlouton::~AlgorithmGlouton() {
	// TODO Auto-generated destructor stub
}

void AlgorithmGlouton::removeIsolatedVertices() {
	std::map<int,std::set<int> >::const_iterator it;
	for(it = graph_.getBeginGraph(); it != graph_.getEndGraph(); it++)
		if((it->second).empty())
			graph_.removeVertex(it->first);
}

int AlgorithmGlouton::addEdgeToVC() {
	int vertexPosition(0);
	unsigned int maxDegree(0);

	std::map<int,std::set<int> >::const_iterator it;
	for(it = graph_.getBeginGraph(); it != graph_.getEndGraph(); it++){
		if (maxDegree < ((it->second).size())) {
			maxDegree = ((it->second).size());
			vertexPosition = it->first;
		}
	}
	vertexCover_.insert(vertexPosition);
	cout <<"Inserted the vertex " << vertexPosition << " into the VC set" << endl;

	return vertexPosition;
}

