/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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

#include <queue>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode *> con;
        con.push(root);

        int depth = 1;
        while (!con.empty()) {
            int n = con.size();
            for (int i = 0; i < n; i++) {
                auto node = con.front();
                con.pop();
                if (!node->left && !node->right) {
                    return depth;
                }
                if (node->left) {
                    con.push(node->left);
                }
                if (node->right) {
                    con.push(node->right);
                }
            }
            depth++;
        }

        return depth;
    }
};
// @lc code=end
