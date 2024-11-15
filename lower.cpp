// @author G. Hemingway, copyright 2024
//
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>

struct LowerCase {
  LowerCase() : count(0) {}
  // Notice - this can not take a const ref, must be non-const!
  void operator()(char &x) {
    if (std::isupper(x)) {
      ++count;
      x = std::tolower(x);
    }
  };
  uint32_t count;
};

int main() {
  std::ostream_iterator<char> output(std::cout, "");
  std::string test1 = "Hello, World!";
  std::copy(test1.begin(), test1.end(), output);
  std::cout << std::endl;

  // Simplest approach - just for-loop it
  int count = 0;
  for (auto &i : test1) {
    if (std::isupper(i))
      ++count;
    i = (char)std::tolower(i);
  }
  std::cout << std::endl << count << " characters are upper case." << std::endl;
  std::copy(test1.begin(), test1.end(), output);
  std::cout << std::endl;

  test1 = "Hello, World!";
  // for_each() returns function object after being applied to each element
  // But, is this a correct use of for_each? Should we be changing the input?
  auto f = std::for_each(test1.begin(), test1.end(), LowerCase());
  std::cout << std::endl
            << f.count << " characters are upper case." << std::endl;
  std::copy(test1.begin(), test1.end(), output);

  count = 0;
  test1 = "Hello, World!";
  std::transform(test1.begin(), test1.end(), test1.begin(),
                 [&count](const auto &x) -> char {
                   if (std::isupper(x))
                     ++count;
                   return std::tolower(x);
                 });
  std::cout << std::endl
            << std::endl
            << count << " characters are upper case." << std::endl;
  std::copy(test1.begin(), test1.end(), output);

  return 0;
}

/************* OUTPUT *********************
Hello, World!

2 characters are upper case.
hello, world!

2 characters are upper case.
hello, world!

2 characters are upper case.
hello, world!
*/
