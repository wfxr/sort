#pragma once
#include "commons.h"

void insert_sort1(vector<int> &a) {
    auto n = a.size();
    for (decltype(n) i = 1; i < n; ++i)
        for (auto j = i; j > 0 && a[j] < a[j - 1]; --j)
            swap(a[j], a[j - 1]);
}

void insert_sort2(vector<int> &a) {
    auto n = a.size();
    for (decltype(n) i = 1; i < n; ++i) {
        auto t = a[i];
        auto j = i;
        for (; j > 0 && t < a[j - 1]; --j)
            a[j] = a[j - 1];
        a[j] = t;
    }
}
