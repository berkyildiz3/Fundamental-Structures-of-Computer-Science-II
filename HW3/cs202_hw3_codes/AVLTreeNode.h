/**
* Title : Heaps and AVL Trees
* Author : Berk Yildiz
* ID: 21502040
* Section : 2
* Assignment : 3
* Description : header for AVL Tree node
*/

#ifndef AVLTREENODE_H
#define AVLTREENODE_H
class AVLTreeNode   // node in the tree
    {
    private:

        AVLTreeNode() {};

        int item; // data portion
        int height; //height of the specified node
        AVLTreeNode* leftChildPtr; // pointer to left child
        AVLTreeNode* rightChildPtr; // pointer to right child

        friend class AVLTree;
    };
#endif // AVLTREENODE_H
