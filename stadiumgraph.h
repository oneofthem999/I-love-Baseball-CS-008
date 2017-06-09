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

		int travelingSalesman(int index, vector<int> vertices, vector<int> &backTrack);

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
		double costOfTravel;
};

#endif // STADIUMGRAPH_H
