#pragma once

void QS_partition(int a[], int l, int r) {
    if (l >= r) return;
    int i = l, j = r;
    int pivot = a[l + r >> 1];
    do {
        while (a[i] < pivot) ++i;
        while (a[j] > pivot) --j;
        if (i <= j) 
            std::swap(a[i++], a[j--]);
    } while (i <= j);
    QS_partition(a, l, j);
    QS_partition(a, i, r);
}

void QuickSort(int a[], int n) {
    QS_partition(a, 0, n - 1);
}