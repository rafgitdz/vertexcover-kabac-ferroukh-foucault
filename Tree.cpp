#include "Tree.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Tree::Tree(int vertexC) : Graph()  {
	cout << "In construct of the tree... \n \n ";
	vertexCount = vertexC;
}

void Tree::createTree() {

	cout << "In create tree... \n \n";

	srand (time (NULL));

	int randomFirstVertex;
	int randomSecondVertex;



	for(int i=1; i<=vertexCount; i++)
			addVertex(); // Add vertexCount in m_graph

	while(1) {

		randomFirstVertex = rand()%vertexCount+1;
		randomSecondVertex = rand()%vertexCount+1;

		if(randomFirstVertex != randomSecondVertex) {

			if(!hasEdge(randomFirstVertex, randomSecondVertex)) {

				if(!hasPath(randomFirstVertex,randomSecondVertex,0))

					addEdge(randomFirstVertex, randomSecondVertex); // add the edge without risk ;=)

				else return;
			}
		}
	}

}


Tree::~Tree() {

}
