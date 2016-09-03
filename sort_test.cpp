#include "commons.h"
#include "heap_sort.h"
#include "insert_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "shell_sort.h"
#include <functional>
#include <gtest/gtest.h>

using namespace std;

class SortTest : public testing::TestWithParam<vector<int>> {};

vector<vector<int>> params{
    {},
    {0},
    {1, 1, 1},
    {0, 1, 2, 3},
    {3, 2, 1, -1},
    {5, 2, 9, 5, 2, 4, 8, 41, 1, 3, 65, 85, 89, 5, 14, 52, 362, 32},
};

INSTANTIATE_TEST_CASE_P(Test, SortTest, testing::ValuesIn(params));

TEST_P(SortTest, InsertSort1) {
    auto expected = GetParam();
    auto actual = expected;
    sort(expected.begin(), expected.end());
    insert_sort1(actual);
    EXPECT_EQ(expected, actual);
}

TEST_P(SortTest, InsertSort2) {
    auto expected = GetParam();
    auto actual = expected;
    sort(expected.begin(), expected.end());
    insert_sort2(actual);
    EXPECT_EQ(expected, actual);
}

TEST_P(SortTest, ShellSort) {
    auto expected = GetParam();
    auto actual = expected;
    sort(expected.begin(), expected.end());
    shell_sort(actual);
    EXPECT_EQ(expected, actual);
}

TEST_P(SortTest, MergeSort) {
    auto expected = GetParam();
    auto actual = expected;
    sort(expected.begin(), expected.end());
    merge_sort(actual);
    EXPECT_EQ(expected, actual);
}

TEST_P(SortTest, QuickSort1) {
    auto expected = GetParam();
    auto actual = expected;
    sort(expected.begin(), expected.end());
    quick_sort1(actual);
    EXPECT_EQ(expected, actual);
}

TEST_P(SortTest, QuickSort2) {
    auto expected = GetParam();
    auto actual = expected;
    sort(expected.begin(), expected.end());
    quick_sort2(actual);
    EXPECT_EQ(expected, actual);
}

TEST_P(SortTest, HeapSort1) {
    auto expected = GetParam();
    auto actual = expected;
    sort(expected.begin(), expected.end());
    heap_sort1(actual);
    EXPECT_EQ(expected, actual);
}

TEST_P(SortTest, HeapSort2) {
    auto expected = GetParam();
    auto actual = expected;
    sort(expected.begin(), expected.end());
    heap_sort2(actual);
    EXPECT_EQ(expected, actual);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
