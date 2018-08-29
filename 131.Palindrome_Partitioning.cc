#include <vector>
#include <string>

#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return helper(s, dp, 0);
    }

    vector<vector<string>> helper(const string& s, vector<vector<int>>& dp, int start) {
        vector<vector<string>> ans;
        vector<vector<string>> tmp;
        for(int i = start;i < s.size();i++) {
            if(dp[start][i] == -1) {
                if (checkpalindrome(s, start, i)) {
                    dp[start][i] = 1;
                    if (i < s.size() - 1) {
                        tmp = std::move(helper(s, dp, i + 1));
                        if (!tmp.empty()) {
                            string temp(s.begin() + start, s.begin() + i + 1);
                            for (int j = 0; j < tmp.size(); j++) {
                                tmp[j].insert(tmp[j].begin(), temp);
                                ans.push_back(std::move(tmp[j]));
                            }
                        }
                    } else {//start == s.size() - 1
                        vector<string> temp;
                        temp.push_back(string(s.begin() + start, s.end()));
                        ans.push_back(temp);
                    }
                } else {
                    dp[start][i] = 0;
                }
            } else if(dp[start][i] == 1) {
                if (i < s.size() - 1) {
                    tmp = std::move(helper(s, dp, i + 1));
                    if (!tmp.empty()) {
                        string temp(s.begin() + start, s.begin() + i + 1);
                        for (int j = 0; j < tmp.size(); j++) {
                            tmp[j].insert(tmp[j].begin(), temp);
                            ans.push_back(std::move(tmp[j]));
                        }
                    }
                } else {//start == s.size() - 1
                    vector<string> temp;
                    temp.push_back(string(s.begin() + start, s.end()));
                    ans.push_back(temp);
                }
            }
        }
        return ans;

    }

    bool checkpalindrome(const string& s, int start, int end) {
        while(start < end) {
            if(s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};

class Solution2 {
    void dfs(const string &s, int pos, vector<vector<bool>> &dp, vector<string> &cur, vector<vector<string>> &res) {
        if(pos == s.size()){
            res.push_back(cur);
            return;
        }

        string temp;
        for(int i=pos;i<s.size();i++) {
            temp.push_back(s[i]);
            if(!dp[pos][i]) continue;
            cur.push_back(temp);
            dfs(s, i + 1, dp, cur, res);
            cur.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i=0;i<n;i++) dp[i][i] = true;
        for(int len=2;len<=n;len++) {
            for(int start = 0; start <= n - len; ++start) {
                int end = start + len - 1;
                if(s[start] == s[end] && (end - start < 3 || dp[start+1][end-1])) dp[start][end] = true;
            }
        }
        vector<string> cur;
        vector<vector<string>> res;
        dfs(s, 0, dp, cur, res);
        return res;
    }
};


int main(int argc, char* argv[]) {
    Solution2 sol;
    vector<vector<string>> ans = sol.partition("aasoidfasdobbabbaabababbababaabab");
    for(int i = 0;i < ans.size();i++) {
        for(int j = 0;j < ans[i].size();j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
