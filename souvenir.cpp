#include "souvenir.h"

using namespace std;

Souvenir::Souvenir()
{

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
