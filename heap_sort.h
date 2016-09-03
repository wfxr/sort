#include "commons.h"

void shift_up(vector<int> &a, int n) {
    int i = n - 1;
    while (i != 0) {
        auto p = (i - 1) / 2;
        if (a[p] < a[i]) {
            swap(a[p], a[i]);
            i = p;
        } else
            break;
    }
}

void shift_down(vector<int> &a, int n) {
    auto i = 0;
    for (;;) {
        auto c = i * 2 + 1;
        // c是左子节点
        if (c >= n) break;
        // c+1是右子节点
        if (c + 1 < n)
            if (a[c + 1] > a[c]) ++c;
        // c现在是左右子节点中较大的那个
        if (a[i] > a[c]) break;
        swap(a[i], a[c]);
        i = c;
    }
}

void heap_sort(vector<int> &a) {
    for (size_t n = 2; n <= a.size(); ++n)
        shift_up(a, n);
    for (size_t n = a.size(); n >= 2; --n) {
        swap(a[0], a[n - 1]);
        shift_down(a, n - 1);
    }
}
