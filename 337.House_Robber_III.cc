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
    int rob(TreeNode* root) {
        int rob = 0;
        int notrob = 0;
        return helper(root, rob, notrob);
    }
    int helper(TreeNode* root, int& rob, int& notrob) {
        if(root == NULL) {
            return 0;
        }
        int left_rob = 0;// the money that rob the left part can get most
        int left_not_rob = 0;// the money that not rob the left part can get most
        int left = helper(root->left, left_rob, left_not_rob);// the money that the left part can get most

        int right_rob = 0;// the money that rob the right part can get most
        int right_not_rob = 0;// the money that not rob the right part can get most
        int right = helper(root->right, right_rob, right_not_rob);// the money that the right part can get most

        rob = root->val + left_not_rob + right_not_rob;// rob this root can get
        notrob = max(left_rob, left_not_rob) + max(right_rob, right_not_rob);// not rob this root can get
        //not rob = left + right
        return max(rob, notrob);
    }

};

int main() {
	Solution sol;
    return 0;
}
