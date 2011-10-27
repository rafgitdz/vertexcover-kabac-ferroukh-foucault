
#include "TreeDynamicComplete.h"

TreeDynamicComplete::TreeDynamicComplete(int vertexCount) : Tree(vertexCount) { 
    
    srand (time (NULL));

    int randomFirstVertex;
    int randomSecondVertex;

    while(1) {

            randomFirstVertex = rand()%m_vertexCount+1;
            randomSecondVertex = rand()%m_vertexCount+1;

            if(randomFirstVertex != randomSecondVertex) {
                            if(!hasPath(randomFirstVertex,randomSecondVertex,0))
                                    addEdge(randomFirstVertex, randomSecondVertex); // add the edge without risk ;=)
            }
            if(verifyExistPathFromAlltoAll()) return;
    }
}

bool TreeDynamicComplete::verifyExistPathFromAlltoAll() {

	srand (time (NULL));
	int random = rand()%m_vertexCount+1;

	for(int i=1; i<=m_vertexCount; i++) {

		if(i!=random) {

			if(!hasPath(random, i, 0))
				return false;
		}
	}
	return true;
}

TreeDynamicComplete::~TreeDynamicComplete() {

}



