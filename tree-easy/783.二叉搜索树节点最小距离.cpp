/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
 */

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

#include <string>

using namespace std;

// @lc code=start

// redo
// 中序遍历
class Solution {
   public:
    int rear;
    Solution() : rear(INT_MIN / 2) {}
    int minDiffInBST(TreeNode *root) {
        if (!root)
            return INT_MAX;
        int l = minDiffInBST(root->left);
        int m = root->val - rear;
        rear = root->val;
        int r = minDiffInBST(root->right);
        return min(l, min(m, r));
    }
};
// @lc code=end

class Solution_1 {
   public:
    void dfs(TreeNode *root, int &pre, int &ans) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left, pre, ans);
        if (pre == -1) {
            pre = root->val;
        } else {
            ans = min(ans, root->val - pre);
            pre = root->val;
        }
        dfs(root->right, pre, ans);
    }
    int minDiffInBST(TreeNode *root) {
        int ans = INT_MAX, pre = -1;
        dfs(root, pre, ans);
        return ans;
    }
};