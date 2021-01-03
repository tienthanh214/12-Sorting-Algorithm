#pragma once
// #include "../extension/utilities.h"

void SelectionSort(int* a, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int pos = i;
        for (int j = i + 1; j < n; ++j) 
            if (a[pos] > a[j]) 
                pos = j;
        std::swap(a[i], a[pos]);
    }
}