#include "helper.h"

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        for (int i = 0; i < data.size(); ++i) {
            if ((data[i] & f1) == 0) {
                continue;
            } else if ((data[i] & f2) == f2e) {
                if (!helper(data[++i])) {
                    return false;
                }
            } else if ((data[i] & f3) == f3e) {
                if (!helper(data[++i]) || !helper(data[++i])) {
                    return false;
                }
            } else if ((data[i] & f4) == f4e) {
                if (!helper(data[++i]) || !helper(data[++i]) || !helper(data[++i])) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
	int f1 = 1 << 7;
    int f2 = 7 << 5;
    int f2e = 3 << 6;
    int f3 = 15 << 4;
    int f3e = f2;
    int f4 = 31 << 23;
    int f4e = f3;    
    int fs = 3 << 6;
    bool helper(const int d) {
        return (d & fs) == f1;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums{235,140,4};
    for (const auto num : nums) {
        binary_print(num);
    }
    std::cout << sol.validUtf8(nums) << std::endl;
}
