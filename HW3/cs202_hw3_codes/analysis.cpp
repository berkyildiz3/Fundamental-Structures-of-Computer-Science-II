/**
* Title : Heaps and AVL Trees
* Author : Berk Yildiz
* ID: 21502040
* Section : 2
* Assignment : 3
* Description : implementation of the analysis
*/

#include "analysis.h"

using namespace std;

// Merges two subarrays for the merge sort algorithm
void merge(int arr[], int first, int mid, int last)
{
    int i, j, k;
    int size1 = mid - first + 1;
    int size2 =  last - mid;

    //temmporary arrays
    int left[size1], right[size2];

    //place the array elements into temp arrays
    for (i = 0; i < size1; i++)
    {
        left[i] = arr[first + i];
    }

    for (j = 0; j < size2; j++)
    {
        right[j] = arr[mid + 1+ j];
    }

    //merge the temporary arrays
    i = 0;
    j = 0;
    k = first;
    while (i < size1 && j < size2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    //Place the remaining elements of first sub array
    while (i < size1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

   //Place the remaining elements of second sub array
    while (j < size2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }

}

//implementation of the merge sort algorithm
void mergeSort(int *arr, int first, int last)
{
    if (first < last)
    {
        int mid = first+(last-first)/2;

        mergeSort(arr, first, mid);
        mergeSort(arr, mid+1, last);

        merge(arr, first, mid, last);
    }
}

//perform height analysis
void heightAnalysis()
{
    //empty trees for random numbers
    AVLTree avlTree4;
    AVLTree avlTree8;
    AVLTree avlTree12;
    AVLTree avlTree16;
    AVLTree avlTree20;
    AVLTree avlTree30;
    AVLTree avlTree40;
    AVLTree avlTree50;
    AVLTree avlTree80;

    int height4;
    int height8;
    int height12;
    int height16;
    int height20;
    int height30;
    int height40;
    int height50;
    int height80;

    //empty trees for ascending order
    AVLTree avlTree4Ascend;
    AVLTree avlTree8Ascend;
    AVLTree avlTree12Ascend;
    AVLTree avlTree16Ascend;
    AVLTree avlTree20Ascend;
    AVLTree avlTree30Ascend;
    AVLTree avlTree40Ascend;
    AVLTree avlTree50Ascend;
    AVLTree avlTree80Ascend;

    int height4Ascend;
    int height8Ascend;
    int height12Ascend;
    int height16Ascend;
    int height20Ascend;
    int height30Ascend;
    int height40Ascend;
    int height50Ascend;
    int height80Ascend;

    //empty trees for descending order
    AVLTree avlTree4Descend;
    AVLTree avlTree8Descend;
    AVLTree avlTree12Descend;
    AVLTree avlTree16Descend;
    AVLTree avlTree20Descend;
    AVLTree avlTree30Descend;
    AVLTree avlTree40Descend;
    AVLTree avlTree50Descend;
    AVLTree avlTree80Descend;

    int height4Descend;
    int height8Descend;
    int height12Descend;
    int height16Descend;
    int height20Descend;
    int height30Descend;
    int height40Descend;
    int height50Descend;
    int height80Descend;

    //size of the arrays
    const int size4 = 4000;
    const int size8 = 8000;
    const int size12 = 12000;
    const int size16 = 16000;
    const int size20 = 20000;
    const int size30 = 30000;
    const int size40 = 40000;
    const int size50 = 50000;
    const int size80 = 80000;

    //empty arrays with specified sizes
    int *arr4 = new int[size4];
    int *arr8 = new int[size8];
    int *arr12 = new int[size12];
    int *arr16 = new int[size16];
    int *arr20 = new int[size20];
    int *arr30 = new int[size30];
    int *arr40 = new int[size40];
    int *arr50 = new int[size50];
    int *arr80 = new int[size80];

    //insertion of the random numbers in to avl trees
     for(int i=0; i < size4; i++)
    {
        arr4[i] = rand();
        avlTree4.insert(arr4[i]);
    }

     for(int i=0; i < size8; i++)
    {
        arr8[i] = rand();
        avlTree8.insert(arr8[i]);
    }

     for(int i=0; i < size12; i++)
    {
        arr12[i] = rand();
        avlTree12.insert(arr12[i]);
    }

     for(int i=0; i < size16; i++)
    {
        arr16[i] = rand();
        avlTree16.insert(arr16[i]);
    }

     for(int i=0; i < size20; i++)
    {
        arr20[i] = rand();
        avlTree20.insert(arr20[i]);
    }

     for(int i=0; i < size30; i++)
    {
        arr30[i] = rand();
        avlTree30.insert(arr30[i]);
    }

     for(int i=0; i < size40; i++)
    {
        arr40[i] = rand();
        avlTree40.insert(arr40[i]);
    }

     for(int i=0; i < size50; i++)
    {
        arr50[i] = rand();
        avlTree50.insert(arr50[i]);
    }

     for(int i=0; i < size80; i++)
    {
        arr80[i] = rand();
        avlTree80.insert(arr80[i]);
    }

    //get heights of the random numbered avl trees
    height4 = avlTree4.getHeight();
    height8 = avlTree8.getHeight();
    height12 = avlTree12.getHeight();
    height16 = avlTree16.getHeight();
    height20 = avlTree20.getHeight();
    height30 = avlTree30.getHeight();
    height40 = avlTree40.getHeight();
    height50 = avlTree50.getHeight();
    height80 = avlTree80.getHeight();

    //rearrange the arrays is ascending order
    mergeSort(arr4, 0, size4-1);
    mergeSort(arr8, 0, size8-1);
    mergeSort(arr12, 0, size12-1);
    mergeSort(arr16, 0, size16-1);
    mergeSort(arr20, 0, size20-1);
    mergeSort(arr30, 0, size30-1);
    mergeSort(arr40, 0, size40-1);
    mergeSort(arr50, 0, size50-1);
    mergeSort(arr80, 0, size80-1);

    //insert the elements of the ascending order arrays in to avl trees
     for(int i=0; i < size4; i++)
    {
        avlTree4Ascend.insert(arr4[i]);
    }

     for(int i=0; i < size8; i++)
    {
        avlTree8Ascend.insert(arr8[i]);
    }

     for(int i=0; i < size12; i++)
    {
        avlTree12Ascend.insert(arr12[i]);
    }

     for(int i=0; i < size16; i++)
    {
        avlTree16Ascend.insert(arr16[i]);
    }

     for(int i=0; i < size20; i++)
    {
        avlTree20Ascend.insert(arr20[i]);
    }

     for(int i=0; i < size30; i++)
    {
        avlTree30Ascend.insert(arr30[i]);
    }

     for(int i=0; i < size40; i++)
    {
        avlTree40Ascend.insert(arr40[i]);
    }

     for(int i=0; i < size50; i++)
    {
        avlTree50Ascend.insert(arr50[i]);
    }

     for(int i=0; i < size80; i++)
    {
        avlTree80Ascend.insert(arr80[i]);
    }

    //get heights of the ascending order numbered avl trees
    height4Ascend = avlTree4Ascend.getHeight();
    height8Ascend = avlTree8Ascend.getHeight();
    height12Ascend = avlTree12Ascend.getHeight();
    height16Ascend = avlTree16Ascend.getHeight();
    height20Ascend = avlTree20Ascend.getHeight();
    height30Ascend = avlTree30Ascend.getHeight();
    height40Ascend = avlTree40Ascend.getHeight();
    height50Ascend = avlTree50Ascend.getHeight();
    height80Ascend = avlTree80Ascend.getHeight();

    //rearrange the arrays' elements in descending order
    int temp;
    for (int i = 0; i < size4/2; ++i)
    {
    temp = arr4[size4-i-1];
    arr4[size4-i-1] = arr4[i];
    arr4[i] = temp;
    }

     for (int i = 0; i < size8/2; ++i)
    {
    temp = arr8[size8-i-1];
    arr8[size8-i-1] = arr8[i];
    arr8[i] = temp;
    }

     for (int i = 0; i < size12/2; ++i)
    {
    temp = arr12[size12-i-1];
    arr4[size12-i-1] = arr12[i];
    arr12[i] = temp;
    }

     for (int i = 0; i < size16/2; ++i)
    {
    temp = arr16[size16-i-1];
    arr16[size16-i-1] = arr16[i];
    arr16[i] = temp;
    }

     for (int i = 0; i < size20/2; ++i)
    {
    temp = arr20[size20-i-1];
    arr20[size20-i-1] = arr20[i];
    arr20[i] = temp;
    }

     for (int i = 0; i < size30/2; ++i)
    {
    temp = arr30[size30-i-1];
    arr30[size30-i-1] = arr30[i];
    arr30[i] = temp;
    }

     for (int i = 0; i < size40/2; ++i)
    {
    temp = arr40[size40-i-1];
    arr40[size40-i-1] = arr40[i];
    arr40[i] = temp;
    }

     for (int i = 0; i < size50/2; ++i)
    {
    temp = arr50[size50-i-1];
    arr50[size50-i-1] = arr50[i];
    arr50[i] = temp;
    }

     for (int i = 0; i < size80/2; ++i)
    {
    temp = arr80[size80-i-1];
    arr80[size80-i-1] = arr80[i];
    arr80[i] = temp;
    }

    //insert the elements of the descending order arrays in to avl trees
      for(int i=0; i < size4; i++)
    {
        avlTree4Descend.insert(arr4[i]);
    }

     for(int i=0; i < size8; i++)
    {
        avlTree8Descend.insert(arr8[i]);
    }

     for(int i=0; i < size12; i++)
    {
        avlTree12Descend.insert(arr12[i]);
    }

     for(int i=0; i < size16; i++)
    {
        avlTree16Descend.insert(arr16[i]);
    }

     for(int i=0; i < size20; i++)
    {
        avlTree20Descend.insert(arr20[i]);
    }

     for(int i=0; i < size30; i++)
    {
        avlTree30Descend.insert(arr30[i]);
    }

     for(int i=0; i < size40; i++)
    {
        avlTree40Descend.insert(arr40[i]);
    }

     for(int i=0; i < size50; i++)
    {
        avlTree50Descend.insert(arr50[i]);
    }

     for(int i=0; i < size80; i++)
    {
        avlTree80Descend.insert(arr80[i]);
    }

    //get heights of the descending order numbered avl trees
    height4Descend = avlTree4Descend.getHeight();
    height8Descend = avlTree8Descend.getHeight();
    height12Descend = avlTree12Descend.getHeight();
    height16Descend = avlTree16Descend.getHeight();
    height20Descend = avlTree20Descend.getHeight();
    height30Descend = avlTree30Descend.getHeight();
    height40Descend = avlTree40Descend.getHeight();
    height50Descend = avlTree50Descend.getHeight();
    height80Descend = avlTree80Descend.getHeight();




    //print the data that collected
    cout << "           Part b - Height analysis of AVL trees" << endl;
    cout << "-----------------------------------------------------------------" <<endl;
    cout << "Array Size           Random          Ascending          Descending" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout <<"  " << size4 << "                 " << height4 << "               " << height4Ascend << "                 " << height4Descend << endl;
    cout <<"  " << size8 << "                 " << height8 << "               " << height8Ascend << "                 " << height8Descend << endl;
    cout <<"  " << size12 << "                " << height12 << "               " << height12Ascend << "                 " << height12Descend << endl;
    cout <<"  " << size16 << "                " << height16 << "               " << height16Ascend << "                 " << height16Descend << endl;
    cout <<"  " << size20 << "                " << height20 << "               " << height20Ascend << "                 " << height20Descend << endl;
    cout <<"  " << size30 << "                " << height30 << "               " << height30Ascend << "                 " << height30Descend << endl;
    cout <<"  " << size40 << "                " << height40 << "               " << height40Ascend << "                 " << height40Descend << endl;
    cout <<"  " << size50 << "                " << height50 << "               " << height50Ascend << "                 " << height50Descend << endl;
    cout <<"  " << size80 << "                " << height80 << "               " << height80Ascend << "                 " << height80Descend << endl;
}
