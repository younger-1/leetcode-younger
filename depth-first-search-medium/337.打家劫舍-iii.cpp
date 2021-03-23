/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */
#include <map>
#include <vector>

using namespace std;

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

// 123/123 cases passed (8 ms)
// Your runtime beats 99.1 % of cpp submissions
// Your memory usage beats 92.54 % of cpp submissions (21.5 MB)
struct SubtreeStatus {
    int selected;
    int notSelected;
};

class Solution {
   public:
    SubtreeStatus dfs(TreeNode *node) {
        if (!node) {
            return {0, 0};
        }
        auto l = dfs(node->left);
        auto r = dfs(node->right);
        int selected = node->val + l.notSelected + r.notSelected;
        int notSelected = max(l.selected, l.notSelected) + max(r.selected, r.notSelected);
        return {selected, notSelected};
    }

    int rob(TreeNode *root) {
        auto rootStatus = dfs(root);
        return max(rootStatus.selected, rootStatus.notSelected);
    }
};

// @lc code=end

// 123/123 cases passed (44 ms)
// Your runtime beats 24.65 % of cpp submissions
// Your memory usage beats 25.48 % of cpp submissions (28.6 MB)
class Solution_0 {
   private:
    map<pair<TreeNode *, bool>, int> memo;

   public:
    int rob(TreeNode *root) { return max(rob_or_not(root, false), rob_or_not(root, true)); }

    int rob_or_not(TreeNode *root, bool rob_node) {
        if (root == nullptr) {
            return 0;
        }
        if (memo.find({root, rob_node}) != memo.end()) {
            return memo[{root, rob_node}];
        }
        if (rob_node) {
            int r = rob_or_not(root->right, false);
            int l = rob_or_not(root->left, false);
            memo[{root, rob_node}] = root->val + r + l;
        } else {
            int r_max = max(rob_or_not(root->right, true), rob_or_not(root->right, false));
            int l_max = max(rob_or_not(root->left, true), rob_or_not(root->left, false));
            memo[{root, rob_node}] = r_max + l_max;
        }
        return memo[{root, rob_node}];
    }
};
