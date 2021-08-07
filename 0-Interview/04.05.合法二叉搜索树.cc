// 面试题 04.05. 合法二叉搜索树
// https://leetcode-cn.com/problems/legal-binary-search-tree-lcci/

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// TODO: redo
class Solution {
   public:
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        if (!isValidBST(root->left)) {
            return false;
        }
        if (pre && root->val <= pre->val) {
            return false;
        }
        pre = root;
        if (!isValidBST(root->right)) {
            return false;
        }
        return true;
    }

   private:
    TreeNode* pre = nullptr;
};

#include <cmath>

class Solution_2 {
   public:
    // case: [INT_MAX] is valid
    bool isValidBST(TreeNode* root) { return isValidBST(root, LONG_MIN, LONG_MAX); }

   private:
    bool isValidBST(TreeNode* root, long min, long max) {
        if (!root) {
            return true;
        }
        if (root->val <= min || root->val >= max) {
            return false;
        }
        return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    }
};
