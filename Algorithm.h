
#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include "Graph.h"

class Algorithm {
public:
    Algorithm(Graph graph);
    virtual ~Algorithm();

    std::set<int> getCover(); // abstract class

protected:
    Graph m_graph;
};

#endif /* ALGORITHM_H_ */
