// 面试题 04.10. 检查子树
// https://leetcode-cn.com/problems/check-subtree-lcci/

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
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) {
            return true;
        }
        if (!t1 || !t2) {
            return false;
        }
        bool res = t1->val == t2->val && checkSubTree(t1->left, t2->left) && checkSubTree(t1->right, t2->right);
        res = res || checkSubTree(t1->left, t2) || checkSubTree(t1->right, t2);
        return res;
    }
};

class Solution_1 {
   public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if (!t2)
            return true;
        if (!t1)
            return false;
        return isEqual(t1, t2) || checkSubTree(t1->left, t2) || checkSubTree(t1->right, t2);
    }

   private:
    bool isEqual(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) {
            return true;
        }
        if (!t1 || !t2) {
            return false;
        }
        return t1->val == t2->val && isEqual(t1->left, t2->left) && isEqual(t1->right, t2->right);
    }
};
