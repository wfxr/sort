#pragma once
#include "commons.h"

void selection_sort(vector<int> &a) {
    auto n = a.size();
    for (decltype(n) i = 0; i < n; ++i) {
        auto min = i;
        for (decltype(n) j = i + 1; j < n; ++j)
            if (a[j] < a[ min ]) min = j;
        swap(a[i], a[min]);
    }
}
