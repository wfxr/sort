#pragma once
#include "commons.h"

// 对大小为n的堆中最后一个元素执行上浮操作
void shift_up(vector<int> &a, int n) {
    for (int i = n - 1; i > 0;) {
        auto c = (i - 1) / 2; // i 的父节点
        if (a[i] < a[c]) break;
        swap(a[c], a[i]);
        i = c;
    }
}

// 对大小为n的堆中第i个元素执行下沉操作
void shift_down(vector<int> &a, int n, int i = 0) {
    for (;;) {
        auto c = 2 * i + 1;
        // c是左子节点
        if (c >= n) break;
        // c+1是右子节点
        if (c + 1 < n && a[c] < a[c + 1]) ++c;
        // c现在是左右子节点中较大的那个
        if (a[c] < a[i]) break;
        swap(a[i], a[c]);
        i = c;
    }
}

// 通过上浮构建堆
void heap_sort1(vector<int> &a) {
    auto n = a.size();
    for (decltype(n) heap_size = 2; heap_size <= n; ++heap_size)
        shift_up(a, heap_size);
    while (n > 1) {
        swap(a[0], a[--n]);
        shift_down(a, n);
    }
}

// 通过下沉构建堆
void heap_sort2(vector<int> &a) {
    auto n = a.size();
    // 可以通过从倒数第二层开始依次往上执行下沉操作来恢复堆，
    // 因为最下面一层节点没有子节点，已经是堆
    // n / 2 - 1是最后一个节点的父节点，即倒数第二层的最后一个节点
    for (int i = n / 2 - 1; i >= 0; --i)
        shift_down(a, n, i);
    while (n > 1) {
        swap(a[0], a[--n]);
        shift_down(a, n);
    }
}
