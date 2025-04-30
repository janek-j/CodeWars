/*
 * Wyrazenie lambda, to funkcja, ktora definiuje sie w miejscu, gdzie sie jej potrzebuje. Na przyklad jako
 * argument do algorytmu, gdzie sie jej potrzebuje.
 * Skladnia lambdy: [capture_list](parameters) -> return_type { //body }
 * Kwadratowe nawiasy: [] to capture list, czyli lista przechwytywania zmiennych, podanych jako parametr.
 * [] - nie przechwytuj nic
 * [x] - przechwyc x przez kopie.
 * [&x] - przechwyc x przez referencje.
 * [=] - przechwyc wszystkie uzyte zmienne przez kopie.
 * [&] - przechwyc wszystkie uzyte zmienne przez referencje.
 * [=, &x] - przechwyc wszystkie uzyte zmienne przez kopie, ale x przez referencje.
 * [&, x] - wszystkie przez referencje, x przez kopie.
 * itd.
 * */

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

template<typename T, typename K>
void modify_vector(std::vector<T> &vec, K modifier);

template<typename T>
bool less_than_10(const std::vector<T> &vec);

template<typename T>
bool all_less_than_10(const std::vector<T> &vec);

template<typename T>
T get_second_largest_el(const std::vector<T> &vec);

template<typename T>
T get_lowest_element(const std::vector<T> &vec);

template<typename T>
T get_second_lowest_el(const std::vector<T> &vec);

int main(int args, char* argv[]) {
    std::vector<int> my_vec = {-5,2,3,4,5,6};

    std::cout << get_second_largest_el(my_vec) << std::endl;
    std::cout << get_lowest_element(my_vec) << std::endl;
    std::cout << get_second_lowest_el(my_vec) << std::endl;
    std::cout << less_than_10(my_vec) << std::endl;
    std::cout << all_less_than_10(my_vec) << std::endl;
    std::cout << "Sum of all elements " << std::accumulate(my_vec.begin(), my_vec.end(), 0) << std::endl;
    modify_vector(my_vec, 10);

    std::cout << less_than_10(my_vec) << std::endl;
    std::cout << all_less_than_10(my_vec) << std::endl;

    return 0;
}



template<typename T, typename K>
void modify_vector(std::vector<T> &vec, K modifier) {
    std::for_each(vec.begin(), vec.end(), [&](int &x) { return x += modifier; });
}


template<typename T>
bool less_than_10(const std::vector<T> &vec) {
    auto less = [=](T i) -> bool { return i < 10; }; //przechwyc przez kopie wszystkie zmienne
    return std::any_of(vec.begin(), vec.end(), less);
}


template<typename T>
bool all_less_than_10(const std::vector<T> &vec) {
    auto less = [&](T i) -> bool { return i < 10; }; //przechwyc przez referencje wszystkie zmienn4e
    return std::all_of(vec.begin(), vec.end(), less);
}

template<typename T>
T get_second_largest_el(const std::vector<T> &vec) {
    const ssize_t size = vec.size();
    if (size < 2) {
        throw std::invalid_argument("Vector must contain at least two elements.");
    }
    T max_el = vec.at(0);
    T sec_max_el = vec.at(1);

    for (const T &el: vec) {
        if (el > max_el) {
            sec_max_el = max_el;
            max_el = el;
        }
        if (el < max_el && el > sec_max_el) {
            sec_max_el = el;
        }
    }
    return sec_max_el;
}

template<typename T>
T get_lowest_element(const std::vector<T> &vec) {
    const ssize_t size = vec.size();
    T low_el = vec.at(0);
    if (size < 2) {
        throw std::invalid_argument("Vector must contain at least two elements");
    }
    for (const T &el: vec) {
        if (el < low_el) {
            low_el = el;
        }
    }
    return low_el;
}

template<typename T>
T get_second_lowest_el(const std::vector<T> &vec) {
    const ssize_t size = vec.size();
    if (size < 2) {
        throw std::invalid_argument("Vector must contain at least two elements.");
    }
    T low_el = vec.at(0);
    T sec_low_el = vec.at(1);
    for (const T &el: vec) {
        if (el < low_el) {
            sec_low_el = low_el;
            low_el = el;
        } else if (el > low_el && el < sec_low_el) {
            sec_low_el = el;
        }
    }
    return sec_low_el;
}