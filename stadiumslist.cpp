#include <fstream>
#include "stadiumslist.h"
#include <sstream>


StadiumsList::StadiumsList(vector<QString> &names)
{
    //vertices = new Stadium[NUMOFSTADIUMS];
    ifstream sList ("Stadiums.txt");
    std::cout<<"hello"<<endl;
    if (sList.is_open())
    {
        string line;
        QString temp;
        int num;
        bool isGrass;
        //Stadium vertex;
        for (int i = 0; i < NUMOFSTADIUMS; ++i)
        {   ++size;

            Stadium vertex;
            getline(sList, line);
            vertex.setStadiumName(line);
            names.push_back(QString::fromStdString(line));

            getline(sList, line);
            vertex.setTeamName(line);
            team.push_back(QString::fromStdString(line));

            getline(sList, line);
            vertex.setAddress(line);
            address.push_back(QString::fromStdString(line));

            getline(sList, line);
            vertex.setPhoneNumber(line);
            phone.push_back(QString::fromStdString(line));

            getline(sList, line);
            vertex.setDate(line);
            dates.push_back(QString::fromStdString(line));

            getline(sList, line);

            stringstream convert(line);
            convert>>num;

            vertex.setCapacity(num);
            cap.push_back(QString::fromStdString(line));

            getline(sList, line);
            isGrass = vertex.to_bool(line);
            turf.push_back(QString::fromStdString(line));
            vertex.setGrass(isGrass);
            //stads.push_back(vertex);
            getline(sList, line);
            getline(sList, line);
            std::cout<<"here"<<endl;
            majorLeagues.insertNode(vertex);
            if (i < NUMOFSTADIUMS / 2)
            //    americanLeagues.insertNode(vertex);
                ;
            else
            {
               vertex.setLeague(false);
              // nationalLeagues.insertNode(vertex);
            }
            std::cout<<"hello"<<endl;

        }
        sList.close();
    }
}

