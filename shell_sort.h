#pragma once
#include "commons.h"

void shell_sort(vector<int> &a) {
    auto n = a.size();
    for (auto d = n / 2; d >= 1; d /= 2)
        for (auto i = d; i < n; ++i)
            for (auto j = i; j >= d && a[j] < a[j - d]; j -= d)
                swap(a[j], a[j - d]);
}
