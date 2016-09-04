#pragma once
#include "commons.h"

void insert_sort1(vector<int> &vec) {
    int n = vec.size();
    for (int i = 1; i < n; ++i)
        for (int j = i; j >= 1 && vec[j] < vec[j - 1]; --j)
            swap(vec[j], vec[j - 1]);
}

void insert_sort2(vector<int> &vec) {
    int n = vec.size();
    for (int i = 1; i < n; ++i) {
        auto t = vec[i];
        int j = i;
        for (; j > 0 && t < vec[j - 1]; --j)
            vec[j] = vec[j - 1];
        vec[j] = t;
    }
}
