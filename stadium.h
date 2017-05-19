#ifndef STADIUM_H
#define STADIUM_H

#include "souvenir.h"

class Stadium
{
    public:
        Stadium(std::string sName = "", std::string tName = "", std::string addr = "", std::string theDate = ""
            , bool grassOrNot = true, std::string num = "", int cap = 100);
        void setStadiumName(std::string sName);
        void setTeamName(std::string tName);
        void setAddress(std::string addr);
        void setDate(std::string theDate);
        void setGrass(bool grassOrNot);
        void setPhoneNumber(std::string num);
        void setCapacity(int cap);
        std::string getStadiumName() const;
        std::string getTeamName() const;
        std::string getAddress() const;
        std::string getDate() const;
        bool getGrass() const;
        std::string getPhoneNumber() const;
        int getCapacity() const;

        void addItemToSouvenirs(Item& item);
        void removeItemFromSouvenirs(Item& item);
        Item& getItemFromSouvenirs(string itemName);
    private:
        Souvenir stadiumGoods;
        std::string stadiumName;
        std::string teamName;
        std::string address;
        std::string date;
        bool grass;
        std::string phoneNumber;
        int capacity;
};

#endif // STADIUM_H
