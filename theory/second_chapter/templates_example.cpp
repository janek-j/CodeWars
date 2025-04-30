#include <iostream>

template<typename T>
T maximum(T a, T b);

int main() {
    return 0;
}

template<typename T>
T maximum(T a, T b) {
    return a > b ? a : b;
}