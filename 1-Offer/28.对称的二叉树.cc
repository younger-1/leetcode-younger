// 剑指 Offer 28. 对称的二叉树
// https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return dfs(root->left, root->right);
    }

   private:
    bool dfs(TreeNode* a, TreeNode* b) {
        if (!a && !b) {
            return true;
        }
        if (!(a && b)) {
            return false;
        }
        return a->val == b->val && dfs(a->left, b->right) && dfs(a->right, b->left);
    }
};
