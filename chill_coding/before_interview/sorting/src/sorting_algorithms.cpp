#include <iostream>
#include <vector>

template<typename T>
void print_elements<T>(std::vector<T> &vec) {
    for (auto &t: vec) {
        std::cout << t << " ";
    }
}

template<typename T> // O(n^2)
std::vector<T> bubble_sort(const std::vector<T> &vec); // O(n^2)

template<typename T>
std::vector<T> insertion_sort(const std::vector<T> &vec); // O(n^2)

template<typename T>
std::vector<T> selection_sort(const std::vector<T> &vec); // O(n^2)

int main() {
    std::vector<int> to_sort = {5,2,5,7,8,9,2,1,4,5,6};
    std::vector<int> bubble_sorted = insertion_sort(to_sort);
    print_elements<int>(bubble_sorted);
    return 0;
}

// O(n^2)
template<typename T>
std::vector<T> bubble_sort(const std::vector<T> &vec) {
    int size = vec.size();
    std::vector<T> sorted_vector = vec;
    if (size == 0) {
        std::cerr << "Cannot sort empty list." << std::endl;
        return vec;
    } else {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (sorted_vector[j] > sorted_vector[j+1]) {
                    std::swap(sorted_vector[j], sorted_vector[j+1]);
                }
            }
        }
    }
    return sorted_vector;
}

// O(n^2)
template<typename T>
std::vector<T> insertion_sort(const std::vector<T> &vec) {
    int size = vec.size();
    std::vector<T> sorted_vector = vec;

    if (size == 0) {
        std::cerr << "Cannot sort empty vector." << std::endl;
        return vec;
    } else {
        for (int i = 1; i < size; i++) {
            T key = sorted_vector[i];
            T j = i - 1;
            while( j >= 0 && sorted_vector[j] > key ) {
                sorted_vector[j+1] = sorted_vector[j];
                j--;
            }
            sorted_vector[j+1] = key;
        }   
    }
    return sorted_vector;
}

// O(n^2)
template<typename T>
std::vector<T> selection_sort(const std::vector<T> &vec) {
    int size = vec.size();
    std::vector<T> sorted_vector = vec;
    if (size == 0) {
        std::cerr << "Cannot sort an empty vector." << std::endl;
        return vec;
    } else {
        for (int i = 0; i < size; i++) {
            int min_ind = i;
            for (int j = i + 1; j < size; j++) {
                if (sorted_vector[j] < sorted_vector[min_ind]) {
                    min_ind = j;
                }
            }
            std::swap(sorted_vector[i], sorted_vector[min_ind]);
        }
    }
    return sorted_vector;
}