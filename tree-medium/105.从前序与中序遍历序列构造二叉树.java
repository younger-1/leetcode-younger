/*
 * @lc app=leetcode.cn id=105 lang=java
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
// Your runtime beats 49.33 % of java submissions
// Your memory usage beats 85.11 % of java submissions (38.3 MB)
class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return build(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1);
    }

    TreeNode build(int[] preorder, int preStart, int preEnd, int[] inorder, int inStart, int inEnd) {
        if (preStart > preEnd) {
            return null;
        }

        int val = preorder[preStart];
        int idx = 0;
        for (int i = 0; i < inorder.length; i++) {
            if (inorder[i] == val) {
                idx = i;
                break;
            }
        }
        TreeNode root = new TreeNode(val);
        // 左子树的节点个数
        int leftSize = idx - inStart;
        root.left = build(preorder, preStart + 1, preStart + leftSize, inorder, inStart, idx - 1);
        root.right = build(preorder, preStart + leftSize + 1, preEnd, inorder, idx + 1, inEnd);
        return root;
    }
}
// @lc code=end

