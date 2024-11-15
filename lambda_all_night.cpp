// @author G. Hemingway, copyright 2024
//
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <list>

template <typename T> class FunctorAllNight {
  uint32_t count;
  T min, max;
  std::ostream &os;

public:
  explicit FunctorAllNight(std::ostream &stream) : count(0), os(stream) {}
  void operator()(const T &val) {
    if (count == 0)
      min = max = val;
    else {
      min = val < min ? val : min;
      max = val > max ? val : max;
    }
    if (count % 2 == 0)
      os << val << " ";
    ++count;
  }
  uint32_t getCount() const noexcept { return count; }
  T getMin() const noexcept { return min; }
  T getMax() const noexcept { return max; }
};

int main() {
  // Let's try this with ints
  int iList[] = {1, 2, 4, 8, 16, 32, 64, 128};
  // Now build me a functor
  auto i = std::for_each(iList, iList + 8,
                         FunctorAllNight<int>(std::cout)); // Expect "1 4 16 64"
  std::cout << std::endl << i.getCount() << std::endl;     // Expect "8"
  std::cout << i.getMin() << std::endl;                    // Expect "1"
  std::cout << i.getMax() << std::endl;                    // Expect "128"
  std::cout << std::endl;

  return 0;
}
