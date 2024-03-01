
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <ctime>
using namespace std;


// This function takes last element as pivot, places 
// the pivot element at its correct
// position in sorted array, and 
// places all smaller (smaller than pivot)
// to left of pivot and all greater 
// elements to right of pivot

template <typename T1, typename T2> 
T2 partition(T1 arr[], T2 low, T2 high)
{
    swap(arr[low], arr[high]);
    int pivot = arr[high];                          
    int i = (low - 1);                             // Index of smaller element
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Generates Random Pivot, swaps pivot with
// end element and calls the partition function
template <typename T1, typename T2>
int partition_r(T1* arr, T2 low, T2 high) {
    srand(time(NULL));
    T2 random = low + rand() % (high - low);
    swap(arr[random], arr[high]);
    return partition(arr, low, high);
};


double* fillArray(int size) {
    double* massive;
    massive = new double[size];
    srand(time(NULL));
    cout << "Unsorted array: " << endl;
    for (int i = 0; i < size; i++)
    {
        massive[i] = rand() % 100;
        cout << massive[i] << " ";
    }
    cout << endl;
    return massive;
}

/* The main function that implements
QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
template <typename T1, typename T2>
void quickSort(T1* arr, T2 low, T2 high)
{
    
    if (low < high) {
        /* pi is partitioning index,
        arr[p] is now
        at right place */
        int pi = partition_r(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


// A template to implement bubble sort 
template <typename T>
void bubbleSort(T* arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place 
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

template <typename T>
void printArray(T* arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

template <typename T>
void insertionSort(T* arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1],
        // that are greater than key, 
        // to one position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


int main()
{
    unsigned int start_time = clock();
    /* Implementation QuickSort using Lomuto's partition Scheme */
    int n;
    cout << "Input size of array: ";
    cin >> n;
    cout << "Implementation QuickSort: " << endl;
    double *massive = fillArray(n);

    quickSort(massive, 0, n - 1);
    printf("Sorted array: \n");
    printArray(massive, n);
    unsigned int end_time = clock();
    unsigned int search_time = start_time - end_time;
    cout << search_time << endl;

    /* Implementation Bubble Sort */
    start_time = clock();
    cout << "Implementation Bubble Sort: " << endl;
    bubbleSort(massive, n);
    cout << "Sorted array: \n";
    printArray(massive, n);
    end_time = clock();
    search_time = start_time - end_time;
    cout << search_time << endl;

    /* Implementation Insertion Sort */
    start_time = clock();
    cout << "Implementation Insertion Sort: " << endl;
    bubbleSort(massive, n);
    cout << "Sorted array: \n";
    insertionSort(massive, n);
    printArray(massive, n);
    end_time = clock();
    search_time = start_time - end_time;
    cout << search_time << endl;
 
    delete[] massive;
    return 0;
}

