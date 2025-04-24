#include <iostream>

std::string fizz_buzz(const int &n);
void print_fizz_buzz(const int &n);

int main() {
  print_fizz_buzz(5);
  return 0;
}

std::string fizz_buzz(const int &n) {
  if (n % 15 == 0) {
    return "FizzBuzz";
  } else if (n % 3 == 0 && n % 5 != 0) {
    return "Fizz";
  } else if (n % 3 != 0 && n % 5 == 0) {
    return "Buzz";
  } else {
    return std::to_string(n);
  }
}

void print_fizz_buzz(const int &n) {
  for (int i = 1; i < n; i++) {
    std::cout << fizz_buzz(i) << std::endl;
  }
}
