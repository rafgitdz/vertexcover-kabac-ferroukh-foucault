/*-----------------------------------------------------------------------------*
 *               *Project of Complexity and Applied Algorithmic*               *
 *-----------------------------------------------------------------------------*
 *        Authors :                                                            *
 *                  Milan Kabac (milan.kabac@etu.u-bordeaux1.fr)               *
 *             Matthieu Foucault (matthieu.foucault@etu.u-bordeaux1.fr)        *
 *                 Rafik Ferroukh (rafik.ferroukh@etu.u-bordeaux1.fr)          *
 *-----------------------------------------------------------------------------*
 *              University Bordeaux 1, Software Engineering, Master 2          *
 *                                *2011/2012*                                  *
 * ----------------------------------------------------------------------------*
 * Goal => has a functions that gives different type of research               *
 *      => DEAPTH SEARCH                                                       *
 *      => BREADTH SEARCH                                                      *
 *                                                                             *
 * It's a class that is used by the Algorithms classes to get a set or a list  *
 * course in the graph.                                                        *
 * Parameters => none                                                          *
 *----------------------------------------------------------------------------*/

#include "../generation/Graph.h"
#include "SearchAlgorithm.h"

using namespace std;

// Complexity => O(|E| * log(n))

set<int> SearchAlgorithm::breadthFirstSearch(const Graph &graph, int root,
        int target) {

    // init data
    m_queue.clear();
    int head;
    set<int> searchedVertices;
    set<int> vertices = graph.getVertices(); // o(n*log(n))

    /* Init all vertices that they haven't any father and the color to white
     that indicate that the vertex hasn't not yet been treated in the search
     * Comlexity => o(n)
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
        // insert the BLACK vertex in the set of the searched vertices
        searchedVertices.insert(head);

        // if it attempt the target, it leaves the algorithm
        // if target == -1, it executes normally
        if (target == head)
            break; // attempt the target
        // get all the neighbours of the new BLACK vertex
        vertices = graph.getNeighbours(head);

        /* stock all the none-visited vertex (WHITE) for the new BLACK vertex,
         * to be treated. */
        for (set<int>::iterator ii = vertices.begin(); ii != vertices.end();
                ++ii) {
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

// Complexity => O(|E| * log(n))

set<int> SearchAlgorithm::depthFirstSearch(const Graph &graph, int root) {

    m_queue.clear();
    // init data
    int head;
    set<int> searchedVertices; // the list of the depth search order
    set<int> vertices = graph.getVertices();

    /* Init all vertices that they haven't any father and the color to white
     * that indicate that the vertex hasn't not yet been treated in the search
     */
    for (set<int>::iterator ii = vertices.begin(); ii != vertices.end(); ++ii) {
        setColor(*ii, WHITE);
    }

    /* GREY indicates that the vertex is visited but it hasn't yet been
     * fixed in the search */
    setColor(root, GREY);
    /* push at the front, it's the difference in comparison with the breadth
     * search, where we put at the back */
    m_queue.push_front(root);

    while (m_queue.size() > 0) {

        head = *(m_queue.begin()); // get the first "GREY" vertex
        m_queue.pop_front();

        // BLACK means that the vertex is inserted in the search and is treated
        setColor(head, BLACK);

        // get all the neighbours of the new BLACK vertex
        set<int> vertices = graph.getNeighbours(head);
        /* Stock all the none-visited vertex (WHITE) for the new BLACK vertex,
         * to be treated. */
        bool isLeaf = true;
        for (set<int>::iterator ii = vertices.begin();
                ii != vertices.end(); ++ii) {

            if (color(*ii) == WHITE) {
                setColor(*ii, GREY);
                m_queue.push_front(*ii);
                isLeaf = false;
            } else if (color(*ii) == GREY) {
                m_queue.remove(*ii);
                m_queue.push_front(*ii);
                isLeaf = false;
            }
        }
        if (!isLeaf) {
        	searchedVertices.insert(head);
        }
    }

    return searchedVertices;
} // end of the depthFirstSearch (graph, &tree, root)

list<int> SearchAlgorithm::getImprovingPath(const Graph &graph, int root,
        int target) {
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

/*
 * This method provides the breadth first search algorithm for trees.
 * The algorithm ignores the leaves of the tree.
 * Parameters : graph - the graph to look over
 * 				root - the root vertex of the graph
 * Return : the list of found vertices
 * Complexity :O(|E| * log(n))
 */
list<int> SearchAlgorithm::breadthFirstSearchWithoutLeaves(const Graph &graph,
        int root) {

    int head;
    list<int> searchedVertices;

    // O(n*log(n))
    set<int> vertices = graph.getVertices();

    // O(n)
    for (set<int>::iterator ii = vertices.begin(); ii != vertices.end(); ++ii) {
        // O(log(n))
        setPi(*ii, NULLE);
        // O(log(n))
        setColor(*ii, WHITE);
    }

    // O(log(n))
    setColor(root, GREY);
    m_queue.push_back(root);

    // O(gray)
    while (m_queue.size() > 0) {

        head = *(m_queue.begin());
        m_queue.pop_front();

        // O(log(n))
        setColor(head, BLACK);

        // O(log(n))
        if ((graph.getVertexDegree(head) > 1) || (root == head))
            searchedVertices.push_back(head);
        // O(log(n))
        vertices = graph.getNeighbours(head);

        // O(n)
        for (set<int>::iterator ii = vertices.begin(); ii != vertices.end();
                ++ii) {
            if (color(*ii) == WHITE) {
                // O(log(gray))
                setColor(*ii, GREY);
                // O(log(n))
                setPi(*ii, head);
                m_queue.push_back(*ii);
            }
        }
    }
    return searchedVertices;
}

/*
 * Returns the parent of the vertex passed by parameter.
 * Parameters : vertex - the vertex whose parent we need
 * Return : the parent of the vertex
 * Complexity : O(log(n)) where
 *			 		n -	number of vertices in the graph
 */
int SearchAlgorithm::pi(int vertex) {
    // O(log(n))
    return m_numColorVertex[vertex].father;
}

/*
 * Sets the parent of the vertex passed by parameter.
 * Parameters : vertex - the vertex whose parent we need to set
 * 				fath - the parent of the vertex
 * Complexity : O(log(n)) where
 *			 		n -	number of vertices in the graph
 *
 */
void SearchAlgorithm::setPi(int vertex, int fath) {
    // O(log(n))
    m_numColorVertex[vertex].father = fath;
}

int SearchAlgorithm::color(int vertex) {
    return m_numColorVertex[vertex].color;
}

/*
 * Sets the color of the vertex passed by parameter
 * Complexity : O(log(n)) where
 * 					n -	number of vertices in the graph
 */
void SearchAlgorithm::setColor(int vertex, int col) {
    // O(log(n))
    m_numColorVertex[vertex].color = col;
}
