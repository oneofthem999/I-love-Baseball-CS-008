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

        //std::vector<int> minDistance(int costs[], bool isInSet[], int size);
        //std::vector<std::vector<int>> adjacentVertices(std::vector<int> vert);

        void printPath(vector<int> path) const;
        //int* dijkstra(int source);
        vector<int> tpMajorLeagues();
        vector<int> tpNationalLeagues();
        vector<int> tpAmericanLeagues();
        bool isValidPath(vector<int> path);
        int pathDistance(vector<int> path);
    private:
        int **adjMatrix;
        int **minimumDistances;
        Stadium *vertices;
};

#endif // STADIUMGRAPH_H
