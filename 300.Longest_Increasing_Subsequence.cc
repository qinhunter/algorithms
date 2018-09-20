#include <iostream>
#include <string.h>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

class SolutionMine {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
		if(size <= 1) {
			return size;
		}
		int maxlen = 1;

		vector<int> dp(size, 1);
		for(int i = 0;i < size;i++) {
			for(int j = i + 1;j < size;j++) {
				if(nums[i] < nums[j]) {
					if(dp[i] + 1 > dp[j]) {
						dp[j] = dp[i] + 1;
						if(dp[j] > maxlen) {
							maxlen = dp[j];
						}
					}
				}
			}
		}

		return maxlen;
    }
};


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        vector<int> LIS;
        for(int i = 0; i < n; i++){
            vector<int>::iterator it = lower_bound(LIS.begin(), LIS.end(), nums[i]);
            if(it != LIS.end()){
                *it = nums[i];
            } else {
                LIS.push_back(nums[i]);
            }
        }
        return LIS.size();
    }
};


int main() {
	Solution sol;
	vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
	int ans = sol.lengthOfLIS(nums);
	cout << "ans = " << ans << endl;
    return 0;
}
