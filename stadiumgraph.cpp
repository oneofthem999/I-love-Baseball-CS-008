#include <fstream>
#include "stadiumgraph.h"

StadiumGraph::StadiumGraph()
{
    vertices = new Stadium[NUMOFSTADIUMS];
    ifstream sList ("Stadiums");
    if (sList.is_open())
    {
        string line;
        int num;
        bool isGrass;
        for (int i = 0; i < NUMOFSTADIUMS; ++i)
        {
            Stadium vertex;
            getline(sList, line);
            vertex.setStadiumName(line);
            getline(sList, line);
            vertex.setTeamName(line);
            getline(sList, line);
            vertex.setAddress(line);
            getline(sList, line);
            vertex.setPhoneNumber(line);
            getline(sList, line);
            vertex.setDate(line);
            getline(sList, line);
            num = stoi(line);
            vertex.setCapacity(num);
            getline(sList, line);
            isGrass = vertex.to_bool(line);
            vertex.setGrass(isGrass);
            getline(sList, line);
            getline(sList, line);
            vertices[i] = vertex;
        }
        sList.close();
    }

    adjMatrix = new int*[NUMOFSTADIUMS];
    adjMatrix[0] = new int[NUMOFSTADIUMS] {0, -1, -1, -1, -1, -1, 340, -1, -1, -1, -1, 1500, -1, -1, -1, 340, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1,
        110, -1, -1, -1};
    adjMatrix[1] = new int[NUMOFSTADIUMS] {-1, 0, -1, -1, -1, -1, -1, -1, 90, 210, -1, -1, -1, 240, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
        , -1, -1, -1, 240};
    adjMatrix[2] = new int[NUMOFSTADIUMS] {-1, -1, 0, -1, -1, -1, -1, -1, -1, 430, -1, -1, -1, -1, 195, -1, -1, -1, 195, -1, -1, -1, -1, 1255, -1,
        -1, -1, -1, -1, -1};
    adjMatrix[3] = new int[NUMOFSTADIUMS] {-1, -1, -1, 0, 460, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 870, -1, -1, 650, -1, -1, -1,
        -1, -1, -1, -1, 740, -1};
    adjMatrix[4] = new int[NUMOFSTADIUMS] {-1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, 415, -1, -1, 235, -1, -1, -1, 560, -1, -1, -1, -1
        , -1, -1, -1, -1, 415};
    //
    adjMatrix[5] = new int[NUMOFSTADIUMS] {};
    adjMatrix[21] = new int[NUMOFSTADIUMS] {0, -1, -1, -1, -1, -1, 340, -1, -1, -1, -1, 1500, -1, -1, -1, 340, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1,
        110, -1, -1, -1};
}
