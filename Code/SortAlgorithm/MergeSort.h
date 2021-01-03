#pragma once

#include <algorithm>

void partition(int* a, int l, int r) {
    if (l >= r) return;
    int mid = l + r >> 1;
    partition(a, l, mid);
    partition(a, mid + 1, r);
    std::inplace_merge(a + l, a + mid + 1, a + r + 1);
}

void MergeSort(int* a, int n) {
    partition(a, 0, n - 1);
}