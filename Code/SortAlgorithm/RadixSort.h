#pragma once

void MSDradixSort(int a[], int l, int r, int offset) {
    if (l >= r) return;
    if (offset == -1) return;
    int i = l, j = r;
    do {
        while ((i <= j) && (!(a[i] >> offset & 1))) 
            ++i;
        while ((i <= j) && (a[j] >> offset & 1))
            --j;
        if (i <= j) 
            std::swap(a[i], a[j]);
    } while (i <= j);
    MSDradixSort(a, l, j, offset - 1);
    MSDradixSort(a, i, r, offset - 1);
}

void RadixSort(int a[], int n) {
    int maxA = a[0];
    for (int i = 1; i < n; ++i)
        if (maxA < a[i]) maxA = a[i];
    int d = 0;
    while ((1 << d) <= maxA) ++d;
    MSDradixSort(a, 0, n - 1, d);
}