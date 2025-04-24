#include <iostream>
#include <vector>

template<typename T>
bool binary_search(const std::vector<T> &vec, T element);

int main() {
  const std::vector<int> my_vec = {1,2,3,4,5,6,7,8,9,10,11};
  std::cout << binary_search(my_vec, 5);
  return 0;
}

template<typename T>
bool binary_search(const std::vector<T> &vec, T element) {
  int low = 0;
  int high = vec.size() - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (vec[mid] < element) {
      low = mid + 1;
    } else if (vec[mid] > element) {
      high = mid - 1;
    } else {
      return true;
    }
  }
  return false;
}