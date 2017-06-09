#include <iostream>
#include <fstream>
#include <string>
#include "stadiumgraph.h"

using namespace std;

bool isAllTrue(bool *arr, int size);

StadiumGraph::StadiumGraph()
{
	vertices = new Stadium[NUMOFSTADIUMS];
	ifstream sList("Stadiums");
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
	adjMatrix[0] = new int[NUMOFSTADIUMS] {0, 0, 0, 0, 0, 0, 340, 0, 0, 0, 0, 1500, 0, 0, 0, 340, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		110, 0, 0, 0};
	adjMatrix[1] = new int[NUMOFSTADIUMS] {0, 0, 0, 0, 0, 0, 0, 0, 90, 210, 0, 0, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		, 0, 0, 0, 240};
	adjMatrix[2] = new int[NUMOFSTADIUMS] {0, 0, 0, 0, 0, 0, 0, 0, 0, 430, 0, 0, 0, 0, 195, 0, 0, 0, 195, 0, 0, 0, 0, 1255, 0,
		0, 0, 0, 0, 0};
	adjMatrix[3] = new int[NUMOFSTADIUMS] {0, 0, 0, 0, 460, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 870, 0, 0, 650, 0, 0, 0,
		0, 0, 0, 0, 740, 0};
	adjMatrix[4] = new int[NUMOFSTADIUMS] {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 415, 0, 0, 235, 0, 0, 0, 560, 0, 0, 0, 0
		, 0, 0, 0, 0, 415};
	adjMatrix[5] = new int[NUMOFSTADIUMS] {0, 0, 0, 230, 0, 0, 0, 0, 0, 0, 0, 0, 790, 0, 0, 0, 680, 1115, 0, 0, 0, 0, 0, 965,
		0, 0, 0, 0, 0, 0};
	adjMatrix[6] = new int[NUMOFSTADIUMS] {340, 0, 0, 0, 0, 0, 0, 0, 0, 0, 680, 0, 0, 0, 0, 0, 0, 650, 0, 0, 0, 340, 0, 0, 0, 0,
		0, 0, 0, 0};
	adjMatrix[7] = new int[NUMOFSTADIUMS] {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0, 0, 930, 0, 0, 0
		, 195, 560, 0};
	adjMatrix[8] = new int[NUMOFSTADIUMS] {0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 225, 0, 0, 0, 0,
		115, 0, 0};
	adjMatrix[9] = new int[NUMOFSTADIUMS] {0, 210, 430, 0, 0, 0, 0, 0, 0, 0, 2070, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 430,
		0, 0, 225, 0, 0};
	adjMatrix[10] = new int[NUMOFSTADIUMS] {0, 0, 0, 0, 0, 0, 680, 0, 0, 2070, 0, 1390, 0, 0, 0, 680, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		, 0, 0, 0, 0};
	adjMatrix[11] = new int[NUMOFSTADIUMS] {1500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1390, 0, 0, 0, 0, 0, 465, 0, 0, 0, 0, 1500, 0, 0, 300
		, 0, 0, 0, 0, 0};
	adjMatrix[12] = new int[NUMOFSTADIUMS] {0, 0, 0, 0, 0, 790, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 790, 210, 0,
		0, 0, 0, 0, 0};
	adjMatrix[13] = new int[NUMOFSTADIUMS] {0, 240, 0, 0, 415, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 250, 0, 80, 0
		, 0, 0, 0, 0};
	adjMatrix[14] = new int[NUMOFSTADIUMS] {0, 0, 195, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 80, 0, 0, 0, 0, 0, 0, 0,
		315, 0, 0};
	adjMatrix[15] = new int[NUMOFSTADIUMS] {340, 0, 0, 0, 0, 0, 0, 0, 0, 0, 680, 0, 0, 0, 0, 0, 0, 650, 0, 0, 0, 340, 0, 0, 0, 0,
		0, 0, 0, 0};
	adjMatrix[16] = new int[NUMOFSTADIUMS] {0, 0, 0, 0, 235, 680, 0, 0, 0, 0, 0, 465, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 310, 0, 0, 0,
		0, 0, 0, 0};
	adjMatrix[17] = new int[NUMOFSTADIUMS] {0, 0, 0, 870, 0, 1115, 650, 0, 0, 0, 0, 0, 0, 0, 0, 650, 0, 0, 0, 0, 580, 0, 0, 0, 0, 0
		, 300, 0, 0, 0};
	adjMatrix[18] = new int[NUMOFSTADIUMS] {0, 0, 195, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 80, 0, 0, 0, 0, 0, 0, 0,
		315, 0, 0};
	adjMatrix[19] = new int[NUMOFSTADIUMS] {0, 0, 0, 0, 0, 0, 0, 90, 0, 0, 0, 0, 0, 0, 80, 0, 0, 0, 80, 0, 0, 0, 0, 0, 0, 90,
		0, 0, 0, 0};
	adjMatrix[20] = new int[NUMOFSTADIUMS] {0, 0, 0, 650, 560, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 580, 0, 0, 0, 0, 0, 0, 0, 0
		, 830, 0, 0, 0};
	adjMatrix[21] = new int[NUMOFSTADIUMS] {0, 0, 0, 0, 0, 0, 340, 0, 0, 0, 0, 1500, 0, 0, 0, 340, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		110, 0, 0, 0};
	adjMatrix[22] = new int[NUMOFSTADIUMS] {0, 0, 0, 0, 0, 0, 0, 0, 225, 0, 0, 0, 790, 250, 0, 0, 310, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 260, 375, 250};
	adjMatrix[23] = new int[NUMOFSTADIUMS] {0, 0, 1255, 0, 0, 965, 0, 930, 0, 0, 0, 0, 210, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 930,
		0, 0, 600, 0};
	adjMatrix[24] = new int[NUMOFSTADIUMS] {0, 0, 0, 0, 0, 0, 0, 0, 0, 430, 0, 300, 0, 80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		, 0, 0, 80};
	adjMatrix[25] = new int[NUMOFSTADIUMS] {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0, 0, 930, 0, 0, 0
		, 195, 560, 0};
	adjMatrix[26] = new int[NUMOFSTADIUMS] {110, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 300, 0, 0, 830, 110, 0, 0, 0, 0,
		0, 0, 0, 0};
	adjMatrix[27] = new int[NUMOFSTADIUMS] {0, 0, 0, 0, 0, 0, 0, 195, 115, 225, 0, 0, 0, 0, 315, 0, 0, 0, 315, 0, 0, 0, 260, 0, 0, 195,
		0, 0, 0, 0};
	adjMatrix[28] = new int[NUMOFSTADIUMS] {0, 0, 0, 740, 0, 0, 0, 560, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 375, 600, 0, 560,
		0, 0, 0, 0};
	adjMatrix[29] = new int[NUMOFSTADIUMS] {0, 240, 0, 0, 415, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 250, 0, 80, 0
		, 0, 0, 0, 0};

	adjMatrixAmerican = new int*[NUMOFSTADIUMS / 2];
	for (int i = 0; i < NUMOFSTADIUMS / 2; ++i)
	{
		adjMatrixAmerican[i] = new int[NUMOFSTADIUMS / 2];
		for (int j = 0; j < NUMOFSTADIUMS / 2; ++j)
			adjMatrixAmerican[i][j] = adjMatrix[i][j];
	}

	adjMatrixNational = new int*[NUMOFSTADIUMS / 2];
	for (int i = 0; i < NUMOFSTADIUMS / 2; ++i)
	{
		adjMatrixNational[i] = new int[NUMOFSTADIUMS / 2];
		for (int j = 0; j < NUMOFSTADIUMS / 2; ++j)
			adjMatrixNational[i][j] = adjMatrix[i + NUMOFSTADIUMS / 2][j + NUMOFSTADIUMS / 2];
	}


	visited = new bool[NUMOFSTADIUMS];
	for (int i = 0; i < NUMOFSTADIUMS; ++i)
		visited[i] = false;

	visitedAmerican = new bool[NUMOFSTADIUMS / 2];
	for (int i = 0; i < NUMOFSTADIUMS / 2; ++i)
		visitedAmerican[i] = false;

	visitedNational = new bool[NUMOFSTADIUMS / 2];
	for (int i = 0; i < NUMOFSTADIUMS / 2; ++i)
		visitedNational[i] = false;

	costOfTravel = 0;
}

StadiumGraph::~StadiumGraph()
{
	for (int i = 0; i < NUMOFSTADIUMS; ++i)
		delete[] adjMatrix[i];
	for (int i = 0; i < NUMOFSTADIUMS / 2; ++i)
		delete[] adjMatrixAmerican[i];
	for (int i = 0; i < NUMOFSTADIUMS / 2; ++i)
		delete[] adjMatrixNational[i];
	delete[] vertices;
	delete[] visited;
	delete[] visitedAmerican;
	delete[] visitedNational;
}

//Returns a vector of the indices where the boolean array is true.
vector<int> verticesForAlgorithim(bool *arr, int size)
{
	vector<int> result;
	for (int i = 0; i < size; ++i)
	{
		if (!arr[i])
			result.push_back(i);
	}
	return result;
}

//Remove the int parameter from the vector.
vector<int> vectorWithoutValue(vector<int> vect, int n)
{
	vector<int> result = vect;
	for (vector<int>::iterator iter = result.begin(); iter != result.end(); ++iter)
	{
		if (*iter == n)
		{
			result.erase(iter);
			break;
		}
	}
	return result;
}

void printPath(vector<int> path)
{
	for (int i = path.size() - 1; i >= 0; --i)
		cout << path[i] << " ---> ";
	cout << endl;
}

void addToVector(vector<int> &vect, int n)
{
	bool isInVector = false;
	for (int i = 0; i < vect.size(); ++i)
	{
		if (vect[i] == n)
			isInVector = true;
	}

	if (!isInVector)
		vect.push_back(n);
}

bool isAllTrue(bool *arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (!arr[i])
			return false;
	}
	return true;
}

int StadiumGraph::travelingSalesman(int index, vector<int> vertices, vector<int> &backTrack)
{
	int minimum = INT_MAX, value, pathIndex;
	vector<int> vect = vectorWithoutValue(vertices, index);

	if (vect.empty())
	{
		return adjMatrix[0][index];
	}

	for (int i = 0; i < vect.size(); ++i)
	{
		value = adjMatrix[vect[i]][index] + travelingSalesman(vect[i], vect, backTrack);
		if (value < minimum)
		{
			minimum = value;
			pathIndex = index;
		}
	}
	addToVector(backTrack, pathIndex + 1);
	return minimum;
}

void StadiumGraph::salesmanMajor()
{
	int index = 0;
	vector<int> vertices;
	vector<int> backTrack;
	for (int i = 0; i < NUMOFSTADIUMS; ++i)
		vertices.push_back(i);
	costOfTravel = travelingSalesman(index, vertices, backTrack);
	printPath(backTrack);
	cout << " ---> " << index + 1;
	cout << "\nCost of trip: " << getCostOfTravel() << endl << endl;
}

void StadiumGraph::salesmanAmerican()
{
	costOfTravel = 0;
	cout << "\nCost of trip: " << getCostOfTravel() << endl << endl;
}

void StadiumGraph::salesmanNational()
{
	costOfTravel = 0;
	cout << "\nCost of trip: " << getCostOfTravel() << endl << endl;
}
