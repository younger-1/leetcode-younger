/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
 * root.val = min(root.left.val, root.right.val) 总成立
 */

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// @lc code=start

// TODO: redo
// 因为最小的一定是根结点，递归找到比根结点大的值时可以立即返回
class Solution_1 {
   public:
    int findSecondMinimumValue(TreeNode* root) { return firstbigger(root, root->val); }

   private:
    int firstbigger(TreeNode* root, int val) {
        if (!root)
            return -1;
        if (root->val > val)
            return root->val;
        int left = firstbigger(root->left, val);
        int right = firstbigger(root->right, val);
        if (left < 0)
            return right;
        if (right < 0)
            return left;
        return min(left, right);
    }
    int min(int left, int right) { return left < right ? left : right; }
};
// @lc code=end

// Wrong: [2,2,2147483647] , my: -1, answer: 2147483647
#include <cmath>
class Solution_0 {
   public:
    int findSecondMinimumValue(TreeNode* root) {
        int a = INT_MAX, b = INT_MAX;
        dfs(root, a, b);
        return (a == b || b == INT_MAX) ? -1 : b;
    }

   private:
    void dfs(TreeNode* root, int& a, int& b) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left, a, b);
        if (root->val < a) {
            b = a;
            a = root->val;
        } else if (root->val != a && root->val < b) {
            b = root->val;
        }
        dfs(root->right, a, b);
    }
};

int main() {}
