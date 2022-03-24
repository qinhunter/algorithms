#include <vector>
#include <iostream>
using namespace std;

void print_vec(const std::vector<int>& nums) {
    for (const auto n : nums) {
        cout << n << " ";
    }
    cout << std::endl;
}
