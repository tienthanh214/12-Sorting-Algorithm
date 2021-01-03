#pragma once
// bubblesort with a little optimize
void BubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int last = n;
        for (int j = n - 1; j > i; --j) 
            if (a[j - 1] > a[j]) {
                last = j - 1;
                std::swap(a[j - 1], a[j]);
            }
        i = last;
    }
}