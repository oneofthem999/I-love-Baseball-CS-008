#ifndef SOUVENIR_H
#define SOUVENIR_H

#include "binarytree.h"
#include "item.h"

class Souvenir
{
    friend class Dialog;
    public:
        Souvenir();
        void addItem(Item& item);
        void removeItem(Item& item);
        Item& getItem(std::string itemName);
    private:
        BinaryTree<Item> souvenirList;
};

#endif // SOUVENIR_H
