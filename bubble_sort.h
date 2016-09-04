#pragma once
#include "commons.h"

/*
 * 冒泡排序
 */
void bubble_sort1(vector<int> &a) {
    auto n = a.size();
    for (decltype(n) i = 0; i < n; ++i)
        for (auto j = n - 1; j > i; --j)
            if (a[j] < a[j - 1]) swap(a[j], a[j - 1]);
}

/*
 * 改进的冒泡排序
 */
void bubble_sort2(vector<int> &a) {
    auto n = a.size();
    auto flag = false;
    for (decltype(n) i = 0; i < n; ++i) {
        if (flag) return;
        flag = true;
        for (auto j = n - 1; j > i; --j)
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                flag = false;
            }
    }
}
