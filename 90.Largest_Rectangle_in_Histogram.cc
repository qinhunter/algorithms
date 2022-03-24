#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::vector<int> st;
        int ans = 0;
        for (int i = 0; i < heights.size(); ++i) {
            int last_i = i;
            while (!st.empty() && heights[st.back()] > heights[i]) {
                last_i = st.back();
                printf("heights[%d] %d \n", i, heights[i]);
                ans = std::max(ans, (i - st.back()) * heights[st.back()]);
                printf("ans %d \n", ans);
                st.pop_back();
            }
            st.emplace_back(last_i);
            heights[last_i] = heights[i];
        }
        for (int i = 0; i < st.size(); ++i) {
            ans = std::max(ans, (static_cast<int>(heights.size()) - st[i]) * heights[st[i]]);
        }
        return ans;
    }
};
int main () {
    //                       0 1 2 3 4 5 6
    // std::vector<int> heights{2,1,5,6,2,3}; 
    std::vector<int> heights{3,3,2,3,2,2,2,1}; 
    Solution sol;
    std::cout << sol.largestRectangleArea(heights) << std::endl;
    return 0;
}
