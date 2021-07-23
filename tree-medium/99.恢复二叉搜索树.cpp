/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 */

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

// @lc code=start
class Solution {
   public:
    void recoverTree(TreeNode *root) {
        inorder(root);
        int tmp = s->val;
        s->val = t->val;
        t->val = tmp;
    }

   private:
    TreeNode *s, *t, *pre;
    void inorder(TreeNode *node) {
        if (!node) {
            return;
        }
        inorder(node->left);
        if (pre && pre->val > node->val) {
            if (s == nullptr) {
                s = pre;
            }
            t = node;
        }
        pre = node;
        inorder(node->right);
    }
};
// @lc code=end
