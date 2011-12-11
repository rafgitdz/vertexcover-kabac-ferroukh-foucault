/*-----------------------------------------------------------------------------*
 *               *Project of Complexity and Applicated Algorithms*             *
 *-----------------------------------------------------------------------------*
 *        Authors :                                                            *
 *                  Milan Kabac (milan.kabac@etu.u-bordeaux1.fr)               *
 *             Matthieu Foucault (matthieu.foucault@etu.u-bordeaux1.fr)        *
 *                 Ferroukh Rafik (rafik.ferroukh@etu.u-bordeaux1.fr)          *
 *-----------------------------------------------------------------------------*
 *              University Bordeaux 1, Software Engineering, Master 2          *
 *                                *2011/2012*                                  *
 * ----------------------------------------------------------------------------*
 * Goal => has a functions that gives different type of research               *
 *      => DEAPTH SEARCH                                                       *
 *      => BREADHT SEARCH                                                      *
 *                                                                             *
 * It's a class that is used by the Algorithms classes to get a set or a list  *
 * course in the graph.                                                        *
 * Parameters => none                                                          *
 *----------------------------------------------------------------------------*/

#include "../generation/Graph.h"
#include "SearchAlgorithm.h"

using namespace std;

SearchAlgorithm::SearchAlgorithm() : m_queue(), m_markedVertices() {
}

/* Get the breadth search of the graph given as enter, we launch from root and
   stop at the target (if different of -1) */
set<int> SearchAlgorithm::breadthFirstSearch(Graph graph, int root, int target) {

    // init data
    m_queue.clear();
    int numOrderSearch = 0;
    int head;
    set<int> searchedVertices;
    set<int> vertices = graph.getVertices();

    /* Init all vertices that they haven't any father and the color to white 
       that indicate that the vertex hasn't not yet been treated in the search 
     */
    for (set<int>::iterator ii = vertices.begin(); ii != vertices.end(); ++ii) {
        setPi(*ii, NULLE);
        setColor(*ii, WHITE);
    }

    /* GREY indicates that the vertex is visited but it hasn't yet been 
     * fixed in the search */
    setColor(root, GREY);
    m_queue.push_back(root); // push the vertex that wasn't fix

    while (m_queue.size() > 0) {

        head = *(m_queue.begin()); // get the first "GREY" vertex
        m_queue.pop_front();

        // BLACK means that the vertex is inserted in the search and is treated
        setColor(head, BLACK);
        // set the order number in the search of the new BLACK vertex 
        setNumVertexSearch(head, numOrderSearch);
        // insert the BLACK vertex in the set of the searched vertices
        searchedVertices.insert(head);
        ++numOrderSearch;

        // if it attempt the target, it leaves the algorithm
        // if target == -1, it executes normally
        if (target == head) break; // attempt the target
        // get all the neighbours of the new BLACK vertex
        vertices = graph.getNeighbours(head);

        /* stock all the none-visited vertex (WHITE) for the new BLACK vertex,
         * to be treated. */
        for (set<int>::iterator ii = vertices.begin(); ii != vertices.end(); ++ii) {
            /*  if the vertex hasn't a white color, it means that the vertex is 
                already treated */
            if (color(*ii) == WHITE) {
                setColor(*ii, GREY);
                setPi(*ii, head); // set the father for the none-visited vertex
                m_queue.push_back(*ii);
            }
        }
    }
    return searchedVertices;
} // end of the breadhtFirstSearch (graph, root, target)

/* Get the depth search of the graph given as enter, we launch from root and
 * build a tree at the same time */
void SearchAlgorithm::depthFirstSearch(Graph graph, Graph &tree, int root) {

	m_queue.clear();
    // init data
    int numOrderSearch = 0;
    int head;
    list<int> searchedVertices; // the list of the depth search order
    set<int> vertices = graph.getVertices();

    /* Init all vertices that they haven't any father and the color to white 
     * that indicate that the vertex hasn't not yet been treated in the search 
     */
    for (set<int>::iterator ii = vertices.begin(); ii != vertices.end(); ++ii) {
        setPi(*ii, NULLE);
        setColor(*ii, WHITE);
    }

    /* GREY indicates that the vertex is visited but it hasn't yet been 
     * fixed in the search */
    setColor(root, GREY);
    /* push at the front, it's the difference in comparison with the breadht 
     * search, where we put at the back */
    m_queue.push_front(root);
    // add the root vertex to the tree
    tree.addVertex(root);

    while (m_queue.size() > 0) {

        head = *(m_queue.begin()); // get the first "GREY" vertex
        m_queue.pop_front();

        // BLACK means that the vertex is inserted in the search and is treated
        setColor(head, BLACK);
        // set the order number in the search of the new BLACK vertex 
        setNumVertexSearch(head, numOrderSearch);
        ++numOrderSearch;
        // insert the BLACK vertex in the set of the searched vertices
        searchedVertices.push_back(head);

        /* the root can't have a parent, we should avoid this case by comparing
         * the new BLACK vertex and the root variable, after, we add an edge 
         * between new BLACK vertex and his parent to build a tree in a 
         * depth way */
        if (head != root) {
            tree.addVertex(head);
            tree.addEdge(head, pi(head));
        }
        // get all the neighbours of the new BLACK vertex
        set<int> verticesList = graph.getNeighbours(head);
        /* sotck all the none-visited vertex (WHITE) for the new BLACK vertex, 
         * to be treated. */
        for (set<int>::iterator ii = verticesList.begin(); ii != verticesList.end(); ++ii) {
            if (color(*ii) == WHITE) {


                setColor(*ii, GREY);
                setPi(*ii, head);// set the father for the none-visited vertex
                m_queue.push_front(*ii);
            } else if (color(*ii) == GREY) {
            	setPi(*ii, head);
            	m_queue.remove(*ii);
            	m_queue.push_front(*ii);
            }

        }
    }
}// end of the depthFirstSearch (graph, &tree, root)

list<int> SearchAlgorithm::getImprovingPath(Graph graph, int root, int target) {

    breadthFirstSearch(graph, root, target);
    list<int> path;
    if (pi(target) == -1)
        return path;
    int vertex = target;
    path.push_front(vertex);
    while (path.front() != root) {
        vertex = pi(vertex);
        path.push_front(vertex);
    }
    return path;
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
        if ((graph.getVertexDegree(head) > 1) ||
                (root == head))
            searchedVertices.push_back(head);
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

