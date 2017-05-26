#ifndef STADIUMSLIST_H
#define STADIUMSLIST_H
#include "binarytree.h"
#include "stadium.h"

class StadiumsList
{
    public:
        StadiumsList();
    private:
        BinaryTree<Stadium> majorLeagues;
        BinaryTree<Stadium> nationalLeagues;
        BinaryTree<Stadium> americanLeagues;
};

#endif // STADIUMSLIST_H
