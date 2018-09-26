#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) {
            return 0;
        }
        int count = 0;
        for(int i = 0;i < grid.size();i++) {
            for(int j = 0;j < grid[i].size();j++) {
                if(grid[i][j] == '1') {
                    count++;
                    helper(grid, i, j);
                }
            }
        }
        return count;
    }

    void helper(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        //grid[i][j] == '1'
        helper(grid, i - 1, j);
        helper(grid, i + 1, j);
        helper(grid, i, j - 1);
        helper(grid, i, j + 1);
    }
};

int main() {
	Solution sol;
    return 0;
}
