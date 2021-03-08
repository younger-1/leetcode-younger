/*
 * @lc app=leetcode.cn id=538 lang=java
 *
 * [538] 把二叉搜索树转换为累加树
 */

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

// @lc code=start

// 215/215 cases passed (1 ms)
// Your runtime beats 85.41 % of java submissions
// Your memory usage beats 80.11 % of java submissions (38.6 MB)
class Solution_0 {
    public TreeNode convertBST(TreeNode root) {
        traverse(root);
        return root;
    }

    int sum = 0;
    // Sum all of nodes' value in the tree and assign to this.sum
    void traverse(TreeNode root) {
        if (root == null) {
            return;
        }
        traverse(root.right);
        root.val += this.sum;
        this.sum = root.val;
        traverse(root.left);
    }
}
// @lc code=end

