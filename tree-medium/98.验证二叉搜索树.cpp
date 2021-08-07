/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

#include <stack>
#include <string>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// @lc code=start

// @lc code=end

// 12ms 18.1MB
// @递归
class Solution1 {
   public:
    bool helper(TreeNode *root, long long lower, long long upper) {
        if (root == nullptr)
            return true;
        if (root->val <= lower || root->val >= upper)
            return false;
        return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
    }

    bool isValidBST(TreeNode *root) { return helper(root, LONG_MIN, LONG_MAX); }
};

// 20ms 18.4MB
// @中序遍历
class Solution2 {
   public:
    bool isValidBST(TreeNode *root) {
        stack<TreeNode *> s;
        long long inorder = (long long)INT_MIN - 1;
        while (s.empty() == false || root != nullptr) {
            while (root != nullptr) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (root->val <= inorder)
                return false;
            inorder = root->val;
            root = root->right;
        }
        return true;
    }
};
