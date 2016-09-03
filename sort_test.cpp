#include "commons.h"
#include "insert_sort.cpp"
#include "shell_sort.cpp"
#include "merge_sort.cpp"
#include <gtest/gtest.h>

using namespace std;

const vector<int> vec{5, 2,  9,  5,  2, 4,  8,  41,  1,
                      3, 65, 85, 89, 5, 14, 52, 362, 32};

TEST(Test, InsertSort1) {
    auto v = vec;
    insert_sort1(v);
    ASSERT_TRUE(is_sorted(v.begin(), v.end()))
        << endl << "before: " << vec
        << endl << " after: " << v;
}

TEST(Test, InsertSort2) {
    auto v = vec;
    insert_sort2(v);
    ASSERT_TRUE(is_sorted(v.begin(), v.end()))
        << endl << "before: " << vec
        << endl << " after: " << v;
}

TEST(Test, ShellSort) {
    auto v = vec;
    shell_sort(v);
    ASSERT_TRUE(is_sorted(v.begin(), v.end()))
        << endl << "before: " << vec
        << endl << " after: " << v;
}

TEST(Test, MergeSort) {
    auto v = vec;
    merge_sort(v);
    ASSERT_TRUE(is_sorted(v.begin(), v.end()))
        << endl << "before: " << vec
        << endl << " after: " << v;
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
