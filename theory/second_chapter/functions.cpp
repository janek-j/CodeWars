#include <iostream>

int add(int number1, int number2);

int main(int args, char* argv[]) {
    int num1 = 3;
    int num2 = 4;

    int sum = add(num1, num2);
    std::cout << sum;

    return 0;
}

int add(int number1, int number2) {
    return number1 + number2;
}


