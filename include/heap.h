#ifndef __HEAP_H__
#define __HEAP_H__

#include <vector>

namespace heap {

  template <typename T>
  void MaxHeapify(std::vector<T>& vec, unsigned root);

  template <typename T>
  void MaxHeapify(std::vector<T>& vec, unsigned root, unsigned heap_size);

  template <typename T>
  void BuildMaxHeap(std::vector<T>& vec);

}
#include "heap.tpp"

#endif
