#include <iostream>
#include <string>

std::string createPhoneNumber(const int arr[10]) {
    std::string phoneNumber = "(";

    for (int i = 0; i < 10; i++) {
        phoneNumber.append(std::to_string(arr[i]));

        if (i == 2) {
            phoneNumber.append(") ");
        }
        else if (i == 5) {
            phoneNumber.append("-");
        }
    }

    return phoneNumber;
}

int main() {
    const int tab[] = {1,1,1,2,3,2,3,4,5,1};
    std::string phone = createPhoneNumber(tab);
    std::cout << phone;
    return 0;
}
