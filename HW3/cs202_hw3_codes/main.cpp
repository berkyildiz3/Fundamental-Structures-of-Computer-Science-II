/**
* Title : Heaps and AVL Trees
* Author : Berk Yildiz
* ID: 21502040
* Section : 2
* Assignment : 3
* Description : this is the class includes the main method
*/

#include "AVLTree.h"
#include "analysis.h"


int main()
{
    //create instance
    AVLTree avl;

    //insertions
    avl.insert(5);
    avl.insert(10);
    avl.insert(15);
    avl.insert(60);
    avl.insert(8);
    avl.insert(40);
    avl.insert(2);
    avl.insert(30);
    avl.insert(17);
    avl.insert(12);
    avl.insert(74);

    //print tree after insertions
    cout << "----------After Insertion----------" << endl;
    avl.printTree();

    //deletions
    avl.deleteKey(30);
    avl.deleteKey(10);
    avl.deleteKey(8);
    avl.deleteKey(74);
    avl.deleteKey(5);

    cout << endl;
    cout << endl;

    //print three after deletions
    cout << "----------After Deletion----------" << endl;
    avl.printTree();

    cout << endl;
    cout << endl;
    cout << endl;

    //call height analysis
    heightAnalysis();

    return 0;
}

