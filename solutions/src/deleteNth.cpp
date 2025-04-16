#include <iostream>
#include <vector>
#include <map>

std::vector<int> deleteNth(std::vector<int> arr, int n);
{
    if(arr.size() == 0) { return {}; }
    std::map<int, int>occurences;
    std::vector<int>result;
    for(int i = 0; i < arr.size(); i++) {
        int element = arr[i];
        if(occurences[element] < n) {
            result.push_back(element);
            occurences[element]++;
        }
    }
    return result;
}

int main() {
    std::vector<int>vec = {1,2,3,4,5,1,1,1,1,2,3,4,3,2,1};
    std::vector<int>vec2 = deleteNth(vec, 2);
    for(int i = 0; i < vec2.size(); i++) {
        std::cout << vec2[i];
    }
    return 0;
}
