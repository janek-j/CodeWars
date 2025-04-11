#include <iostream>
 
namespace mierla {
    int key = 0;
    void print_key() {
        std::cout << "Your key is: " << key << std::endl;
        std::cout << "Do not show your key to anyone!" << std::endl;
    }
}

int main() {
    std::cout << std::endl;
    mierla::print_key();
    return 0;
}