#pragma once

void InsertionSort(int a[], int n) {
    for (int i = 1; i < n; ++i) {
        int pos = i;
        int val = a[i];
        while (pos > 0 && a[pos - 1] > val) {
            a[pos] = a[pos - 1]; 
            --pos;
        }
        a[pos] = val;
    }
}
