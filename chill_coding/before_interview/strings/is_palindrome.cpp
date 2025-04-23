#include <iostream>

bool is_palindrome(const std::string &str) {
    ssize_t i = 0;
    ssize_t j = str.size() - 1;

    while (i < j && j >= 0) {
        if (str[i] != str[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main(int args, char* argv[]) {
    std::cout << is_palindrome("a");
}