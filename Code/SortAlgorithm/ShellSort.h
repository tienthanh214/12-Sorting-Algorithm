#pragma once
#include <iostream>

void ShellSort(int a[], int n) {
    for (int gap = n / 2; gap; gap >>= 1) {
        for (int i = gap; i < n; ++i) {
            int pos = i;
            int val = a[i];
            while (pos >= gap && a[pos - gap] > val) {
                a[pos] = a[pos - gap];
                pos -= gap;
            }
            a[pos] = val;
        }
    }
}