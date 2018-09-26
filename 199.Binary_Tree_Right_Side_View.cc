#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) {
        	return ans;
        }
		queue<pair<int, TreeNode*>> q;
		int index = -1;
		q.push(pair<int, TreeNode*>(0, root));
		pair<int, TreeNode*> tmp;
		while(!q.empty()) {
			tmp = q.front();
			q.pop();
			if(tmp.first > index) {
				index = tmp.first;
				ans.push_back(tmp.second->val);
			}
			if(tmp.second->right != NULL) {
				q.push(pair<int, TreeNode*>(tmp.first + 1, tmp.second->right));
			}
			if(tmp.second->left != NULL) {
				q.push(pair<int, TreeNode*>(tmp.first + 1, tmp.second->left));
			}
		}
		return ans;
    }
};

int main() {
	Solution sol;
    return 0;
}
