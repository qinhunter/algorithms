#include "helper.h"

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        for (int i = 0; i < data.size(); ++i) {
            if ((data[i] & f1) == 0) {
                continue;
            } else if ((data[i] & f2) == f2e) {
                if (data.size() <= i + 1 || !helper(data[++i])) {
                    return false;
                }
            } else if ((data[i] & f3) == f3e) {
                if (data.size() <= i + 2|| !helper(data[++i]) || !helper(data[++i])) {
                    return false;
                }
            } else if ((data[i] & f4) == f4e) {
                if (data.size() <= i + 3|| !helper(data[++i]) || !helper(data[++i]) || !helper(data[++i])) {
                    printf("hunter test\n");
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
    int f4 = 31 << 3;
    int f4e = f3;    
    int fs = 3 << 6;
    bool helper(const int d) {
        return (d & fs) == f1;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums{240,162,138,147};
    for (const auto num : nums) {
        binary_print(num);
    }
    std::cout << sol.validUtf8(nums) << std::endl;
}
