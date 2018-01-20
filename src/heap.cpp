#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

inline unsigned Parent(int i){
  return i/2;
}

inline unsigned LeftChild(unsigned i){
  return i*2 + 1;
}

inline unsigned RightChild(unsigned i){
  return i*2 + 2;
}

void PrintVec(const vector<int>& vec){
  std::cout << "[";
  for (unsigned i = 0; i < vec.size() - 1; ++i) {
    std::cout << vec[i] << ", ";
  }
  std::cout << vec[vec.size()-1] << "]" << std::endl;
}

void MaxHeapify(vector<int>& vec, unsigned i) {
  unsigned l = LeftChild(i);
  unsigned r = RightChild(i);
  unsigned largest = (l < vec.size() and vec[i] < vec[l]) ? l : i;
  largest = (r < vec.size() and vec[largest] < vec[r]) ? r : largest;
  if (largest != i) {
    //std::cout << "i: " << i << "\tl: " << l << "\tr: " << r
    //<< "\tlargest: " << largest << std::endl;
    std::swap(vec[i], vec[largest]);
    //PrintVec(vec);
    MaxHeapify(vec, largest);
    MaxHeapify(vec, i);
  }
}


int main(){

  int iVal = 0;
  vector<int> vec;

  while (std::cin >> iVal) {
    vec.push_back(iVal);
  }
  PrintVec(vec);
  for (unsigned i = 0; i < vec.size(); ++i) {
    MaxHeapify(vec, i);
  }
  PrintVec(vec);
  return 0;
}
