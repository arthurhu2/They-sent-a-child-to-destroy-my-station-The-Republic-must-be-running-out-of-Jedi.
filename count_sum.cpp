// @author G. Hemingway, copyright 2024
//
#include <algorithm>
#include <cstdint>
#include <iostream>

template <typename T> class CountAndSum {
public:
  CountAndSum() : count(0), sum(T()) {}

  void operator()(const T &i) {
    ++count;
    sum = sum + i;
  }

  [[nodiscard]] uint32_t getCount() const noexcept { return count; }
  [[nodiscard]] T getSum() const noexcept { return sum; }

private:
  uint32_t count;
  T sum;
};

// define a special-purpose custom printing function
int count = 0;
int sum = 0;
void countAndSum(const int &i) {
  ++count;
  sum = sum + i;
}

int main() {
  int list1[] = {1, 2, 3, 4, 45, 56, 456, 234312};
  int list2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

  // count the number of elements in the list
  // and get the sum of the elements in the list
  std::for_each(list1, list1 + 8, countAndSum);
  std::for_each(list2, list2 + 9, countAndSum);
  std::cout << count << std::endl;
  std::cout << sum << std::endl;

  // Now let's do it with a functor...
  auto ret = std::for_each(list1, list1 + 8, CountAndSum<int>());
  ret = std::for_each(list2, list2 + 9, ret);
  std::cout << ret.getCount() << std::endl;
  std::cout << ret.getSum() << std::endl;

  // Finally, with a lambda
  uint32_t lCount = 0;
  int lSum = 0;
  std::for_each(list1, list1 + 8, [&lCount, &lSum](auto &val) {
    ++lCount;
    lSum += val;
  });
  /*** How to call the same lambda again? ***/
  std::cout << lCount << std::endl;
  std::cout << lSum << std::endl;
  return 0;
}

/************* OUTPUT *********************
17
234924
17
234924
8
234879
*/
