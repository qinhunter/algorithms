#include <iostream>
#include <string.h>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

class SolutionOld {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        int cnt1 = 0, cnt2 = 0;
        for (char c : s) {
            cnt1 += (c == '(');
            if (cnt1 == 0) cnt2 += (c == ')');
            else cnt1 -= (c == ')');
        }
        helper(s, 0, cnt1, cnt2, res);
        return res;
    }
    void helper(string s, int start, int cnt1, int cnt2, vector<string>& res) {
        if (cnt1 == 0 && cnt2 == 0) {
            if (isValid(s)) res.push_back(s);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            if (i != start && s[i] == s[i - 1]) continue;
            if (cnt1 > 0 && s[i] == '(') {
                helper(s.substr(0, i) + s.substr(i + 1), i, cnt1 - 1, cnt2, res);
            }
            if (cnt2 > 0 && s[i] == ')') {
                helper(s.substr(0, i) + s.substr(i + 1), i, cnt1, cnt2 - 1, res);
            }
        }
    }
    bool isValid(string t) {
        int cnt = 0;
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] == '(') ++cnt;
            else if (t[i] == ')' && --cnt < 0) return false;
        }
        return cnt == 0;
    }
};

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        helper(s, 0, 0, {'(', ')'}, res);
        return res;
    }
    void helper(string s, int last_i, int last_j, vector<char> p, vector<string>& res) {
        int cnt = 0;
        for (int i = last_i; i < s.size(); ++i) {
            if (s[i] == p[0]) ++cnt;
            else if (s[i] == p[1]) --cnt;
            if (cnt >= 0) continue;
            for (int j = last_j; j <= i; ++j) {
                if (s[j] == p[1] && (j == last_j || s[j] != s[j - 1])) {
                    helper(s.substr(0, j) + s.substr(j + 1), i, j, p, res);
                }
            }
            return;
        }
        string rev = string(s.rbegin(), s.rend());
        if (p[0] == '(') helper(rev, 0, 0, {')', '('}, res);
        else res.push_back(rev);
    }
};


int main() {
	Solution sol;
	string s = "()(asd)(a)da)(v()(((((()))))))))(())(()((ad";
	vector<string> ans = std::move(sol.removeInvalidParentheses(s));
	for(int i = 0;i < ans.size();i++) {
		cout << "i = " << i << ", " << ans[i] << endl;
	}
    return 0;
}
