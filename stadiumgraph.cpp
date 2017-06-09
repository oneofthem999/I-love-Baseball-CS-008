#include <fstream>
#include <iostream>
#include "stadiumgraph.h"
#include <string>

bool isInVector(vector<int> vert, int num);
void swap (int *x, int *y);
vector<vector<int> > permute(int *a, int i, int n);
vector<int> copy_array_to_vector(int *a, int size);

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
            //num = stoi(line);
            stringstream convert(line);
            convert>>num;

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
    adjMatrix[5] = new int[NUMOFSTADIUMS] {-1, -1, -1, 230, -1, -1, -1, -1, -1, -1, -1, -1, 790, -1, -1, -1, 680, 1115, -1, -1, -1, -1, -1, 965,
        -1, -1, -1, -1, -1, -1};
    adjMatrix[6] = new int[NUMOFSTADIUMS] {340, -1, -1, -1, -1, -1, -1, -1, -1, -1, 680, -1, -1, -1, -1, 0, -1, 650, -1, -1, -1, 340, -1, -1, -1, -1,
        -1, -1, -1, -1};
    adjMatrix[7] = new int[NUMOFSTADIUMS] {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 90, -1, -1, -1, 930, -1, 0, -1
        , 195, 560, -1};
    adjMatrix[8] = new int[NUMOFSTADIUMS] {-1, 90, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 225, -1, -1, -1, -1,
        115, -1, -1};
    adjMatrix[9] = new int[NUMOFSTADIUMS] {-1, 210, 430, -1, -1, -1, -1, -1, -1, -1, 2070, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 430,
        -1, -1, 225, -1, -1};
    adjMatrix[10] = new int[NUMOFSTADIUMS] {-1, -1, -1, -1, -1, -1, 680, -1, -1, 2070, -1, 1390, -1, -1, -1, 680, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
        , -1, -1, -1, -1};
    adjMatrix[11] = new int[NUMOFSTADIUMS] {1500, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1390, -1, -1, -1, -1, -1, 465, -1, -1, -1, -1, 1500, -1, -1, 300
        , -1, -1, -1, -1, -1};
    adjMatrix[12] = new int[NUMOFSTADIUMS] {-1, -1, -1, -1, -1, 790, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 790, 210, -1,
        -1, -1, -1, -1, -1};
    adjMatrix[13] = new int[NUMOFSTADIUMS] {-1, 240, -1, -1, 415, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 250, -1, 80, -1
        , -1, -1, -1, 0};
    adjMatrix[14] = new int[NUMOFSTADIUMS] {-1, -1, 195, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 80, -1, -1, -1, -1, -1, -1, -1,
        315, -1, -1};
    adjMatrix[15] = new int[NUMOFSTADIUMS] {340, -1, -1, -1, -1, -1, 0, -1, -1, -1, 680, -1, -1, -1, -1, -1, -1, 650, -1, -1, -1, 340, -1, -1, -1, -1,
        -1, -1, -1, -1};
    adjMatrix[16] = new int[NUMOFSTADIUMS] {-1, -1, -1, -1, 235, 680, -1, -1, -1, -1, -1, 465, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 310, -1, -1, -1,
        -1, -1, -1, -1};
    adjMatrix[17] = new int[NUMOFSTADIUMS] {-1, -1, -1, 870, -1, 1115, 650, -1, -1, -1, -1, -1, -1, -1, -1, 650, -1, -1, -1, -1, 580, -1, -1, -1, -1, -1
        , 300, -1, -1, -1};
    adjMatrix[18] = new int[NUMOFSTADIUMS] {-1, -1, 195, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, 80, -1, -1, -1, -1, -1, -1, -1,
        315, -1, -1};
    adjMatrix[19] = new int[NUMOFSTADIUMS] {-1, -1, -1, -1, -1, -1, -1, 90, -1, -1, -1, -1, -1, -1, 80, -1, -1, -1, 80, -1, -1, -1, -1, -1, -1, 90,
        -1, -1, -1, -1};
    adjMatrix[20] = new int[NUMOFSTADIUMS] {-1, -1, -1, 650, 560, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 580, -1, -1, -1, -1, -1, -1, -1, -1
        , 830, -1, -1, -1};
    adjMatrix[21] = new int[NUMOFSTADIUMS] {0, -1, -1, -1, -1, -1, 340, -1, -1, -1, -1, 1500, -1, -1, -1, 340, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1,
        110, -1, -1, -1};
    adjMatrix[22] = new int[NUMOFSTADIUMS] {-1, -1, -1, -1, -1, -1, -1, -1, 225, -1, -1, -1, 790, 250, -1, -1, 310, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, 260, 375, 250};
    adjMatrix[23] = new int[NUMOFSTADIUMS] {-1, -1, 1255, -1, -1, 965, -1, 930, -1, -1, -1, -1, 210, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 930,
        -1, -1, 600, -1};
    adjMatrix[24] = new int[NUMOFSTADIUMS] {-1, -1, -1, -1, -1, -1, -1, -1, -1, 430, -1, 300, -1, 80, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
        , -1, -1, 80};
    adjMatrix[25] = new int[NUMOFSTADIUMS] {-1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 90, -1, -1, -1, 930, -1, -1, -1
        , 195, 560, -1};
    adjMatrix[26] = new int[NUMOFSTADIUMS] {110, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 300, -1, -1, 830, 110, -1, -1, -1, -1,
        -1, -1, -1, -1};
    adjMatrix[27] = new int[NUMOFSTADIUMS] {-1, -1, -1, -1, -1, -1, -1, 195, 115, 225, -1, -1, -1, -1, 315, -1, -1, -1, 315, -1, -1, -1, 260, -1, -1, 195,
        -1, -1, -1, -1};
    adjMatrix[28] = new int[NUMOFSTADIUMS] {-1, -1, -1, 740, -1, -1, -1, 560, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 375, 600, -1, 560,
        -1, -1, -1, -1};
    adjMatrix[29] = new int[NUMOFSTADIUMS] {-1, 240, -1, -1, 415, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, 250, -1, 80, -1
        , -1, -1, -1, -1};
}

//bool isInVector(vector<int> vert, int num)
//{
//    for (int i = 0; i < vert.size(); ++i)
//    {
//        if (vert[i] == num)
//            return true;
//    }
//    return false;
//}

void swap (int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

vector<vector<int> > permute(int *a, int i, int n)
{
    int j, counter = 0;
    static vector<vector<int> > vect;
    if (i == n)
    {
        vect.push_back(copy_array_to_vector(a, n + 1));
    }
    else
    {
        for (j = i; j <= n; j++)
        {
            swap((a + i), (a + j));
            permute(a, i + 1, n);
            swap((a + i), (a + j));
        }
    }
    return vect;
}

vector<int> copy_array_to_vector(int *a, int size)
{
    vector<int> vect;
    for (int i = 0; i < size; ++i)
        vect.push_back(a[i]);
    return vect;
}


//int* StadiumGraph::dijkstra(int source)
//{
//    int costs[NUMOFSTADIUMS];
//    int parent[NUMOFSTADIUMS];
//    bool isInSet[NUMOFSTADIUMS];

//    costs[source] = 0;
//    parent[source] = -1;

//    for (int i = 0; i < NUMOFSTADIUMS; ++i)
//        isInSet[i] = false;
//    isInSet[0] = true;

//    //Find the shortest path.
//    for (int i = 0; i < NUMOFSTADIUMS - 1; ++i)
//    {
//        vector<int> minDistIndex = minDistance(costs, isInSet, NUMOFSTADIUMS);
//        isInSet[minDistIndex[1]] = true;
//        costs[minDistIndex[1]] = costs[minDistIndex[0]] + adjMatrix[minDistIndex[0]][minDistIndex[1]];
//        parent[minDistIndex[1]] = minDistIndex[0];
//    }

//    return costs;
//}

vector<int> StadiumGraph::tpMajorLeagues()
{
    int minDist;
    vector<int> result;
    int *arr = new int[NUMOFSTADIUMS];
    for (int i = 0; i < NUMOFSTADIUMS; ++i)
        arr[i] = i;

    vector<vector<int> > permutations = permute(arr, 0, NUMOFSTADIUMS - 1);
    vector<vector<int> > possiblePaths;

    for (int i = 0; i < permutations.size(); ++i)
    {
        if (isValidPath(permutations[i]))
            possiblePaths.push_back(permutations[i]);
    }

    minDist = pathDistance(possiblePaths[0]);
    result = possiblePaths[0];
    for (int j = 0; j < possiblePaths.size(); ++j)
    {
        if (pathDistance(possiblePaths[j]) < minDist)
        {
            minDist = pathDistance(possiblePaths[j]);
            result = possiblePaths[j];
        }
    }

    printPath(result);
    return result;
}

vector<int> StadiumGraph::tpNationalLeagues()
{
    int minDist;
    vector<int> result;

    int numOfNationalStadiums = 0;
    for (int i = 0; i < NUMOFSTADIUMS; ++i)
    {
        if (vertices[i].getNationalLeague())
            numOfNationalStadiums++;
    }

    int *arr = new int[numOfNationalStadiums];
    for (int i = 0; i < NUMOFSTADIUMS; ++i)
    {
        if (vertices[i].getNationalLeague())
            arr[i] = i;
    }

    vector<vector<int> > permutations = permute(arr, 0, numOfNationalStadiums - 1);
    vector<vector<int> > possiblePaths;

    for (int i = 0; i < permutations.size(); ++i)
    {
        if (isValidPath(permutations[i]))
            possiblePaths.push_back(permutations[i]);
    }

    minDist = pathDistance(possiblePaths[0]);
    result = possiblePaths[0];
    for (int j = 0; j < possiblePaths.size(); ++j)
    {
        if (pathDistance(possiblePaths[j]) < minDist)
        {
            minDist = pathDistance(possiblePaths[j]);
            result = possiblePaths[j];
        }
    }

    printPath(result);
    return result;
}

vector<int> StadiumGraph::tpAmericanLeagues()
{
    int minDist;
    vector<int> result;

    int numOfAmericanStadiums = 0;
    for (int i = 0; i < NUMOFSTADIUMS; ++i)
    {
        if (!vertices[i].getNationalLeague())
            numOfAmericanStadiums++;
    }

    int *arr = new int[numOfAmericanStadiums];
    for (int i = 0; i < NUMOFSTADIUMS; ++i)
    {
        if (!vertices[i].getNationalLeague())
            arr[i] = i;
    }

    vector<vector<int> > permutations = permute(arr, 0, numOfAmericanStadiums - 1);
    vector<vector<int> > possiblePaths;

    for (int i = 0; i < permutations.size(); ++i)
    {
        if (isValidPath(permutations[i]))
            possiblePaths.push_back(permutations[i]);
    }

    minDist = pathDistance(possiblePaths[0]);
    result = possiblePaths[0];
    for (int j = 0; j < possiblePaths.size(); ++j)
    {
        if (pathDistance(possiblePaths[j]) < minDist)
        {
            minDist = pathDistance(possiblePaths[j]);
            result = possiblePaths[j];
        }
    }

    printPath(result);
    return result;
}

bool StadiumGraph::isValidPath(vector<int> path)
{
    for (int i = 0; i < path.size() - 1; ++i)
    {
        if (adjMatrix[path[i]][path[i + 1]] == -1)
            return false;
    }
    if (adjMatrix[path.size() - 1][0] == -1)
        return false;

    return true;
}

int StadiumGraph::pathDistance(vector<int> path)
{
    int distance = 0;
    for (int i = 0; i < path.size() - 1; ++i)
    {
        distance += adjMatrix[path[i]][path[i + 1]];
    }
    distance += adjMatrix[path.size() - 1][0];
    return distance;
}

void StadiumGraph::printPath(vector<int> path) const
{
    for (int i = 0; i < path.size() - 1; ++i)
        cout << vertices[path[i]].getStadiumName() << " to " << vertices[path[i + 1]].getStadiumName() << endl;
    cout << vertices[path[path.size() - 1]].getStadiumName() << " to " << vertices[path[0]].getStadiumName() << endl;
}

/*vector<vector<int>> StadiumGraph::adjacentVertices(vector<int> vert)
{
    vector<vector<int>> result;
    for (int i = 0; i < vert.size(); ++i)
    {
        for (int j = 0; j < NUMOFSTADIUMS; ++j)
        {
            if (adjMatrix[vert[i]][j] != -1 && !isInVector(vert, j))
            {
                vector<int> v;
                v.push_back(vert[i]);
                v.push_back(j);
                result.push_back(v);
            }
        }
    }
    return result;
}

vector<int> StadiumGraph::minDistance(int costs[], bool isInSet[], int size)
{
    //Initialize starting values.
    int min = 0;
    vector<int> vert, min_index;
    vector<vector<int>> adjVert;
    for (int i = 0; i < size; ++i)
    {
        if (isInSet[i])
            vert.push_back(i);
    }

    //Get adjacent vertices
    adjVert = adjacentVertices(vert);
    min = costs[adjVert[0][0]] + adjMatrix[adjVert[0][0]][adjVert[0][1]];

    //Find minimum value from adjacent vertices
    for (int i = 0; i < adjVert.size(); ++i)
    {
        if (costs[adjVert[i][0]] + adjMatrix[adjVert[i][0]][adjVert[i][1]] <= min)
        {
            min = costs[adjVert[i][0]] + adjMatrix[adjVert[i][0]][adjVert[i][1]];
            min_index = adjVert[i];
        }
    }

    return min_index;
}*/
