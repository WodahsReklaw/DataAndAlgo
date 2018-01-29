#ifndef __SORT_TPP__
#define __SORT_TPP__

#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

#include "sort.h"
#include "heap.h"

template <typename T>
void sort::HeapSort(std::vector<T>& vec) {

  if (vec.size() < 2) {
    return;
  }
  heap::BuildMaxHeap(vec);
  for (auto i = vec.size() - 1; i != 0; --i) {
    std::swap(vec[0], vec[i]);
    heap::MaxHeapify(vec, 0, i);
  }
}

template <typename T>
void sort::InsertionSort(std::vector<T>& vec) {

  const auto vec_size = vec.size();
  // Vector is already sorted since it has one element, or is empty.
  if (vec_size < 2){
    return;
  }
  // For every element in V_i check if V_(i-1) is > V, if so swap.
  // The main iadea is we are going to _insert_ the value key
  // into the sorted position.
  for (auto i = 1; i < vec_size; ++i){
    T key = vec[i];
    auto j = i - 1;
    // Continue this loop until we found where to insert
    // the key.
    while(j >= 0 && vec[j] > key){
      vec[j + 1] = vec[j];
      --j;
    }
    vec[j+1] = key;
  }
}

template <typename T>
void Merge(std::vector<T>& vec, std::size_t p, std::size_t q, std::size_t r) {
  std::vector<T> left_vec = std::vector<T>(vec.begin() + p, vec.begin() + q);
  std::vector<T> right_vec = std::vector<T>(vec.begin() + q, vec.begin() + r);
  std::size_t l_index = 0;
  std::size_t r_index = 0;
  std::size_t i = p;
  while (l_index < left_vec.size() and r_index < right_vec.size()) {
    if (left_vec[l_index] < right_vec[r_index]) {
      vec[i] = left_vec[l_index];
      ++l_index;
    } else {
      vec[i] = right_vec[r_index];
      ++r_index;
    }
    ++i;
  }
  while (l_index < left_vec.size()){
    vec[i] = left_vec[l_index];
    ++i;
    ++l_index;
  }
  while (r_index < right_vec.size()){
    vec[i] = right_vec[r_index];
    ++i;
    ++r_index;
  }
}

// The main work of our MergeSort will be done here recursively calling,
// MergeSortHelper to break up our problem into smaller sub-problems.
template <typename T>
void MergeSortHelper(std::vector<T>& vec, std::size_t p, std::size_t r) {
  if (r - p > 1) {
    auto q = (p+r)/2;
    MergeSortHelper(vec, p, q);
    MergeSortHelper(vec, q, r);
    Merge(vec, p, q, r);
  }
}

template <typename T>
void sort::MergeSort(std::vector<T>& vec){
  if (vec.size() > 0) {
    MergeSortHelper(vec, 0, vec.size());
  }
}

template <typename T>
std::size_t sort::Partition(std::vector<T>& vec, std::size_t p, std::size_t r) {
  auto x = vec[r];
  std::size_t i = p;
  for (auto j = p; j < r; ++j) {
    if (vec[j] <= x) {
      std::swap(vec[i], vec[j]);
      ++i;
    }
  }
  std::swap(vec[i], vec[r]);
  return i;
}

template <typename T>
void QuickSortHelper(std::vector<T>& vec, std::size_t p, std::size_t r) {
  if (p < r) {
    std::size_t q = sort::Partition(vec, p, r);
    if (q != 0) {
      QuickSortHelper(vec, p, q-1);
    }
    QuickSortHelper(vec, q+1, r);
  }
}

template <typename T>
std::size_t RandomPartition(std::vector<T>& vec, std::size_t p, std::size_t r) {
  std::size_t j = ((r*7621 + 1) % 32768) % (r - p + 1);
  std::swap(vec[r], vec[j+p]);
  return sort::Partition(vec, p, r);
 }

template <typename T>
void RandQuickSortHelper(std::vector<T>& vec, std::size_t p, std::size_t r) {
  if (p < r) {
    std::size_t q = RandomPartition(vec, p, r);
    if (q != 0) {
      RandQuickSortHelper(vec, p, q-1);
    }
    RandQuickSortHelper(vec, q+1, r);
  }
}

template <typename T>
void sort::RandomizedQuickSort(std::vector<T>& vec) {
  if (vec.size() > 1) {
    RandQuickSortHelper(vec, 0, vec.size()-1);
  }
  return;
}

template <typename T>
void sort::QuickSort(std::vector<T>& vec) {
  if (vec.size() > 1) {
    QuickSortHelper(vec, 0, vec.size()-1);
  }
  return;
}

#endif
