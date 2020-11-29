using namespace std;

/* Title: Algorithm Efficiency and Sorting
 * Author: Berk Yýldýz
 * ID: 21502040
 * Section: 2
 * Assignment: 1
 * Description: header file of the project
 */

class sorting
{
public:

    void insertionSort(int *arr, int first, int last, int &compCount, int &moveCount);
    void mergeSort(int *arr, int first, int last, int &compCount, int &moveCount);
    void quickSort(int *arr, int first, int last, int &compCount, int &moveCount);
    void hybridSort(int *arr, int first, int last, int &compCount, int &moveCount);
    void performanceAnalysis(int size1);
    void merge( int *arr, int first, int mid, int last, int &compCount, int &moveCount);
    void swap(int *a, int *b, int &moveCount);
    int partition(int *arr, int first, int last, int &compCount, int &moveCount);

};
