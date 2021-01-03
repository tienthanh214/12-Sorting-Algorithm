#pragma once

#include <queue>

// void HeapSort(int a[], int n) {
//     std::priority_queue<int> heap;
//     for (int i = 0; i < n; ++i)
//         heap.push(a[i]);
//     while (heap.size()) {
//         a[--n] = heap.top();
//         heap.pop();    
//     }
// }

void heapify(int *a, int i, int n) { // heaptify [i..n)
    int root = i;
    int child = root << 1 | 1;
    int value = a[i];
    while (child < n) {
        if (child < n - 1 && a[child] < a[child + 1])
            ++child;
        if (value >= a[child]) break;
        a[root] = a[child];
        root = child;
        child = root << 1 | 1;
    }
    a[root] = value;
}

void HeapSort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(a, i, n);
    for (int i = n - 1; i >= 0; --i)
        std::swap(a[0], a[i]),
        heapify(a, 0, i);
}