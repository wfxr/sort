#pragma once
#include "commons.h"

/*
 * 冒泡排序
 */
void bubble_sort(vector<int> &a) {
    auto n = a.size();
    for (decltype(n) i = 0; i < n; ++i)
        for (auto j = i + 1; j < n; ++j)
            if (a[j] < a[i]) swap(a[j], a[i]);
}
