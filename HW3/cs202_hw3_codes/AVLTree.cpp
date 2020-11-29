/**
* Title : Heaps and AVL Trees
* Author : Berk Yildiz
* ID: 21502040
* Section : 2
* Assignment : 3
* Description : this class includes the implementation of AVL Tree
*/

#include "AVLTree.h"

AVLTree::AVLTree() : root(NULL) {}

// helper function to get height
int AVLTree::height(AVLTreeNode *treePtr)
{
    if (treePtr == NULL)
        return 0;
    return treePtr -> height;
}

//calculate height
int AVLTree::getHeight()
{
    int heightTree = height(root);
    return heightTree;
}
// return maximum of given two integers
int AVLTree::getMaximum(int x, int y)
{
    if(x > y) return x;
    else return y;
}

//perform the right rotation
AVLTreeNode* AVLTree::rightRotate(AVLTreeNode *treePtr)
{
    AVLTreeNode *left = treePtr->leftChildPtr;
    AVLTreeNode *right = left->rightChildPtr;

    left->rightChildPtr = treePtr;
    treePtr->leftChildPtr = right;

    treePtr->height = getMaximum(height(treePtr->leftChildPtr), height(treePtr->rightChildPtr))+1;
    left->height = getMaximum(height(left->leftChildPtr), height(left->rightChildPtr))+1;

    return left;
}

//perform left rotation
AVLTreeNode* AVLTree::leftRotate(AVLTreeNode *treePtr)
{
    AVLTreeNode *right = treePtr->rightChildPtr;
    AVLTreeNode *left = right->leftChildPtr;

    right->leftChildPtr = treePtr;
    treePtr->rightChildPtr = left;

    treePtr->height = getMaximum(height(treePtr->leftChildPtr), height(treePtr->rightChildPtr))+1;
    right->height = getMaximum(height(right->leftChildPtr), height(right->rightChildPtr))+1;

    return right;
}


int AVLTree::getBalance(AVLTreeNode *treePtr)
{
    int balance;
    if (treePtr == NULL)
        return 0;
    balance = height(treePtr->leftChildPtr) - height(treePtr->rightChildPtr);
    return balance;
}

//insert item into AVL Tree
AVLTreeNode* AVLTree::insertItem(AVLTreeNode* treePtr, int nodeItem)
{
    //if tree is empty, create new node
    if (treePtr == NULL)
    {
        AVLTreeNode* newNode = new AVLTreeNode();
        newNode->item   = nodeItem;
        newNode->leftChildPtr   = NULL;
        newNode->rightChildPtr  = NULL;
        newNode->height = 1;  // new node is initially added at leaf
        return newNode;
    }

    if (nodeItem < treePtr->item)
        treePtr->leftChildPtr  = insertItem(treePtr->leftChildPtr, nodeItem);
    else if (nodeItem > treePtr->item)
        treePtr->rightChildPtr = insertItem(treePtr->rightChildPtr, nodeItem);
    else
        return treePtr;


    treePtr->height = 1 + getMaximum(height(treePtr->leftChildPtr),
                              height(treePtr->rightChildPtr));

    int balance = getBalance(treePtr);


    // single left rotate case
    if (balance < -1 && nodeItem > treePtr->rightChildPtr->item)
        return leftRotate(treePtr);

    //single right rotate case
    if (balance > 1 && nodeItem < treePtr->leftChildPtr->item)
        return rightRotate(treePtr);

    // double left rotate case
    if (balance < -1 && nodeItem < treePtr->rightChildPtr->item)
    {
        treePtr->rightChildPtr = rightRotate(treePtr->rightChildPtr);
        return leftRotate(treePtr);
    }

    // double right rotate case
    if (balance > 1 && nodeItem > treePtr->leftChildPtr->item)
    {
        treePtr->leftChildPtr =  leftRotate(treePtr->leftChildPtr);
        return rightRotate(treePtr);
    }

    return treePtr;
}

//helper function for insertion
void AVLTree::insert(int val)
{
    root = insertItem(root, val);

}

//return the node which has minimum value in the tree
AVLTreeNode * AVLTree::findMinimumNode(AVLTreeNode* treePtr)
{
    AVLTreeNode* minimum = treePtr;

    while (minimum->leftChildPtr != NULL)
        minimum = minimum->leftChildPtr;

    return minimum;
}

//perform the deletion
AVLTreeNode* AVLTree:: deleteNode(AVLTreeNode* root, int nodeItem)
{
    //if three is empty
     if (root == NULL)
        return root;

    if ( nodeItem < root->item )
        root->leftChildPtr = deleteNode(root->leftChildPtr, nodeItem);

    else if( nodeItem > root->item )
        root->rightChildPtr = deleteNode(root->rightChildPtr, nodeItem);
    //delete root
    else
    {
        //node with only one child
        if( (root->leftChildPtr == NULL) || (root->rightChildPtr == NULL) )
        {
            AVLTreeNode *temp = root->leftChildPtr ? root->leftChildPtr :
                                root->rightChildPtr;

            //node with no child
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            delete temp;
        }
        else
        {
            //two children case, inorder successor
            AVLTreeNode* temp = findMinimumNode(root->rightChildPtr);
            root->item = temp->item;
            root->rightChildPtr = deleteNode(root->rightChildPtr, temp->item);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + getMaximum(height(root->leftChildPtr),
                           height(root->rightChildPtr));

    int balance = getBalance(root);

    // rotations
    if (balance > 1 && getBalance(root->leftChildPtr) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->leftChildPtr) < 0)
    {
        root->leftChildPtr =  leftRotate(root->leftChildPtr);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->rightChildPtr) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->rightChildPtr) > 0)
    {
        root->rightChildPtr = rightRotate(root->rightChildPtr);
        return leftRotate(root);
    }

    return root;
}

//helper function for deletion
void AVLTree::deleteKey(int val)
{
    deleteNode(root, val);
}

//print AVL Tree
void AVLTree::printTreeFunction(AVLTreeNode* root, int space)
{
    if (root == NULL)
        return;

    space += 5;

    printTreeFunction(root->rightChildPtr, space);

    cout << endl;
    for (int i = 5; i < space; i++)
        cout << (" ");
    cout << root->item << endl;

    printTreeFunction(root->leftChildPtr, space);
}

//helper function for print
void AVLTree::printTree()
{
   printTreeFunction(root, 0);
}

