#pragma once

void CountingSort(int a[], int n) {
    int* b = new int[n];
    int* cnt = new int[n]{}; // a[i] in range [0..n)
    for (int i = 0; i < n; ++i)
        ++cnt[a[i]];
    for (int i = 1; i < n; ++i)
        cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; --i)
        b[--cnt[a[i]]] = a[i];
    for (int i = 0; i < n; ++i)
        a[i] = b[i];        
    delete[] b;
    delete[] cnt;
}