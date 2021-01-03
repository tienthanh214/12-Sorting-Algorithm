#pragma once

void ShakerSort(int *a, int n) {
    int left = 0;
    int right = n - 1;
    while (left < right) {
        int last = 0;
        for (int i = left; i < right; ++i)
            if (a[i] > a[i + 1]) {
                std::swap(a[i], a[i + 1]);
                last = i;
            }
        right = last;

        for (int i = right; i > left; --i) 
            if (a[i - 1] > a[i]) {
                std::swap(a[i - 1], a[i]);
                last = i;
            }
        left = last;
    }
}