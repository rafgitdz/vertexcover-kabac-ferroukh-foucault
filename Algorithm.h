/*
 * Algorithm.h
 *
 *  Created on: 27 oct. 2011
 *      Author: rferrouk
 */

#ifndef ALGORITHM_H_
#define ALGORITHM_H_

class Algorithm {
public:
	Algorithm(Graph graph);
	virtual ~Algorithm();

	virtual std::set<int> getCover() = 0;

private :
	Graph graph;
};

#endif /* ALGORITHM_H_ */
