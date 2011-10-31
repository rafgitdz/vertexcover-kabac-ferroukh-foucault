
#ifndef ALGORITHMCOVEREDGES_H_
#define ALGORITHMCOVEREDGES_H_

#include "Algorithm.h"

class AlgorithmCoverEdges : public Algorithm {
public:
    AlgorithmCoverEdges(Graph graph);
    virtual ~AlgorithmCoverEdges();

    std::set<int> getCover();
    std::set<int> getSelectedEdge();
    void eraseCoveredEdges(int coveredVertex);
    bool existsEdges();

private:
    Graph graphTemp;
    std::set<int> verticesToCover;
};

#endif /* ALGORITHMCOVEREDGES_H_ */
