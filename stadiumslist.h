#ifndef STADIUMSLIST_H
#define STADIUMSLIST_H
#include "binarytree.h"
#include "stadium.h"
#include "mainwindow.h"

#include "sstream"

class StadiumsList
{


    public:
        StadiumsList(vector<QString> &names);
        std::vector<QString> names;
        std::vector<QString> team;
        std::vector<QString> phone;
        std::vector<QString> address;
        std::vector<QString> turf;
        std::vector<QString> cap;
        std::vector<QString> dates;
        std::vector<Stadium> stads;
        int size =0;
    private:
        BinaryTree<Stadium> majorLeagues;
        BinaryTree<Stadium> nationalLeagues;
        BinaryTree<Stadium> americanLeagues;
};

#endif // STADIUMSLIST_H
