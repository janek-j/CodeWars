#include <iostream>
#include <map>
#include <vector>

int score(const std::vector<int>& dice) {
    int result = 0;
    std::map<int, int> counts;

    for (int i = 0; i < dice.size(); i++) {
        counts[dice[i]]++;
    }

    for (auto &x : counts) {
        if (x.second >= 3) {
            if (x.first == 1) {
                result += 1000;
            } else {
                result += 100 * x.first;
            }
            x.second -= 3;

        }
        result += x.second * (x.first == 1 ? 100 : (x.first == 5 ? 50 : 0));
    }

    return result;
}


int main() {
    const std::vector<int>throws = {1,1,1,2,3};
    std::cout << score(throws);
    return 0;
}