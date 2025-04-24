#include <iostream>
#include <vector>

template<typename T>
T find_2nd_el(const std::vector<T> &vec);

int main(int args, char* argv[]) {
    std::vector<int> numbers = {0,3,2,5,7,9,2};
    int second_largest = find_2nd_el(numbers);
    std::cout << "Second largest element: " << second_largest;
    return 0;
}

template<typename T>
T find_2nd_el(const std::vector<T> &vec) {

    if (vec.size() < 2) {
        throw std::invalid_argument("Vector must contain at least 2 elements");
    }

    const ssize_t size = vec.size();
    T largest_element = vec.at(0);
    T second_largest_element = vec.at(size - 1);

    for (const T& val: vec) {
        if (val > largest_element) {
            second_largest_element = largest_element;
            largest_element = val;
        } else if (val < largest_element && val > second_largest_element) {
            second_largest_element = val;
        }
    }
    return second_largest_element;
}

