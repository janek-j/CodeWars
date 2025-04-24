#include <iostream>
#include <vector>
#include <algorithm>

// metody dodawnia pol emplace back

bool modify_vector(std::vector<int> &vec);
/*
 * Napisz funkcje ktora przyjmie vector i kazdy element zwiekszy o 5.
 * Sprawdzic czy jakis element jest wiekszy od 8 jak tak, to true oth false
*/

void print_vector(const std::vector<int> &vec);


int main() {
  std::vector<int> test = {1,2,3,4,5};
  std::cout << modify_vector(test);
  print_vector(test);
  return 0;
}
bool modify_vector(std::vector<int> &vec) {
    for (int &i: vec) {
      i += 5;
    }
    constexpr int _n = 8;
    auto greater = [=](const int n) { return n > _n; };
    return std::any_of(vec.begin(), vec.end(), greater);
}

void print_vector(const std::vector<int> &vec) {
  const int size = vec.size();
  std::cout << "Vector contains: ";
  for (int i = 0; i < size; i++) {
    std::cout << vec[i];
    if (i != size - 1) {
      std::cout << ", ";
    }
  }
}
