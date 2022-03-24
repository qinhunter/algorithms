#include "helper.h"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if (k == 0) {
            return;
        }
        for (int j = 0; j < (nums.size() % k == 0 ? k : 1); ++j) {
            printf("j %d\n", j);
            int i = j;
            int last = nums[i + nums.size() - k];
            do {
                printf("i %d, nums %d, last %d \n", i, nums[i], last);
                std::swap(nums[i], last);
                i = (i + k) % nums.size();
            } while (i != j);
        }
    }
};

int main() {
    Solution sol;
    int k = 2;
    std::vector<int> nums{0, 1, 2, 3};
    cout << "before rotate" << std::endl;
    print_vec(nums);
    sol.rotate(nums, k);
    cout << "after rotate" << std::endl;
    print_vec(nums);
}
