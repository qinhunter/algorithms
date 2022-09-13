#include <iostream>
#include <string.h>
#include <vector>
#include <limits.h>
#include <functional>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        helper(nums, target, 0);
        return ans;
    }
    int ans = 0;
    std::vector<int> path;
    int C(int n, int m) {
        long long sum = 1;
        long long di = 1;
        for (int i = 0; i < m; ++i) {
            sum *= n - i;
            di *= m - i;
        }
        return sum / di;
    }
    void helper(const std::vector<int>& nums, int target, int i) {
        if (nums.size() <= i) {
            long long tmp = 1;
            long long sum = 0;
            for (const auto& n : path) {
                sum += n;
                // printf("%d ", n);
            }
            for (const auto p : path) {
                tmp *= C(sum, p);
                sum -= p;
            }
            // printf("\n sum %d, tmp %d\n", sum, tmp);
            ans += tmp;
        } else if (i == nums.size() - 1){
            if (target % nums[i] == 0) {
                int num = target / nums[i];
                path.emplace_back(num);
                helper(nums, 0, i + 1);
                path.pop_back();
            }
        } else {
            path.emplace_back(-1);
            for (int tmp = 0; tmp <= target; tmp += nums[i]) {
                // printf("start calculate i %d, nums[i] %d, tmp %d, target %d\n", i, nums[i], tmp, target);
                ++path.back();
                helper(nums, target - tmp, i + 1);
                // printf("end calculate i %d, nums[i] %d, tmp %d, target %d, added %d\n", i, nums[i], tmp, target, added);
            }
            path.pop_back();
        }
    }
};

int main() {
    Solution sol;
    std::vector<int> nums{1, 2, 3};
    std::cout << sol.combinationSum4(nums, 4) << std::endl;
}
