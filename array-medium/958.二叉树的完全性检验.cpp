/*
 * @lc app=leetcode.cn id=958 lang=cpp
 *
 * [958] 二叉树的完全性检验
 */

// @lc code=start
/*
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

#include <queue>

using namespace std;

class Solution {
   public:
    bool isCompleteTree(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        bool ok = true;
        while (!q.empty()) {
            auto n = q.front();
            q.pop();
            if (!n) {
                ok = false;
                continue;
            }
            if (!ok) {
                return false;
            }
            q.push(n->left);
            q.push(n->right);
        }
        return true;
    }
};
// @lc code=end
