#ifndef STADIUMGRAPH_H
#define STADIUMGRAPH_H

#include <vector>
#include <map>
#include "stadiumslist.h"
#include "stadium.h"

class StadiumGraph
{
    public:
        StadiumGraph();
        ~StadiumGraph();

		void mincost(int** arr, int size, int city);
		void mincostAmerican(int** arr, int size, int city);
		void mincostNational(int** arr, int size, int city);
		int least(int** arr, int size, int city);
		int leastAmerican(int** arr, int size, int city);
		int leastNational(int** arr, int size, int city);
		int getCostOfTravel() { return costOfTravel; }

		void salesmanMajor();
		void salesmanAmerican();
		void salesmanNational();
    private:
        int **adjMatrix;
		int **adjMatrixNational;
		int **adjMatrixAmerican;
		bool *visited;
		bool *visitedNational;
		bool *visitedAmerican;
        Stadium *vertices;
		int costOfTravel;
};

#endif // STADIUMGRAPH_H
