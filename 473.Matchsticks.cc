#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <bitset>

using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (const auto stick : matchsticks) {
            sum += stick;
        }
        if (sum % 4 != 0) {
            return false;
        }
        int final = 0;
        for (int i = 0; i < matchsticks.size(); ++i) {
            final |= 1 << i;
        }
        // printf("sum %d\n", sum);
        mem[final] = 1;
        std::sort(matchsticks.begin(), matchsticks.end(), std::greater<int>());
        if (matchsticks.front() > sum / 4) {
            return false;
        }
        return helper(matchsticks, 0, sum / 4, 0, 0);
    }
    std::unordered_map<int, int> mem;
    bool helper(const std::vector<int>& sticks, int tmp, int target, int bit, int i) {
        auto& res = mem[bit];
        if (res == 0) {
            res = -1;
	        // std::cout << "calculater with bit " << bitset<sizeof(bit)*8>(bit) << ", tmp " << tmp << " i " << i << endl;
            if (tmp == 0 || tmp == target) {
                for (int j = 0; j < sticks.size(); ++j) {
                    // printf("tmp == 0, sticks[%d] %d\n", j, sticks[j]);
                    int tmp_bit = bit | 1 << j;
                    if (tmp_bit != bit) {
                        if (helper(sticks, sticks[j], target, tmp_bit, j + 1)) {
                            res = 1;
                        }
                        break;
                    }
                }
            } else {
                for (int j = i; j < sticks.size(); ++j) {
                    int tmp_bit = bit | 1 << j;
                    int new_tmp = tmp + sticks[j];
                    if (tmp_bit == bit || new_tmp > target) {
                        continue;
                    }
                    if (helper(sticks, new_tmp, target, tmp_bit, j + 1)) {
                        res = 1;
                        break;
                    }
                }
            }
        }
        return res == 1;
    }
};

int main () {
    std::vector<int> sticks{5,5,5,5,4,4,4,4,3,3,3,3}; 
    Solution sol;
    std::cout << sol.makesquare(sticks) << std::endl;
    return 0;
}
