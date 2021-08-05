// 剑指 Offer 27. 二叉树的镜像
// https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/

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
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        TreeNode* t = new TreeNode(root->val);
        t->left = mirrorTree(root->right);
        t->right = mirrorTree(root->left);
        return t;
    }
};
