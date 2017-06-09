#include "souvenir.h"

using namespace std;

Souvenir::Souvenir()
{
    Item bbCap("Baseball Cap", 25.99),
    bbBat("Baseball Bat", 35.35), pen("Team pennant, 12.99"), autog("Autographed Baseball", 19.99);
    addItem(bbCap);
    addItem(pen);
    addItem(autog);
    addItem(bbBat);
}

void Souvenir::addItem(Item& item) { souvenirList.insertNode(item); }

void Souvenir::removeItem(Item& item) { souvenirList.remove(item); }

Item& Souvenir::getItem(string itemName)
{
    TreeNode<Item>* nodePtr = souvenirList.getRoot();

    while (nodePtr)
    {
        if (nodePtr->value.getName() == itemName)
            return nodePtr->value;
        else if (itemName < nodePtr->value.getName())
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }

    return nodePtr->value;
}
