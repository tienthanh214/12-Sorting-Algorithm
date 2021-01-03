#pragma once
#include <algorithm>

template<typename T>
void Swap(T &x, T &y) {
    T tmp = x;
    x = y;
    y = tmp;
}

int Rand(int l, int r) {
    return l + (1ll * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                1ll * rand() * (RAND_MAX + 1) +
                1ll * rand()) % (r - l + 1);
}

bool checker(int a[], int b[], int n) {
    int* c = new int[n];
    for (int i = 0; i < n; ++i)
        c[i] = b[i];
    std::sort(c, c + n);
    bool flag = true;
    for (int i = 0; i < n; ++i)
        if (c[i] != a[i])
            flag = false;
    delete[] c;
    return flag;
}
