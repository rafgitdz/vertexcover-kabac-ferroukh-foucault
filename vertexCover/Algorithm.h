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
 * Goal => Applicate an algorithm on a different type of graph to have a cover *
 * of it                                                                       *
 * It's a parent class for all the others types of algorithms (childs class)   *
 * Parameters => the graph to handle and passes to the childs                  *
 * Include => class Graph, to enable inherits all methods and use them         *
 *----------------------------------------------------------------------------*/

#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include "../generation/Graph.h"

class Algorithm {
public:

    /*
     * Get a graph from the sons class, trim it (to erase all the lonely 
     * vertices
     */
    Algorithm(const Graph& graph) : m_graph(graph) {
        m_graph.trim();
    }

    virtual ~Algorithm() {
    };

protected:
    Graph m_graph;
};

#endif /* ALGORITHM_H_ */
