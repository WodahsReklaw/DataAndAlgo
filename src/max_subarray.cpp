#include <iostream>
#include <vector>

using std::endl;
using std::cin;
using std::cout;
using std::vector;

const int MAX_ELEM = 1000;
const int MIN_VAL = -100;
const int SENTINEL_SUM = MAX_ELEM*MIN_VAL - 10000;

int MaxArrayValue(const vector<int>& vec) {
  // Pick a max_sum smaller than any possible input.
  // Min possible is -100*1000.
  int max_sum = SENTINEL_SUM;
  int max_right = 0;
  int sum = 0;
  for (int i = 0; i < vec.size(); ++i) {
    sum += vec[i];
    if (sum > max_sum) {
      max_sum = sum;
      max_right = i;
    }
  }
  sum = 0;
  for (int j = max_right; j >= 0; --j) {
    sum += vec[j];
    if (sum > max_sum) {
      max_sum = sum;
    }
  }
  return max_sum;

}

int main() {
  vector<int> input_array = std::vector<int>();
  input_array.reserve(MAX_ELEM);
  int nTestCases = 0;
  int inputVal;

  cin >> nTestCases;
  int nInput;
  for (int testNum = 0; testNum < nTestCases; ++testNum) {
    input_array.clear();
    cin >> nInput;
    for (int inputCount = 0; inputCount < nInput; ++inputCount) {
      cin >> inputVal;
      input_array.push_back(inputVal);

    }
    cout << MaxArrayValue(input_array) << endl;



  }
  return 0;

}
