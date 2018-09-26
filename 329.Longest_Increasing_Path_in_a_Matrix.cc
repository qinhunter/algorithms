#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), 0));
        int max = 0;
        for(int i = 0;i < matrix.size();i++) {
            for(int j = 0;j < matrix[i].size();j++) {
                if(visited[i][j] == 0) {
                    helper(matrix, i, j, visited, INT_MAX);
                    if(visited[i][j] > max) {
                        max = visited[i][j];
                    }
                }
            }
        }
        return max;
    }
    int helper(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& visited, int last) {
        if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[i].size() || matrix[i][j] >= last) {
            return 0;
        }
        if(visited[i][j] != 0) {
            return visited[i][j];
        }
        int maxstep = 0;
        maxstep = max(maxstep, helper(matrix, i - 1, j, visited, matrix[i][j]));
        maxstep = max(maxstep, helper(matrix, i + 1, j, visited, matrix[i][j]));
        maxstep = max(maxstep, helper(matrix, i, j - 1, visited, matrix[i][j]));
        maxstep = max(maxstep, helper(matrix, i, j + 1, visited, matrix[i][j]));
        visited[i][j] = maxstep + 1;
        return visited[i][j];
    }
};

int main() {
	Solution sol;
    return 0;
}
