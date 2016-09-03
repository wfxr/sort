#include "commons.h"

void shell_sort(vector<int> &vec) {
    int n = vec.size();
    for (int d = n / 2; d >= 1; d /= 2)
        for (int i = d; i < n; ++i)
            for (int j = i; j >= d && vec[j] < vec[j - d]; j -= d)
                swap(vec[j], vec[j - d]);
}
