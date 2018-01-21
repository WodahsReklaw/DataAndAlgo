#ifndef __HEAP_TPP__
#define __HEAP_TPP__

#include <algorithm>
#include <iterator>
#include <vector>

#include <heap.h>

template <typename T>
void heap::MaxHeapify(std::vector<T>& vec, unsigned i){
  unsigned heap_sz = vec.size();
  heap::MaxHeapify(vec, i, heap_sz);
}

template <typename T>
void heap::MaxHeapify(std::vector<T>& vec, unsigned i, unsigned heap_sz){
  unsigned this_index = i;
  unsigned largest = -1;
  while (true) {
    unsigned l = this_index*2 + 1;
    unsigned r = this_index*2 + 2;
    largest = (l < heap_sz and vec[this_index] < vec[l]) ? l : this_index;
    largest = (r < heap_sz and vec[largest] < vec[r]) ? r : largest;
    if (largest != this_index) {
      std::swap(vec[this_index], vec[largest]);
      // Max-Heapify the newchild tree.
      this_index = largest;
    } else {
      return;
    }
  }
}

template <typename T>
void heap::BuildMaxHeap(std::vector<T>& vec) {
  // Reverse iterate on all non-trivial sub-trees calling MaxHeapify.
  for (auto it = vec.rbegin() + vec.size()/2; it != vec.rend(); ++it) {
    const auto heap_index = std::distance(it, vec.rend()) - 1;
    heap::MaxHeapify(vec, heap_index);
  }
}

#endif
