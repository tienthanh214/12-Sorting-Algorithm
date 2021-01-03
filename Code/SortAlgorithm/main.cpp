#include <assert.h>
#include <time.h>
#include <string.h>

#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>

#include "SortLib.h"

using namespace std;

typedef void (*sortAlgorithm)(int*, int);

const sortAlgorithm SORT_ALGORITHM[] = {SelectionSort, InsertionSort, BinaryInsertionSort, BubbleSort, ShakerSort, ShellSort,
                         HeapSort, MergeSort, QuickSort, CountingSort, RadixSort, FlashSort};

const string NAME[] = {"Selection Sort", "Insertion Sort", "Binary Insertion Sort", "Bubble Sort", "Shaker Sort", "Shell Sort",
                       "Heap Sort", "Merge Sort", "Quick Sort", "Counting Sort", "Radix Sort", "Flash Sort"};

const int DATA_SIZE[] = {3000, 10000, 30000, 100000, 300000};

const int numberOfSortAlgorithm = sizeof(SORT_ALGORITHM) / sizeof(sortAlgorithm);

enum Data {RandomData, SortedData, ReverseData, NearlySortedData};

void runSortAlgorithm(int a[], int n, sortAlgorithm Sort, string sortName) {
    cerr << setw(25) << left << sortName;
    cerr << right << ":";
    auto start = std::chrono::high_resolution_clock::now();
    Sort(a, n);
    auto end = std::chrono::high_resolution_clock::now();
    cerr << setw(30) << right ;
    cerr << fixed << setprecision(6) << std::chrono::duration<double, std::milli>(end - start).count() << " milliseconds" << endl;
    //cout << right << setw(30);
    //cout << sortName << "," << fixed << setprecision(6) << std::chrono::duration<double, std::milli>(end - start).count() << endl;
}

int main() {
    // freopen("result.csv", "w", stdout);
    for (int dataOrder = 0; dataOrder < 4; ++dataOrder) {
        switch (dataOrder) {
            case 0: 
                cerr << "=====================> Random data <=====================" << endl; 
                //cout << "RANDOM DATA" << endl;
                break;
            case 1: 
                cerr << "=====================> Sorted data <=====================" << endl; 
                //cout << "SORTED DATA" << endl; 
                break;
            case 2: 
                cerr << "=====================> Reverse data <=====================" << endl; 
                //cout << "REVERSE DATA" << endl; 
                break;
            case 3: 
                cerr << "=====================> Nearly sorted data <=====================" << endl; 
                //cout << "NEARLY SORTED DATA" << endl; 
                break;
        }
        
        for (int dataSize : DATA_SIZE) {
            cerr << "Number of elements = " << dataSize << endl << endl;
            //cout << "Number of elements = " << dataSize << endl;
            //cout << "Sort algorithm,Run time (milliseconds)" << endl;
            int *source = new int[dataSize];
            int *a = new int[dataSize];
            GenerateData(source, dataSize, dataOrder);
            for (int i = 0; i < numberOfSortAlgorithm; ++i) {
                memcpy(a, source, dataSize * sizeof(int));
                runSortAlgorithm(a, dataSize, SORT_ALGORITHM[i], NAME[i]);
                assert(is_sorted(a, a + dataSize));
            }
            delete[] source;
            delete[] a;
            cerr << " *********************************************** " << endl;
            //cout << endl;
        }
        cerr << endl;
        // cout << endl << endl;
    }
    return 0;
}
