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

  // HeapSort function template.
  template <typename T>
  void HeapSort(std::vector<T>&);

  // QuickSort function template.
  template <typename T>
  void QuickSort(std::vector<T>&);

  template <typename T>
  void RandomizedQuickSort(std::vector<T>&);

  // QuickSort helper partition.
  template <typename T>
  std::size_t Partition(std::vector<T>&, std::size_t p, std::size_t r);
}
#include "sort.tpp"
#include "heap.tpp"

#endif
