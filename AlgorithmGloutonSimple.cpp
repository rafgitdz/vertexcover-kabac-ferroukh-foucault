/*
 * AlgorithmGloutonSimple.cpp
 *
 *  Created on: 18 nov. 2011
 *      Author: milan
 */

#include "AlgorithmGloutonSimple.h"

using namespace std;

AlgorithmGloutonSimple::AlgorithmGloutonSimple(Graph graph) : AlgorithmGlouton(graph){
}

AlgorithmGloutonSimple::~AlgorithmGloutonSimple() {
	// TODO Auto-generated destructor stub
}

void AlgorithmGloutonSimple::findMinimalVertexCover() {
	removeIsolatedVertices();
	map<int, set<int> >::const_iterator it;
	multimap<int, int>::const_iterator it1;

	for(it = m_graph.getBeginGraph(); it != m_graph.getEndGraph(); it++)
		vertexDegree.insert(pair<int,int>((it->second).size(),it->first));

	/*
	it1 = vertexDegree.end();

	do{
		it1--;
		cout << it1->first << " , " << it1->second << endl;
	}while(it1 != vertexDegree.begin());
	*/

	it1 = vertexDegree.end();
	do{
		it1--;
		vertexCover_.insert(it1->second);
		cout <<"Inserted the vertex " << it1->second << " into the VC set" << endl;
		m_graph.removeVertexAndIsolatedNeighbour(it1->second);
	} while((m_graph.getVertexCount() > 0) && (it1 != vertexDegree.begin()));

	cout << "The found vertex cover has size : " << vertexCover_.size() << endl
						<< "Vertex cover : ";
	for(set<int>::iterator it = vertexCover_.begin(); it != vertexCover_.end(); it++)
		cout << *it << ", ";
	cout << endl << endl;
}
