/*
 * @lc app=leetcode.cn id=106 lang=java
 *
 * [106] 从中序与后序遍历序列构造二叉树
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

// 202/202 cases passed (4 ms)
// Your runtime beats 48.86 % of java submissions
// Your memory usage beats 21.91 % of java submissions (38.8 MB)
class Solution {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return build(inorder, 0, inorder.length - 1, postorder, 0, postorder.length - 1);
    }
    
    TreeNode build(int[] inorder, int inStart, int inEnd, int[] postorder, int postStart, int postEnd) {
        if (inStart > inEnd) {
            return null;
        }
        int val = postorder[postEnd];
        int idx = 0;
        for (int i = 0; i < inorder.length; i++) {
            if (inorder[i] == val) {
                idx = i;
                break;
            }
        }
        TreeNode root = new TreeNode(val);
        int leftSize = idx - inStart;
        root.left = build(inorder, inStart, idx - 1, postorder, postStart, postStart + leftSize - 1);
        root.right = build(inorder, idx + 1, inEnd, postorder, postStart + leftSize, postEnd - 1);
        return root;
    }
}
// @lc code=end

