#include <iostream>
#include "SmallCoverGraph.h"

using namespace std;

SmallCoverGraph::SmallCoverGraph(int vertexCount, float edgeProba, unsigned int coverSize): SimpleGraph(vertexCount, edgeProba) {
	std::map<int,std::set<int> > tmp_graph = getGraph();
	std::map<int,std::set<int> >::iterator it;

	int position(0);
	unsigned int maxDegree(0);

	/* removing isolated vertices from the graph */
	for(it = tmp_graph.begin(); it != tmp_graph.end(); it++){
		if((it->second).empty())
			tmp_graph.erase(it->first);
	}

	/*
	  	removing vertices from the graph choosing always the vertex with
	 	the highest degree;
	 	this vertex is written to the vertexCover set
		when removing a vertex the program removes the reference from the
	 	adjacent lists of the left vertices;
	 	the program stops when there are no more vertices in the graph
	 */

	while(tmp_graph.size() > 0) {
		for(it = tmp_graph.begin(); it != tmp_graph.end(); it++){
			if (maxDegree < ((it->second).size())) {
				maxDegree = ((it->second).size());
				position = it->first;
			}
		}
		vertexCover.insert(position);

		set<int> neigh = tmp_graph[position];
		for(set<int>::iterator ii= neigh.begin(); ii != neigh.end(); ++ii) {
			tmp_graph[*ii].erase(position);
			if(tmp_graph[*ii].empty())
				tmp_graph.erase(*ii);
		}
		tmp_graph.erase(position);
		maxDegree = 0;
	}

	if(vertexCover.size() > coverSize) {
		cout << "This graph doesn't have a vertex cover of size : " << coverSize << " !"
		<< endl << "The found vertex cover has size : " << vertexCover.size() << endl
		<< "Vertex cover : ";
		for(set<int>::iterator it = vertexCover.begin(); it != vertexCover.end(); it++)
			cout << *it << ", ";
		cout << endl << endl;
	}
}

SmallCoverGraph::~SmallCoverGraph() {
	// TODO Auto-generated destructor stub
}
