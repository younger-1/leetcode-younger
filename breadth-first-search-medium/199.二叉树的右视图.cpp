/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 */

#include <queue>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start

class Solution {
   public:
    vector<int> rightSideView(TreeNode *root) {
        if (!root) {
            return {};
        }
        queue<TreeNode *> q;
        q.push(root);
        vector<int> ans;
        while (!q.empty()) {
            int n = q.size();
            ans.push_back(q.front()->val);
            while (n--) {
                TreeNode *node = q.front();
                q.pop();
                if (node->right) {
                    q.push(node->right);
                }
                if (node->left) {
                    q.push(node->left);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
