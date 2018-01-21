#include <vector>

#include "gtest/gtest.h"
#include "heap.h"

namespace {
  using std::vector;

  TEST(TestMaxHeapify, MaxHeapifyInts) {
    vector<int> simple_vec{1, 2, 3, 4, 5};
    vector<int> simple_ans{3, 2, 1, 4, 5};
    heap::MaxHeapify(simple_vec, 0);
    EXPECT_EQ(simple_vec, simple_ans);
  }
  TEST(TestMaxHeapify, SortInts) {
    vector<int> simple_vec{1, 2, 3, 4, 5};
    vector<int> simple_ans{3, 2, 1, 4, 5};
    heap::MaxHeapify(simple_vec, 0);
    EXPECT_EQ(simple_vec, simple_ans);
  }
}
