/*
 * @lc app=leetcode.cn id=226 lang=java
 *
 * [226] 翻转二叉树
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

// 68/68 cases passed (0 ms)
// Your runtime beats 100 % of java submissions
// Your memory usage beats 11.24 % of java submissions (36.1 MB)
class Solution {
    // 前、中、后序遍历皆可
    public TreeNode invertTree(TreeNode root) {
        // base case
        if (root == null) {
            return root;
        }
        /**** 前序遍历位置 ****/
        TreeNode tmp = root.left;
        root.left = root.right;
        root.right = tmp;
        // 让左右子节点继续翻转它们的子节点
        invertTree(root.left);
        invertTree(root.right);
        return root;
    }
}
// @lc code=end

