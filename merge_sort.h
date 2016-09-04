#pragma once
#include "commons.h"

void merge(vector<int> &a, vector<int> &aux, int l, int m, int u) {
    int i = l;     // 左侧数据的下标
    int j = m + 1; // 右侧数组的下标
    int k = l;     // 辅助数组aux的下标
    while (i <= m && j <= u)
        if (a[i] > a[j])
            aux[k++] = a[j++];
        else
            aux[k++] = a[i++];

    while (i <= m)
        aux[k++] = a[i++];
    while (j <= u)
        aux[k++] = a[j++];

    for (int k = l; k <= u; ++k)
        a[k] = aux[k];
}

void merge2(vector<int> &a, vector<int> &aux, int l, int m, int u) {
    int i = l;
    int j = m + 1;

    for (int k = l; k <= u; ++k)
        if (i > m)
            aux[k] = a[j++];
        else if (j > u)
            aux[k] = a[i++];
        else if (a[j] < a[i])
            aux[k] = a[j++];
        else
            aux[k] = a[i++];

    for (int k = l; k <= u; ++k)
        a[k] = aux[k];
}

void merge_sort(vector<int> &a, vector<int> &aux, int l, int u) {
    if (l >= u) return;
    auto m = l + (u - l) / 2;
    merge_sort(a, aux, l, m);
    merge_sort(a, aux, m + 1, u);
    merge2(a, aux, l, m, u);
}

void merge_sort(vector<int> &a) {
    vector<int> aux(a.size());
    merge_sort(a, aux, 0, a.size() - 1);
}
