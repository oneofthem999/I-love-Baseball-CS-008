#include <iostream>
#include "item.h"

using namespace std;

Item::Item(string newName, double newPrice, string newStadiumName, int newQuantity) : name(newName), price(newPrice), stadiumName(newStadiumName)
  , quantity(newQuantity)
{

}

void Item::setName(string newName) { name = newName; }

void Item::setPrice(double newPrice) { price = newPrice; }

void Item::setStadiumName(string newStadiumName) { stadiumName = newStadiumName; }

void Item::setQuantity(int newQuantity) { quantity = newQuantity; }

string Item::getName() const { return name; }

double Item::getPrice() const { return price; }

string Item::getStadiumName() const { return stadiumName; }

int Item::getQuantity() const { return quantity; }

bool Item::operator<(const Item& other) { return name < other.name; }
bool Item::operator>(const Item& other) { return name > other.name; }
bool Item::operator<=(const Item& other) { return name <= other.name; }
bool Item::operator>=(const Item& other) { return name >= other.name; }
bool Item::operator==(const Item& other) { return name == other.name; }
bool Item::operator!=(const Item& other) { return name != other.name; }
