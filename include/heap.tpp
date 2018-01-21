#ifndef __HEAP_TPP__
#define __HEAP_TPP__

#include <algorithm>
#include <vector>

#include <heap.h>

template <typename T>
void heap::MaxHeapify(std::vector<T>& vec, unsigned i){
  unsigned last_largest = -1;
  unsigned largest = i;
  while (largest != last_largest) {
    last_largest = largest;
    unsigned l = largest*2 + 1;
    unsigned r = largest*2 + 2;
    largest = (l < vec.size() and vec[largest] < vec[l]) ? l : largest;
    largest = (r < vec.size() and vec[largest] < vec[r]) ? r : largest;
    if (largest != last_largest) {
      std::swap(vec[i], vec[largest]);
    }
  }
}

#endif
