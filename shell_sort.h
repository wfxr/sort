#include "commons.h"

void shell_sort(vector<int> &a) {
    int n = a.size();
    for (int d = n / 2; d >= 1; d /= 2)
        for (int i = d; i < n; ++i)
            for (int j = i; j >= d && a[j] < a[j - d]; j -= d)
                swap(a[j], a[j - d]);
}
