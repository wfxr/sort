#pragma once
#include "commons.h"

using size_type = vector<int>::size_type;

void merge1(vector<int> &a, vector<int> &aux, size_type l, size_type m, size_type u) {
    auto i = l;     // 左侧数组的下标
    auto j = m + 1; // 右侧数组的下标
    auto k = l;     // 辅助数组aux的下标
    while (i <= m && j <= u)
        if (a[j] < a[i])    // if语句的条件关系排序的稳定性
            aux[k++] = a[j++];
        else
            aux[k++] = a[i++];

    while (i <= m)
        aux[k++] = a[i++];
    while (j <= u)
        aux[k++] = a[j++];

    for (k = l; k <= u; ++k)
        a[k] = aux[k];
}

void merge2(vector<int> &a, vector<int> &aux, size_type l, size_type m, size_type u) {
    auto i = l;
    auto j = m + 1;
    auto k = l;

    while (k <= u)
        if (i > m)
            aux[k++] = a[j++];
        else if (j > u)
            aux[k++] = a[i++];
        else if (a[j] < a[i])
            aux[k++] = a[j++];
        else
            aux[k++] = a[i++];

    for (k = l; k <= u; ++k)
        a[k] = aux[k];
}

void merge_sort1(vector<int> &a, vector<int> &aux, size_type l, size_type u) {
    if (l >= u) return;
    auto m = l + (u - l) / 2;
    merge_sort1(a, aux, l, m);
    merge_sort1(a, aux, m + 1, u);
    merge1(a, aux, l, m, u);
}

void merge_sort2(vector<int> &a, vector<int> &aux, size_type l, size_type u) {
    if (l >= u) return;
    auto m = l + (u - l) / 2;
    merge_sort2(a, aux, l, m);
    merge_sort2(a, aux, m + 1, u);
    merge2(a, aux, l, m, u);
}

void merge_sort1(vector<int> &a) {
    if (a.empty()) return;  // 当a为空时，a.size() - 1会溢出
    vector<int> aux(a.size());
    merge_sort1(a, aux, 0, a.size() - 1);
}

void merge_sort2(vector<int> &a) {
    if (a.empty()) return;  // 当a为空时，a.size() - 1会溢出
    vector<int> aux(a.size());
    merge_sort2(a, aux, 0, a.size() - 1);
}
