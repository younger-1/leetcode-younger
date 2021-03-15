/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode *root) {
        TreeNode *l, *r = root;
        int ld, rd = 0;
        while (l != nullptr) {
            l = l->left;
            ld += 1;
        }
        while (r != nullptr) {
            r = r->right;
            rd += 1;
        }
        if (ld == rd) {
            return (1 << ld) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
// @lc code=end

// 18/18 cases passed (60 ms)
// Your runtime beats 14.36 % of cpp submissions
// Your memory usage beats 87.45 % of cpp submissions (30 MB)
class Solution_1 {
   public:
    int countNodes(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int ld = left_side_depth(root->left);
        int rd = left_side_depth(root->right);

        if (ld == rd) {
            // 1(根节点) + (1 << ld) - 1 (左完全左子树节点数) + 右子树节点数量
            return (1 << ld) + countNodes(root->right);
        } else
            // 1(根节点) + (1 << rd) - 1 (右完全右子树节点数) + 左子树节点数量
            return (1 << rd) + countNodes(root->left);
    }

    int left_side_depth(TreeNode *root) {
        int depth = 0;
        while (root != nullptr) {
            depth += 1;
            root = root->left;
        }
        return depth;
    }
};
