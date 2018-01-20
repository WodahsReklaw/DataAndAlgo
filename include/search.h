#ifndef __SEARCH_H__
#define __SEARCH_H__

#include <iterator>

namespace search {
  template <typename FIter, typename T>
  FIter find(const FIter& start, const FIter& end, const T& val,
             std::forward_iterator_tag) {
    for (auto it = start; it != end; ++it) {
      if (*it == val) {
        return it;
      }
    }
    return end;
  }

  template <typename RAIter>
  RAIter find(RAIter start, RAIter end, std::random_access_iterator_tag)
  {

  }

  template< class Iter >
  void alg(Iter first, Iter last)
  {
    alg(first, last,
        typename std::iterator_traits<Iter>::iterator_category());

  }

}
