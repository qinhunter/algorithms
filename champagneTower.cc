#include<iostream>
#include<vector>

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        std::vector<double> last{static_cast<double>(poured)};
        for (int l = 1; l <= query_row; ++l) {
            decltype(last) now(l + 1, 0);
            for (int i = 0; i < last.size(); ++i) {
                if (last[i] > 1) {
                    double tmp = (last[i] - 1) / 2;
                    now[i] += tmp;
                    now[i + 1] += tmp;
                }
            }
            last.swap(now);
        } 
        return std::min(last[query_glass], 1.0);
    }
};
int main() {
    Solution sol;
    // std::cout << sol.champagneTower(0, 0, 0) << std::endl;
    std::cout << sol.champagneTower(1, 1, 1) << std::endl;
}
