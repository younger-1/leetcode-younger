/*
 * @lc app=leetcode.cn id=230 lang=java
 *
 * [230] 二叉搜索树中第K小的元素
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

// 93/93 cases passed (0 ms)
// Your runtime beats 100 % of java submissions
// Your memory usage beats 52.95 % of java submissions (38.3 MB)
class Solution {
    public int kthSmallest(TreeNode root, int k) {
        this.k = k;
        traverse(root);
        return res;
    }

    int k;
    int res = 0;
    int rank = 0;
    void traverse(TreeNode root) {
        if (root == null) {
            return;
        }

        traverse(root.left);
        // 中序遍历
        rank += 1;
        if (rank == k) {
            res = root.val;
            return;
        }
        traverse(root.right);
    }
}
// @lc code=end

