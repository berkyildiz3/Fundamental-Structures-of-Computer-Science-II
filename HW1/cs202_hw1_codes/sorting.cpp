#include <iostream>
#include "sorting.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

/* Title: Algorithm Efficiency and Sorting
 * Author: Berk Yýldýz
 * ID: 21502040
 * Section: 2
 * Assignment: 1
 * Description: includes the implementation of the sorting algorithms
 */

 //implementation of the insertion sort algorithm
void sorting::insertionSort(int *arr, int first, int last, int &compCount, int &moveCount)
{
    int size = last - first + 1;


    for ( first = 1; first < size; ++first)
    {
        compCount++;
        int nextItem = arr[first];
        moveCount++;
        int last = first;
        moveCount++;

        for (; (last > 0) && (arr[last-1] > nextItem); --last)
        {
            if((arr[last-1] > nextItem))
                compCount++;
            arr[last] = arr[last-1];
            moveCount++;
            compCount++;
        }

        arr[last] = nextItem;
        moveCount++;
    }
}

// Merges two subarrays for the merge sort algorithm
void sorting::merge(int arr[], int first, int mid, int last, int &compCount, int &moveCount)
{
    int i, j, k;
    int size1 = mid - first + 1;
    moveCount++;
    int size2 =  last - mid;
    moveCount++;

    //temmporary arrays
    int left[size1], right[size2];

    //place the array elements into temp arrays
    for (i = 0; i < size1; i++)
    {
        left[i] = arr[first + i];
        moveCount++;
    }

    for (j = 0; j < size2; j++)
    {
        right[j] = arr[mid + 1+ j];
        moveCount++;
    }


    //merge the temporary arrays
    i = 0;
    j = 0;
    k = first;
    while (i < size1 && j < size2)
    {
        if (left[i] <= right[j])
        {
            compCount++;
            arr[k] = left[i];
            moveCount++;
            i++;
        }
        else
        {
            compCount++;
            arr[k] = right[j];
            moveCount++;
            j++;
        }
        k++;
    }

    //Place the remaining elements of first sub array
    while (i < size1)
    {
        arr[k] = left[i];
        moveCount++;
        i++;
        k++;
    }

   //Place the remaining elements of second sub array
    while (j < size2)
    {
        arr[k] = right[j];
        moveCount++;
        j++;
        k++;
    }

}

//implementation of the merge sort algorithm
void sorting::mergeSort(int *arr, int first, int last, int& compCount, int& moveCount)
{

    if (first < last)
    {
        compCount++;
        int mid = first+(last-first)/2;
        moveCount++;

        mergeSort(arr, first, mid, compCount, moveCount);
        mergeSort(arr, mid+1, last, compCount, moveCount);

        merge(arr, first, mid, last, compCount, moveCount);

    }
}

// implementation of swap function to be used in partition of quick sort algorithm, which swaps the
// places of two elements in an array
void sorting::swap(int *a, int *b, int &moveCount)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    moveCount = moveCount + 3;
}

//last element is the pivot. places smaller elements to the left of pivot and greater elements
// to the right of pivot
int sorting::partition(int *arr, int first, int last, int &compCount, int &moveCount)
{
    int pivot = arr[last]; // pivot
    moveCount++;
    int i = (first - 1);
    moveCount++;

    for (int j = first; j <= last-1; j++)
    {
        compCount++;

        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j], moveCount);
        }
    }
    swap(&arr[i + 1], &arr[last], moveCount);
    return (i + 1);
}

//implementation of the quick sort algorithm
void sorting::quickSort(int *arr, int first, int last, int& compCount, int& moveCount)
{
    if (first < last)
    {
        compCount++;

        int pivotIndex = partition(arr, first, last, compCount, moveCount);

        quickSort(arr, first, pivotIndex - 1, compCount, moveCount);
        quickSort(arr, pivotIndex + 1, last, compCount, moveCount);
    }
}

//implementation of hybrid sort algorithm
//starts with quick sort and turns to insertion sort when size of partition becomes less than 10
void sorting::hybridSort(int *arr, int first, int last, int& compCount, int& moveCount)
{
    if(last - first + 1 < 10)
    {
        insertionSort(arr, first, last, compCount, moveCount);
    }
    else
    {
        int pivotIndex = partition(arr, first, last, compCount, moveCount);

        quickSort(arr, first, last, compCount, moveCount);
        quickSort(arr, pivotIndex+1, last, compCount, moveCount);
    }
}

//function that outputs the results of the algorithm to the user
void sorting::performanceAnalysis(int size1)
{
    clock_t start;

    //random arrays
    int *arrForInsertionSortRandom = new int[size1];
    int *arrForMergeSortRandom = new int[size1];
    int *arrForQuickSortRandom = new int[size1];
    int *arrForHybridSortRandom = new int[size1];

    //arrays that are in ascending order
    int *arrForInsertionSortAscending = new int[size1];
    int *arrForMergeSortAscending = new int[size1];
    int *arrForQuickSortAscending = new int[size1];
    int *arrForHybridSortAscending = new int[size1];

    //arrays that are in descending order
    int *arrForInsertionSortDescending = new int[size1];
    int *arrForMergeSortDescending = new int[size1];
    int *arrForQuickSortDescending = new int[size1];
    int *arrForHybridSortDescending = new int[size1];

    //create array with random elements
    for(int i=0; i < size1; i++)
    {
        arrForInsertionSortRandom[i] = rand();
    }
    //copy the random array
    for(int i=0; i < size1; i++)
    {
        arrForMergeSortRandom[i] = arrForInsertionSortRandom[i];
    }
    //copy the random array
    for(int i=0; i < size1; i++)
    {
        arrForQuickSortRandom[i] = arrForInsertionSortRandom[i];
    }
    //copy the random array
    for(int i=0; i < size1; i++)
    {
        arrForHybridSortRandom[i] = arrForInsertionSortRandom[i];
    }

    //analysis for sorting of random array by insertion sort
    int compCount = 0;
    int moveCount = 0;
    start = clock();
    insertionSort(arrForInsertionSortRandom, 0, size1-1, compCount, moveCount);
    double durationOfInsertionSortRandom = ( clock() - start ) / (double) (CLOCKS_PER_SEC/1000);
    int compCountInsertionSortRandom = compCount;
    int moveCountInsertionSortRandom = moveCount;

    //analysis for sorting of random array by merge sort
    compCount = 0;
    moveCount = 0;
    start = clock();
    mergeSort(arrForMergeSortRandom, 0, size1-1, compCount, moveCount);
    double durationOfMergeSortRandom = ( clock() - start ) / (double) (CLOCKS_PER_SEC/1000);
    int compCountMergeSortRandom = compCount;
    int moveCountMergeSortRandom = moveCount;

    //analysis for sorting of random array by quick sort
    compCount = 0;
    moveCount = 0;
    start = clock();
    quickSort(arrForQuickSortRandom, 0, size1-1, compCount, moveCount);
    double durationOfQuickSortRandom = ( clock() - start ) / (double) (CLOCKS_PER_SEC/1000);
    int compCountQuickSortRandom = compCount;
    int moveCountQuickSortRandom = moveCount;

    //analysis for sorting of random array by hybrid sort
    compCount = 0;
    moveCount = 0;
    start = clock();
    hybridSort(arrForHybridSortRandom, 0, size1-1, compCount, moveCount);
    double durationOfHybridSortRandom = ( clock() - start ) / (double) (CLOCKS_PER_SEC/1000);
    int compCountHybridSortRandom = compCount;
    int moveCountHybridSortRandom = moveCount;

    //copying sorted elements to the new array which will consist of ascending order elements
    for(int i=0; i < size1; i++)
    {
        arrForInsertionSortAscending[i] = arrForInsertionSortRandom[i];
    }
    for(int i=0; i < size1; i++)
    {
        arrForMergeSortAscending[i] = arrForMergeSortRandom[i];
    }
    for(int i=0; i < size1; i++)
    {
        arrForQuickSortAscending[i] = arrForQuickSortRandom[i];
    }
    for(int i=0; i < size1; i++)
    {
        arrForHybridSortAscending[i] = arrForHybridSortRandom[i];
    }

    //analysis for sorting of ascending array by insertion sort
    compCount = 0;
    moveCount = 0;
    start = clock();
    insertionSort(arrForInsertionSortAscending, 0, size1-1, compCount, moveCount);
    double durationOfInsertionSortAscending = ( clock() - start ) / (double) (CLOCKS_PER_SEC/1000);
    int compCountInsertionSortAscending = compCount;
    int moveCountInsertionSortAscending = moveCount;

    //analysis for sorting of ascending array by merge sort
    compCount = 0;
    moveCount = 0;
    start = clock();
    mergeSort(arrForMergeSortAscending, 0, size1-1, compCount, moveCount);
    double durationOfMergeSortAscending = ( clock() - start ) / (double) (CLOCKS_PER_SEC/1000);
    int compCountMergeSortAscending = compCount;
    int moveCountMergeSortAscending = moveCount;

    //analysis for sorting of ascending array by quick sort
    compCount = 0;
    moveCount = 0;
    start = clock();
    quickSort(arrForQuickSortAscending, 0, size1-1, compCount, moveCount);
    double durationOfQuickSortAscending = ( clock() - start ) / (double) (CLOCKS_PER_SEC/1000);
    int compCountQuickSortAscending = compCount;
    int moveCountQuickSortAscending = moveCount;

    //analysis for sorting of ascending array by hybrid sort
    compCount = 0;
    moveCount = 0;
    start = clock();
    hybridSort(arrForHybridSortAscending, 0, size1-1, compCount, moveCount);
    double durationOfHybridSortAscending = ( clock() - start ) / (double) (CLOCKS_PER_SEC/1000);
    int compCountHybridSortAscending = compCount;
    int moveCountHybridSortAscending = moveCount;

    //reversing the ascending order array to fain descending order array
    int temp;
    for (int i = 0; i < size1/2; ++i)
    {
    temp = arrForInsertionSortAscending[size1-i-1];
    arrForInsertionSortAscending[size1-i-1] = arrForInsertionSortAscending[i];
    arrForInsertionSortAscending[i] = temp;
    }

    //copying the descending order elements to the new arrays
    for(int i=0; i < size1; i++)
    {
        arrForInsertionSortDescending[i] = arrForInsertionSortAscending[i];
    }

    for (int i = 0; i < size1/2; ++i)
    {
    temp = arrForMergeSortAscending[size1-i-1];
    arrForMergeSortAscending[size1-i-1] = arrForMergeSortAscending[i];
    arrForMergeSortAscending[i] = temp;
    }

     for(int i=0; i < size1; i++)
    {
        arrForMergeSortDescending[i] = arrForMergeSortAscending[i];
    }

    for (int i = 0; i < size1/2; ++i)
    {
    temp = arrForQuickSortAscending[size1-i-1];
    arrForQuickSortAscending[size1-i-1] = arrForQuickSortAscending[i];
    arrForQuickSortAscending[i] = temp;
    }

    for(int i=0; i < size1; i++)
    {
        arrForQuickSortDescending[i] = arrForQuickSortAscending[i];
    }

    for (int i = 0; i < size1/2; ++i)
    {
    temp = arrForHybridSortAscending[size1-i-1];
    arrForHybridSortAscending[size1-i-1] = arrForHybridSortAscending[i];
    arrForHybridSortAscending[i] = temp;
    }

     for(int i=0; i < size1; i++)
    {
        arrForHybridSortDescending[i] = arrForHybridSortAscending[i];
    }

    //analysis for sorting of descending array by insertion sort
    compCount = 0;
    moveCount = 0;
    start = clock();
    insertionSort(arrForInsertionSortDescending, 0, size1-1, compCount, moveCount);
    double durationOfInsertionSortDescending = ( clock() - start ) / (double) (CLOCKS_PER_SEC/1000);
    int compCountInsertionSortDescending = compCount;
    int moveCountInsertionSortDescending = moveCount;

    //analysis for sorting of descending array by merge sort
    compCount = 0;
    moveCount = 0;
    start = clock();
    mergeSort(arrForMergeSortDescending, 0, size1-1, compCount, moveCount);
    double durationOfMergeSortDescending = ( clock() - start ) / (double) (CLOCKS_PER_SEC/1000);
    int compCountMergeSortDescending = compCount;
    int moveCountMergeSortDescending = moveCount;

    //analysis for sorting of descending array by quick sort
    compCount = 0;
    moveCount = 0;
    start = clock();
    quickSort(arrForQuickSortDescending, 0, size1-1, compCount, moveCount);
    double durationOfQuickSortDescending = ( clock() - start ) / (double) (CLOCKS_PER_SEC/1000);
    int compCountQuickSortDescending = compCount;
    int moveCountQuickSortDescending = moveCount;

    //analysis for sorting of descending array by hybrid sort
    compCount = 0;
    moveCount = 0;
    start = clock();
    hybridSort(arrForHybridSortDescending, 0, size1-1, compCount, moveCount);
    double durationOfHybridSortDescending = ( clock() - start ) / (double) (CLOCKS_PER_SEC/1000);
    int compCountHybridSortDescending = compCount;
    int moveCountHybridSortDescending = moveCount;

    //visual output of the gained data from the analysis
    cout << "Performance analysis of for arrays of size " << size1 << endl;
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    cout << "Random Integers          " << "Elapsed Time         " << "compCount                 " << "moveCount" << endl;
    cout << "Insertion Sort           ";
    printf("%5.2f ms", durationOfInsertionSortRandom);
    printf("%20d ", compCountInsertionSortRandom);
    printf("%25d\n ", moveCountInsertionSortRandom);
    cout << "Merge Sort              ";
    printf("%5.2f ms", durationOfMergeSortRandom);
    printf("%20d ", compCountMergeSortRandom);
    printf("%25d\n", moveCountMergeSortRandom);
    cout << "Quick Sort               ";
    printf("%5.2f ms", durationOfQuickSortRandom);
    printf("%20d ", compCountQuickSortRandom);
    printf("%25d\n", moveCountQuickSortRandom);
    cout << "Hybrid Sort              ";
    printf("%5.2f ms", durationOfHybridSortRandom);
    printf("%20d ", compCountHybridSortRandom);
    printf("%25d\n", moveCountHybridSortRandom);

    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    cout << "Ascending Integers       " << "Elapsed Time         " << "compCount                 " << "moveCount" << endl;
    cout << "Insertion Sort           ";
    printf("%5.2f ms", durationOfInsertionSortAscending);
    printf("%20d ", compCountInsertionSortAscending);
    printf("%25d\n ", moveCountInsertionSortAscending);
    cout << "Merge Sort              ";
    printf("%5.2f ms", durationOfMergeSortAscending);
    printf("%20d ", compCountMergeSortAscending);
    printf("%25d\n", moveCountMergeSortAscending);
    cout << "Quick Sort               ";
    printf("%5.2f ms", durationOfQuickSortAscending);
    printf("%20d ", compCountQuickSortAscending);
    printf("%25d\n", moveCountQuickSortAscending);
    cout << "Hybrid Sort              ";
    printf("%5.2f ms", durationOfHybridSortAscending);
    printf("%20d ", compCountHybridSortAscending);
    printf("%25d\n", moveCountHybridSortAscending);

    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    cout << "Descending Integers      " << "Elapsed Time          " << "compCount                " << "moveCount" << endl;
    cout << "Insertion Sort           ";
    printf("%5.2f ms", durationOfInsertionSortDescending);
    printf("%20d ", compCountInsertionSortDescending);
    printf("%25d\n ", moveCountInsertionSortDescending);
    cout << "Merge Sort              ";
    printf("%5.2f ms", durationOfMergeSortDescending);
    printf("%20d ", compCountMergeSortDescending);
    printf("%25d\n", moveCountMergeSortDescending);
    cout << "Quick Sort               ";
    printf("%5.2f ms", durationOfQuickSortDescending);
    printf("%20d ", compCountQuickSortDescending);
    printf("%25d\n", moveCountQuickSortDescending);
    cout << "Hybrid Sort              ";
    printf("%5.2f ms", durationOfHybridSortDescending);
    printf("%20d ", compCountHybridSortDescending);
    printf("%25d\n", moveCountHybridSortDescending);
}








