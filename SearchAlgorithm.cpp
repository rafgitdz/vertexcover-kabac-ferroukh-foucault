
#include "Graph.h"
#include "SearchAlgorithm.h"
using namespace std;

SearchAlgorithm::SearchAlgorithm() {
}

list<int> SearchAlgorithm::breadhtFirstSearch(Graph graph, int root, int target) {

    int k = 0;
    int head;
    list<int> searchedVertices;

    set<int> vertices = graph.getVertices();

    for (set<int>::iterator ii = vertices.begin(); ii != vertices.end(); ++ii) {
        setPi(*ii, NULLE);
        setColor(*ii, WHITE);
    }

    setColor(root, GREY);
    m_queue.push_back(root);

    while (m_queue.size() > 0) {

        head = *(m_queue.begin());
        m_queue.pop_front();

        setColor(head, BLACK);
        setNumVertexSearch(head, k);
        searchedVertices.push_back(head);
        if (target == head) break; // attempt the target
        ++k;
        vertices = graph.getNeighbours(head);

        for (set<int>::iterator ii = vertices.begin(); ii != vertices.end(); ++ii) {
            if (color(*ii) == WHITE) {
                setColor(*ii, GREY);
                setPi(*ii, head);
                m_queue.push_back(*ii);
            }
        }
    }
    return searchedVertices;
}

list<int> SearchAlgorithm::breadthFirstSearchWithoutLeaves(Graph graph, int root) {

    int k = 0;
    int head;
    list<int> searchedVertices;

    set<int> vertices = graph.getVertices();

    for (set<int>::iterator ii = vertices.begin(); ii != vertices.end(); ++ii) {
        setPi(*ii, NULLE);
        setColor(*ii, WHITE);
    }

    setColor(root, GREY);
    m_queue.push_back(root);

    while (m_queue.size() > 0) {

        head = *(m_queue.begin());
        m_queue.pop_front();

        setColor(head, BLACK);
        setNumVertexSearch(head, k);
        if((graph.getVertexDegree(head) > 1) ||
           (root == head))
        	searchedVertices.push_back(head);
        //if (target == head) break; // attempt the target
        ++k;
        vertices = graph.getNeighbours(head);

        for (set<int>::iterator ii = vertices.begin(); ii != vertices.end(); ++ii) {
            if (color(*ii) == WHITE) {
                setColor(*ii, GREY);
                setPi(*ii, head);
                m_queue.push_back(*ii);
            }
        }
    }
    return searchedVertices;
}

void SearchAlgorithm::depthFirstSearch(Graph graph, Graph &tree, int vertex) {

    m_markedVertices.insert(vertex);
    set<int> neighbours = graph.getNeighbours(vertex);

    for (set<int>::iterator ii = neighbours.begin(); ii != neighbours.end(); ii++) {

        if (m_markedVertices.find(*ii) == m_markedVertices.end()) {
            tree.addVertex(*ii);
            tree.addEdge(vertex, *ii);
            depthFirstSearch(graph, tree, *ii);
        }
    }
}

list<int> SearchAlgorithm::depthFirstSearch(Graph graph, int root) {

    int k = 0;
    int head;
    list<int> searchedVertices;

    set<int> vertices = graph.getVertices();

    for (set<int>::iterator ii = vertices.begin(); ii != vertices.end(); ++ii) {
        setPi(*ii, NULLE);
        setColor(*ii, WHITE);
    }

    setColor(root, GREY);
    m_queue.push_front(root);

    while (m_queue.size() > 0) {

        head = *(m_queue.begin());
        m_queue.pop_front();

        searchedVertices.push_back(head);
        setColor(head, BLACK);
        setNumVertexSearch(head, k);
        ++k;
        list<int> verticesList = graph.getNeighboursList(head);

        for (list<int>::iterator ii = verticesList.begin(); ii != verticesList.end(); ++ii) {
            if (color(*ii) == WHITE) {
                setColor(*ii, GREY);
                setPi(*ii, head);
                m_queue.push_front(*ii);
            }
        }
    }
    return searchedVertices;
}

bool SearchAlgorithm::exist(list<int> l, int vertex) {

    for (list<int>::iterator jj = l.begin(); jj != l.end(); ++jj) {
        if (*jj == vertex) return true;
    }
    return false;
}

int SearchAlgorithm::pi(int vertex) {
    return m_numColorVertex[vertex].father;
}

void SearchAlgorithm::setPi(int vertex, int fath) {
    m_numColorVertex[vertex].father = fath;
}

int SearchAlgorithm::color(int vertex) {
    return m_numColorVertex[vertex].color;
}

void SearchAlgorithm::setColor(int vertex, int col) {
    m_numColorVertex[vertex].color = col;
}

int SearchAlgorithm::numVertexSearch(int vertex) {
    return m_numColorVertex[vertex].vertexNumSearch;
}

void SearchAlgorithm::setNumVertexSearch(int vertex, int num) {
    m_numColorVertex[vertex].vertexNumSearch = num;
}

SearchAlgorithm::~SearchAlgorithm() {
}

