#ifndef STADIUMGRAPH_H
#define STADIUMGRAPH_H

#include <vector>
#include "stadiumslist.h"
#include "stadium.h"

class StadiumGraph
{
    public:
        StadiumGraph();
        ~StadiumGraph();

        std::vector<int> minDistance(int costs[], bool isInSet[], int size);
        std::vector<std::vector<int>> adjacentVertices(std::vector<int> vert);

        //void printResult(int costs[], int parent[], int indexOfVertice) const;
        //void printPath(int parent[], int indexOfVertice) const;
        int* dijkstra(int source);
    private:
        int **adjMatrix;
        int **minimumDistances;
        Stadium *vertices;
        StadiumsList theList;
};

#endif // STADIUMGRAPH_H
