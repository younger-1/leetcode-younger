/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// @lc code=start

// 31/31 cases passed (16 ms)
// Your runtime beats 91.61 % of cpp submissions
// Your memory usage beats 62.83 % of cpp submissions (14 MB)
class Solution {
   public:
    TreeNode *ans;
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, p, q);
        return ans;
    }

    // 表示 root 节点的子树中是否包含 p 节点或 q 节点
    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr)
            return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        // 第一条判断条件, lson ​&& rson ​说明左子树和右子树均包含 p 节点或 q 节点
        // 第二条判断条件，考虑了 root 恰好是 p 节点或 q 节点且它的左子树或右子树有一个包含了另一个节点的情况
        if ((lson && rson) || ((root == p || root == q) && (lson || rson))) {
            ans = root;
        }
        return lson || rson || root == p || root == q;
    }
};
// @lc code=end

// 执行用时： 20 ms , 在所有 C++ 提交中击败了 70.58% 的用户
// 内存消耗： 14.1 MB , 在所有 C++ 提交中击败了 44.76% 的用户
class Solution_1 {
   public:
    // TODO: ?
    // 用 Git 来讲讲二叉树最近公共祖先
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) {
            return nullptr;
        }
        if (p == root || q == root) {
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left && right) {
            return root;
        }
        if (!left && !right) {
            return nullptr;
        }

        return left ? left : right;
    }
};
