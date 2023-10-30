#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

/*
Your job is to write a function which increments a string, to create a new string.
If the string already ends with a number, the number should be incremented by 1.
If the string does not end with a number. the number 1 should be
 appended to the new string.
*/
bool EndWithNumber(const std::string &str) {
    if(isdigit(str[str.back()])) {
        return true;
    }
    return false;
}
std::string incrementString(const std::string &str)
{
    std::string incrementedString = str;
    if(EndWithNumber(str)) {
        size_t lastDigitPos = str.find_last_of("0123456789");
        //increment last digit.
        if(lastDigitPos != std::string::npos) {
            std::string numericPart = incrementedString.substr(lastDigitPos); // Extract the numeric part
            int numericValue = std::stoi(numericPart); // Convert it to an integer
            numericValue++; // Increment the integer
            std::string newNumericPart = std::to_string(numericValue); // Convert it back to a string
            incrementedString.replace(lastDigitPos, numericPart.length(), newNumericPart); // Replace the old numeric part with the new one

            // Ensure the new numeric part has the same number of digits as the old one (considering leading zeros)
            while (newNumericPart.length() < numericPart.length()) {
                newNumericPart = "0" + newNumericPart;
            }

            incrementedString.replace(lastDigitPos + 1, numericPart.length(), newNumericPart); // Replace the old numeric part with the new one
        }


    }
    return incrementedString;
}

int main() {

    return 0;
}