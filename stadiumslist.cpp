#include <fstream>
#include "stadiumslist.h"

StadiumsList::StadiumsList()
{
    //vertices = new Stadium[NUMOFSTADIUMS];
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
            majorLeagues.insertNode(vertex);
            if (i < NUMOFSTADIUMS / 2)
                americanLeagues.insertNode(vertex);
            else
            {
                vertex.setLeague(false);
                nationalLeagues.insertNode(vertex);
            }
        }
        sList.close();
    }
}

