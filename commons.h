#pragma once

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    // way 1:
    os << '[';
    char comma[]{'\0', ' ', '\0'};
    for (const auto &e : v) {
        os << comma << e;
        comma[0] = ',';
    }
    return os << ']';

    // way 2:
    // os << '[';
    // if (!v.empty()) {
    // os << v[0];
    // for (int i = 1; i < v.size(); ++i)
    // os << ", " << v[i];
    //}
    // return os << ']';
}
