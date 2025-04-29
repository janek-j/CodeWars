#include <iostream>

void example_of_return(int argument);

int main(int args, char* argv[]) {
    return 0;
}

void example_of_return(int argument) {
    if (argument == 0) {
        std::cout << "Argument equals 0. I'm ending." << std::endl;
        return;
    } else {
        std::cout << argument << std::endl;
    }
}


