// @author G. Hemingway, copyright 2024
//
#include <algorithm>
#include <iostream>

class PrintIt {
public:
  void operator()(const int &i) { std::cout << i << ":"; }
};

// define a special-purpose custom printing function
void printIt(int i) { std::cout << i << ":"; }

int main() {
  int int_list[] = {1, 2, 3, 4, 45, 56, 456, 234312};

  // Use a range-based for loop to call the printIt function
  for (auto val : int_list)
    printIt(val);
  std::cout << std::endl;

  // Use for_each algorithm to call printIt function on each element in the list
  std::for_each(int_list, int_list + 8, printIt);
  std::cout << std::endl;

  // Use for_each algorithm to invoke PrintIt functor on each element in the
  // list
  std::for_each(int_list, int_list + 8, PrintIt());
  std::cout << std::endl;

  // Use a lambda function to print each element in the list
  std::for_each(int_list, int_list + 8,
                [](auto val) { std::cout << val << ":"; });
  std::cout << std::endl;

  return 0;
}

/************* OUTPUT *********************
1:2:3:4:45:56:456:234312:
1:2:3:4:45:56:456:234312:
1:2:3:4:45:56:456:234312:
1:2:3:4:45:56:456:234312:
*/
