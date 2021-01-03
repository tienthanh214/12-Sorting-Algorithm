#pragma once

int findPosition(int a[], int h, int val) {
    int l = 0;
    int pos = 0;
    while (l <= h) {
        int mid = l + h >> 1;
        if (a[mid] < val) {
            l = mid + 1;
            pos = mid;
        } else {
            h = mid - 1;
        }
    }
    return pos;
}

void BinaryInsertionSort(int a[], int n) {
    for (int i = 1; i < n; ++i) {
        int pos = findPosition(a, i - 1, a[i]);
        for (int j = i; j > pos; --j)
            a[j] = a[j - 1];
        a[pos] = a[i];
    }
}