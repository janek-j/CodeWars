#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
          return false;
        }
        int reversed = 0;
        int _x = x;
        int divider = 10;
        while (_x > 0) {
            int last_digit = _x % 10;
            reversed = reversed * 10 + last_digit;
            _x /= 10;
        }
        return x == reversed;
    }

};

int main() {

}