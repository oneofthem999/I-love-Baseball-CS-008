#include <iostream>
#include "stadium.h"

using namespace std;

Stadium::Stadium(string sName, string tName, string addr, string theDate, bool grassOrNot, string num, int cap)
    : stadiumName(sName), teamName(tName), address(addr), date(theDate), grass(grassOrNot), phoneNumber(num), capacity(cap), isNationalLeague(true)
{

}

void Stadium::setStadiumName(string sName) { stadiumName = sName; }
void Stadium::setTeamName(string tName) { teamName = tName; }
void Stadium::setAddress(string addr) { address = addr; }
void Stadium::setDate(string theDate) { date = theDate; }
void Stadium::setGrass(bool grassOrNot) { grass = grassOrNot; }
void Stadium::setPhoneNumber(string num) { phoneNumber = num; }
void Stadium::setCapacity(int cap) { capacity = cap; }
void Stadium::setLeague(bool isNational) { isNationalLeague = isNational; }
string Stadium::getStadiumName() const { return stadiumName; }
string Stadium::getTeamName() const { return teamName; }
string Stadium::getAddress() const { return address; }
string Stadium::getDate() const { return date; }
bool Stadium::getGrass() const { return grass; }
string Stadium::getPhoneNumber() const { return phoneNumber; }
int Stadium::getCapacity() const { return capacity; }
bool Stadium::getNationalLeague() const { return isNationalLeague; }

void Stadium::addItemToSouvenirs(Item &item) { stadiumGoods.addItem(item); }

void Stadium::removeItemFromSouvenirs(Item &item) { stadiumGoods.removeItem(item); }

Item& Stadium::getItemFromSouvenirs(string itemName) { return stadiumGoods.getItem(itemName); }

bool Stadium::operator<(const Stadium& other) { return getStadiumName() < other.getStadiumName(); }
bool Stadium::operator>(const Stadium& other) { return getStadiumName() > other.getStadiumName(); }
bool Stadium::operator<=(const Stadium& other) { return getStadiumName() <= other.getStadiumName(); }
bool Stadium::operator>=(const Stadium& other) { return getStadiumName() >= other.getStadiumName(); }
bool Stadium::operator==(const Stadium& other) { return getStadiumName() == other.getStadiumName(); }
bool Stadium::operator!=(const Stadium& other) { return getStadiumName() != other.getStadiumName(); }

bool Stadium::to_bool(std::string const& s) const
{
     return s == "true";
}
