#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <iomanip>

using namespace std;

template <typename A>
struct TreeNode
{
    A value;
    TreeNode<A> *left;
    TreeNode<A> *right;

    TreeNode<A>& operator=(const TreeNode<A>& other);
};

template <typename A>
class BinaryTree
{
    private:
        TreeNode<A>* root;

        void insert(TreeNode<A> *&, TreeNode<A> *&);
        void destroySubTree(TreeNode<A> *);
        void deleteNode(A, TreeNode<A> *&);
        void makeDeletion(TreeNode<A> *&);
        void displayInOrder(TreeNode<A> *) const;
        void displayPreOrder(TreeNode<A> *) const;
        void displayPostOrder(TreeNode<A> *) const;

        int leaf_count(TreeNode<A> *) const;
        int non_leaf_count(TreeNode<A> *) const;

        void traversalInsert(TreeNode<A> *);

    public:
        //Constructor
        BinaryTree() { root = NULL; }
        BinaryTree(const BinaryTree<A>& other) { *this = other; }

        ~BinaryTree() { destroySubTree(root); }

        //Binary Tree Operations
        void insertNode(A);
        bool searchNode(A);
        TreeNode<A>*& search(A);
        void remove(A);
        TreeNode<A>* getRoot() const;

        void displayInOrder() const { displayInOrder(root); }
        void displayPreOrder() const { displayPreOrder(root); }
        void displayPostOrder() const { displayPostOrder(root); }
        int leaf_count() const;
        int non_leaf_count() const;
        int size() const;

        BinaryTree<A>& operator=(const BinaryTree<A>& other);
};

template <typename A>
TreeNode<A>& TreeNode<A>::operator=(const TreeNode<A>& other)
{
    value = other.value;

    TreeNode<A> *originalLeft = left;
    TreeNode<A> *originalRight = right;
    left = &(*other.left);
    right = &(*other.right);

    delete originalLeft;
    delete originalRight;
}

template <typename A>
void BinaryTree<A>::insertNode(A value)
{
    TreeNode<A> *newNode = new TreeNode<A>;

    newNode->value = value;
    newNode->left = newNode->right = NULL;

    //Insert the Node
    insert(root, newNode);
}

template <typename A>
void BinaryTree<A>::insert(TreeNode<A> *&nodePtr, TreeNode<A> *&newNode) {
    if (nodePtr == NULL)
        nodePtr = newNode;
    else if (newNode->value < nodePtr->value)
        insert(nodePtr->left, newNode);
    else
        insert(nodePtr->right, newNode);
}

template <typename A>
void BinaryTree<A>::displayInOrder(TreeNode<A> *nodePtr) const
{
    if (nodePtr) {
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << " ";
        displayInOrder(nodePtr->right);
    }
}

template <typename A>
void BinaryTree<A>::displayPreOrder(TreeNode<A> *nodePtr) const
{
    if (nodePtr) {
        cout << nodePtr->value << " ";
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

template <typename A>
void BinaryTree<A>::displayPostOrder(TreeNode<A> *nodePtr) const
{
    if (nodePtr) {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << " ";
    }
}

template <typename A>
void BinaryTree<A>::destroySubTree(TreeNode<A> *nodePtr)
{
    cout << "Binary Tree Destroyed\n";
}

template <typename A>
bool BinaryTree<A>::searchNode(A value)
{
    TreeNode<A>* nodePtr = root;

    while (nodePtr) {
        if (nodePtr->value == value)
            return true;
        else if (value < nodePtr->value)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    return false;
}

template <typename A> //Do not call if searchNode(value) returns false!!!
TreeNode<A>*& BinaryTree<A>::search(A value)
{
    TreeNode<A>* nodePtr = root;

    while (nodePtr)
    {
        if (nodePtr->value == value)
            return nodePtr;
        else if (value < nodePtr->value)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
}

template <typename A>
void BinaryTree<A>::remove(A value) { deleteNode(value, root); }

template <typename A>
TreeNode<A>* BinaryTree<A>::getRoot() const { return root; }

template <typename A>
void BinaryTree<A>::deleteNode(A value, TreeNode<A> *&nodePtr) {
    if (value < nodePtr->value)
        deleteNode(value, nodePtr->left);
    else if (value > nodePtr->value)
        deleteNode(value, nodePtr->right);
    else
        makeDeletion(nodePtr);
}

template <typename A>
void BinaryTree<A>::makeDeletion(TreeNode<A> *&nodePtr) {
    TreeNode<A> *tempNodePtr;

    if (nodePtr == NULL)
        cout << "Cannot delete empty node\n";
    else if (nodePtr->right == NULL)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;
        delete tempNodePtr;
    }
    else if (nodePtr->left == NULL)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
    //If the node has two Children
    else
    {
        //Move one node to the right
        tempNodePtr = nodePtr->right;
        //Go to the end left node
        while (tempNodePtr->left)
            tempNodePtr = tempNodePtr->left;
        //Reattach the left subtree
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        //Reattach the right subtree
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}

template <typename A>
int BinaryTree<A>::leaf_count(TreeNode<A> *ptr) const
{
    int count = 0;
    if (!ptr->left && !ptr->right)
    {
        count++;
    }
    else if (!ptr->left && ptr->right)
        count += leaf_count(ptr->right);
    else if (ptr->left && !ptr->right)
        count += leaf_count(ptr->left);
    else
    {
        count += leaf_count(ptr->left);
        count += leaf_count(ptr->right);
    }
    return count;
}

template <typename A>
int BinaryTree<A>::non_leaf_count(TreeNode<A> *ptr) const
{
    int count = 0;

    if (ptr->left && ptr->right)
    {
        count++;
        count += non_leaf_count(ptr->left);
        count += non_leaf_count(ptr->right);
    }
    else if (ptr->left && !ptr->right)
    {
        count++;
        count += non_leaf_count(ptr->left);
    }
    else if (!ptr->left && ptr->right)
    {
        count++;
        count += non_leaf_count(ptr->right);
    }

    return count;
}

template <typename A>
int BinaryTree<A>::leaf_count() const
{
    return leaf_count(root);
}

template <typename A>
int BinaryTree<A>::non_leaf_count() const
{
    return non_leaf_count(root);
}

template <typename A>
int BinaryTree<A>::size() const
{
    return leaf_count() + non_leaf_count();
}

template <typename A>
BinaryTree<A>& BinaryTree<A>::operator=(const BinaryTree<A>& other)
{
    delete root;
    TreeNode<A> *otherRoot = other.root;
    traversalInsert(otherRoot);
    return *this;
}

template <typename A>
void BinaryTree<A>::traversalInsert(TreeNode<A> *other)
{
    insertNode(other->value);

    if (!other->left && other->right)
        traversalInsert(other->right);
    else if (other->left && !other->right)
        traversalInsert(other->left);
    else if (other->left && other->right)
    {
        traversalInsert(other->left);
        traversalInsert(other->right);
    }
}

#endif
