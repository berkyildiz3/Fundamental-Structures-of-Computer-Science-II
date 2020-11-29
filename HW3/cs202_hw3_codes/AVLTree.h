/**
* Title : Heaps and AVL Trees
* Author : Berk Yildiz
* ID: 21502040
* Section : 2
* Assignment : 3
* Description : header for AVL Tree
*/

#include<stdlib.h>
#include<stdio.h>
#include <iostream>
#include "AVLTreeNode.h"
using namespace std;

#ifndef AVLTREE_H
#define AVLTREE_H
class AVLTree
{

public:

    AVLTreeNode* root;

    AVLTree();

    int getMaximum(int x, int y);
    int getHeight();
    int height(AVLTreeNode* treePtr);
    AVLTreeNode* rightRotate(AVLTreeNode* treePtr);
    AVLTreeNode* leftRotate(AVLTreeNode* treePtr);
    int getBalance(AVLTreeNode* treePtr);
    void insert(int val);
    AVLTreeNode* insertItem(AVLTreeNode* treePtr, int value);
    AVLTreeNode* findMinimumNode(AVLTreeNode* treePtr);
    AVLTreeNode* deleteNode(AVLTreeNode* root, int val);
    void deleteKey(int key);
    void printTreeFunction(AVLTreeNode* root, int space);
    void printTree();
};
#endif // AVLTREE_H
