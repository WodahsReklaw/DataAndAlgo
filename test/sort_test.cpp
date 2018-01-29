#include <algorithm>
#include <functional>
#include <random>
#include <vector>

#include "gtest/gtest.h"
#include "sort.h"


namespace {
  using std::vector;
  TEST(TestInsertionSort, SortInts) {
    vector<int> simple_vec{5, 4, 3, 2, 1};
    vector<int> simple_ans{1, 2, 3, 4, 5};
    sort::InsertionSort(simple_vec);
    EXPECT_EQ(simple_vec, simple_ans);
  }

  TEST(TestInsertionSort, SortEmpty) {
    vector<int> empty{};
    vector<int> empty_cpy{empty};
    sort::InsertionSort(empty);
    EXPECT_EQ(empty, empty_cpy);
  }

  TEST(TestInsertionSort, SortTrivial) {
    vector<int> trivial{1};
    vector<int> trivial_cpy{trivial};
    sort::InsertionSort(trivial);
    EXPECT_EQ(trivial, trivial_cpy);
  }

  TEST(TestInsertionSort, SortManyDoubles) {
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(-1000, 1000);
    auto rand = std::bind(distribution, generator);
    vector<double> vec;
    for (int i = 0; i < 5000; ++i) {
      int d = rand();
      vec.push_back(d);
    }
    vector<double> expected_ans = vec;
    EXPECT_EQ(vec, expected_ans);
    std::sort(expected_ans.begin(), expected_ans.end());
    sort::InsertionSort(vec);
    EXPECT_EQ(vec, expected_ans);
  }

  TEST(TestMergeSort, SortInts) {
    vector<int> simple_vec{5, 4, 3, 2, 1};
    vector<int> simple_ans{1, 2, 3, 4, 5};
    sort::MergeSort(simple_vec);
    EXPECT_EQ(simple_vec, simple_ans);
  }

  TEST(TestMergeSort, SortEmpty) {
    vector<int> empty{};
    vector<int> empty_cpy{empty};
    sort::MergeSort(empty);
    EXPECT_EQ(empty, empty_cpy);
  }

  TEST(TestMergeSort, SortTrivial) {
    vector<int> trivial{1};
    vector<int> trivial_cpy{trivial};
    sort::MergeSort(trivial);
    EXPECT_EQ(trivial, trivial_cpy);
  }

  TEST(TestMergeSort, SortManyDoubles) {
    std::default_random_engine generator(1);
    std::uniform_real_distribution<double> distribution(-1000, 1000);
    auto rand = std::bind(distribution, generator);
    vector<double> vec;
    for (int i = 0; i < 100000; ++i) {
      int d = rand();
      vec.push_back(d);
    }
    vector<double> expected_ans = vec;
    EXPECT_EQ(vec, expected_ans);
    std::sort(expected_ans.begin(), expected_ans.end());
    sort::MergeSort(vec);
    EXPECT_EQ(vec, expected_ans);
  }

  TEST(TestHeapSort, SortInts) {
    vector<int> simple_vec{5, 4, 3, 2, 1};
    vector<int> simple_ans{1, 2, 3, 4, 5};
    sort::HeapSort(simple_vec);
    EXPECT_EQ(simple_vec, simple_ans);
  }

  TEST(TestHeapSort, SortEmpty) {
    vector<int> empty{};
    vector<int> empty_cpy{empty};
    sort::HeapSort(empty);
    EXPECT_EQ(empty, empty_cpy);
  }

  TEST(TestHeapSort, SortTwo) {
    vector<int> trivial{1, 0};
    vector<int> trivial_ans{0, 1};
    sort::HeapSort(trivial);
    EXPECT_EQ(trivial, trivial_ans);
  }

  TEST(TestHeapSort, SortManyDoubles) {
    std::default_random_engine generator(1);
    std::uniform_real_distribution<double> distribution(-1000, 1000);
    auto rand = std::bind(distribution, generator);
    vector<double> vec;
    for (int i = 0; i < 100000; ++i) {
      int d = rand();
      vec.push_back(d);
    }
    vector<double> expected_ans = vec;
    EXPECT_EQ(vec, expected_ans);
    std::sort(expected_ans.begin(), expected_ans.end());
    sort::HeapSort(vec);
    EXPECT_EQ(vec, expected_ans);
  }

  TEST(TestQuickSort, Partition) {
    vector<int> simple_vec{5, 4, 3, 2, 1};
    std::size_t a = sort::Partition(simple_vec, 0, 4);
    EXPECT_EQ(a, 0);
  }

  TEST(TestQuickSort, SortInts) {
    vector<int> simple_vec{5, 4, 3, 2, 1};
    vector<int> simple_ans{1, 2, 3, 4, 5};
    sort::QuickSort(simple_vec);
    EXPECT_EQ(simple_vec, simple_ans);
  }

  TEST(TestQuickSort, SortEmpty) {
    vector<int> empty{};
    vector<int> empty_cpy{empty};
    sort::QuickSort(empty);
    EXPECT_EQ(empty, empty_cpy);
  }

  TEST(TestQuickSort, SortTwo) {
    vector<int> trivial{1, 0};
    vector<int> trivial_ans{0, 1};
    sort::QuickSort(trivial);
    EXPECT_EQ(trivial, trivial_ans);
  }

  TEST(TestQuickSort, SortManyDoubles) {
    std::default_random_engine generator(1);
    std::uniform_real_distribution<double> distribution(-1000, 1000);
    auto rand = std::bind(distribution, generator);
    vector<double> vec;
    for (int i = 0; i < 100000; ++i) {
      int d = rand();
      vec.push_back(d);
    }
    vector<double> expected_ans = vec;
    EXPECT_EQ(vec, expected_ans);
    std::sort(expected_ans.begin(), expected_ans.end());
    sort::QuickSort(vec);
    EXPECT_EQ(vec, expected_ans);
  }

  TEST(TestRandQuickSort, SortManyDoubles) {
    std::default_random_engine generator(1);
    std::uniform_real_distribution<double> distribution(-1000, 1000);
    auto rand = std::bind(distribution, generator);
    vector<double> vec;
    for (int i = 0; i < 100000; ++i) {
      int d = rand();
      vec.push_back(d);
    }
    vector<double> expected_ans = vec;
    EXPECT_EQ(vec, expected_ans);
    std::sort(expected_ans.begin(), expected_ans.end());
    sort::RandomizedQuickSort(vec);
    EXPECT_EQ(vec, expected_ans);
  }
}
