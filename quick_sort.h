#include "commons.h"

void quick_sort1(vector<int> &a, int l, int u) {
    if (l >= u) return;
    auto t = a[l];
    auto i = l + 1, j = u;
    while (i <= j) {
        if (a[j] < t)
            swap(a[i++], a[j]);
        else
            --j;
    }
    swap(a[l], a[j]);
    quick_sort1(a, l, j - 1);
    quick_sort1(a, j + 1, u);
}

void quick_sort2(vector<int> &a, int l, int u) {
    if (l >= u) return;
    auto t = a[l];
    auto i = l, j = u + 1;
    for (;;) {
        do ++i; while (i <= u && a[i] < t);
        // 因为j向左移动时必然经过t，此时a[j] > t不成立，循环结束
        do --j; while (a[j] > t);
        if (i > j) break;
        // i指向的是（从前往后）第一个大于t的元素
        // j指向的是（从后往前）第一个小于t的元素
        swap(a[i], a[j]);
    }

    swap(a[l], a[j]);
    quick_sort2(a, l, j - 1);
    quick_sort2(a, j + 1, u);
}

void quick_sort1(vector<int> &a) { quick_sort1(a, 0, a.size() - 1); }
void quick_sort2(vector<int> &a) { quick_sort2(a, 0, a.size() - 1); }