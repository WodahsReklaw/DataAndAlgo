#ifndef __HEAP_H__
#define __HEAP_H__

#include <vector>

namespace heap {
  template <typename T>
  void MaxHeapify(std::vector<T>& vec, unsigned root);

  template <typename T>
  void MaxHeapify(std::vector<T>& vec, unsigned root, unsigned heap_size);
}
#include "heap.tpp"

#endif
