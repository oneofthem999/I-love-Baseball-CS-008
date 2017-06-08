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

bool isAllTrue(bool *arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (!arr[i])
			return false;
	}
	return true;
}

void StadiumGraph::mincost(int** arr, int size, int city)
{
	int nextCity;
	visited[city] = true;
	cout << city + 1 << " ---> ";
	nextCity = least(arr, size, city);

	//End of the loop.  Return to first node (1)
	if (nextCity == -1)
	{
		nextCity = 0;
		cout << nextCity + 1;
		costOfTravel += arr[city][nextCity];
		return;
	}
	mincost(arr, size, nextCity);
}

int StadiumGraph::least(int** arr, int size, int city)
{
	int nextCity = -1;
	int min = 999, costOfMin = 0;
	for (int i = 0; i < size; i++)
	{
		if ((arr[city][i] != -1) && (!visited[i]))
			if (arr[city][i] < min)
			{
				min = arr[i][0] + arr[city][i];
				costOfMin = arr[city][i];
				nextCity = i;
			}
	}
	if (min != 999)
		costOfTravel += costOfMin;
	return nextCity;
}

void StadiumGraph::mincostAmerican(int** arr, int size, int city)
{
	int nextCity;
	visitedAmerican[city] = true;
	cout << city + 1 << " ---> ";
	nextCity = leastAmerican(arr, size, city);

	//End of the loop.  Return to first node (1)
	if (nextCity == -1)
	{
		nextCity = 0;
		cout << nextCity + 1;
		costOfTravel += arr[city][nextCity];
		return;
	}
	mincostAmerican(arr, size, nextCity);
}

int StadiumGraph::leastAmerican(int** arr, int size, int city)
{
	int nextCity = -1;
	int min = 999, costOfMin = 0;
	for (int i = 0; i < size; i++)
	{
		if ((arr[city][i] != -1) && (!visitedAmerican[i]))
			if (arr[city][i] < min)
			{
				min = arr[i][0] + arr[city][i];
				costOfMin = arr[city][i];
				nextCity = i;
			}
	}
	if (min != 999)
		costOfTravel += costOfMin;
	return nextCity;
}

void StadiumGraph::mincostNational(int** arr, int size, int city)
{
	int nextCity;
	visitedNational[city] = true;
	cout << city + 1 + NUMOFSTADIUMS / 2 << " ---> ";
	nextCity = leastNational(arr, size, city);

	//End of the loop.  Return to first node (16)
	if ((nextCity == -1))
	{
		nextCity = 0;
		cout << nextCity + 1 + NUMOFSTADIUMS / 2;
		costOfTravel += arr[city][nextCity];
		return;
	}
	mincostNational(arr, size, nextCity);
}

int StadiumGraph::leastNational(int** arr, int size, int city)
{
	int nextCity = -1;
	int min = 999, costOfMin = 0;
	for (int i = 0; i < size; i++)
	{
		if ((arr[city][i] != -1) && (!visitedNational[i]))
			if (arr[city][i] < min)
			{
				min = arr[i][0] + arr[city][i];
				costOfMin = arr[city][i];
				nextCity = i;
			}
	}
	if (min != 999)
		costOfTravel += costOfMin;
	return nextCity;
}

void StadiumGraph::salesmanMajor()
{
	costOfTravel = 0;
	mincost(adjMatrix, NUMOFSTADIUMS, 0);
	cout << "\nCost of trip: " << getCostOfTravel() << endl << endl;
}

void StadiumGraph::salesmanAmerican()
{
	costOfTravel = 0;
	mincostAmerican(adjMatrixAmerican, NUMOFSTADIUMS / 2, 0);
	cout << "\nCost of trip: " << getCostOfTravel() << endl << endl;
}

void StadiumGraph::salesmanNational()
{
	costOfTravel = 0;
	mincostNational(adjMatrixNational, NUMOFSTADIUMS / 2, 0);
	cout << "\nCost of trip: " << getCostOfTravel() << endl << endl;
}
