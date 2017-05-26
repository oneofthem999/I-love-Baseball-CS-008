#ifndef STADIUM_H
#define STADIUM_H

#include "souvenir.h"

const int NUMOFSTADIUMS = 30;

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
        void setLeague(bool isNationalLeague);
        std::string getStadiumName() const;
        std::string getTeamName() const;
        std::string getAddress() const;
        std::string getDate() const;
        bool getGrass() const;
        std::string getPhoneNumber() const;
        int getCapacity() const;
        bool getNationalLeague() const;

        void addItemToSouvenirs(Item& item);
        void removeItemFromSouvenirs(Item& item);
        Item& getItemFromSouvenirs(string itemName);

        bool operator<(const Stadium& other);
        bool operator>(const Stadium& other);
        bool operator<=(const Stadium& other);
        bool operator>=(const Stadium& other);
        bool operator==(const Stadium& other);
        bool operator!=(const Stadium& other);

        bool to_bool(std::string const& s) const;
    private:
        Souvenir stadiumGoods;
        std::string stadiumName;
        std::string teamName;
        std::string address;
        std::string date;
        bool grass;
        std::string phoneNumber;
        int capacity;
        bool isNationalLeague;
};

#endif // STADIUM_H
