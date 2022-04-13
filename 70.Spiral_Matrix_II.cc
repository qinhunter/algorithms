#include <vector>
#include <iostream>
#include "helper.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        std::vector<std::pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int i = 0;
        int j = -1;
        std::vector<std::vector<int>> grid(n, std::vector<int>(n, 0));
        int g = 1;
        
        for (int dir_n = 0; g <= n * n; ++dir_n) {
            const auto& [a, b] = dirs[dir_n %= dirs.size()];
            while (true) {
                int x = i + a;
                int y = j + b;
                printf("x %d, y %d, g %d\n", x, y, g);
                if (0 <= x && 0 <= y && x < n && y < n && grid[x][y] == 0) {
                    grid[x][y] = g;
                    i = x;
                    j = y;
                    ++g;
                } else {
                    break;
                }
            }
        }
        return grid;
    }
};

int main () {
    Solution sol;
    print_vec_vec(sol.generateMatrix(10));
    return 0;
}
