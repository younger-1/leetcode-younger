// 面试题 04.08. 首个共同祖先
// https://leetcode-cn.com/problems/first-common-ancestor-lcci/

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 1、递归出口：根节点为空，或者找到p或q节点了
        if (!root || root == p || root == q)
            return root;
        // 2、递归式：从根节点的左右子树寻找p、q的节点
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // 3、判断其祖先的位置
        if (left && right)
            return root;  // 在以root为根节点的左右子树中找到p、q节点了，则root为祖先
        if (left && !right)
            return left;  // 在以root为根节点的右子树没找到p、q节点，则其左子树根节点为祖先
        return right;     // 在以root为根节点的左子树没找到p、q节点，则其右子树根节点为祖先
    }
};
