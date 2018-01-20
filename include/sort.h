#ifndef __SORT_H__
#define __SORT_H__
// This header defines a few example sorting functions which will be used
// to practice implenting sorting algorithms.
#include <vector>

namespace sort {

  // InsertionSort function template.
  template <typename T>
  void InsertionSort(std::vector<T>&);

  // MergeSort function template.
  template <typename T>
  void MergeSort(std::vector<T>&);
}
#include "sort.tpp"

#endif
