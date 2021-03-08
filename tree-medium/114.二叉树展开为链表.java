/*
 * @lc app=leetcode.cn id=114 lang=java
 *
 * [114] 二叉树展开为链表
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

// 225/225 cases passed (0 ms)
// Your runtime beats 100 % of java submissions
// Your memory usage beats 72.85 % of java submissions (37.8 MB)
class Solution {
    public void flatten(TreeNode root) {
        // base case
        if (root == null) {
            return;
        }

        flatten(root.left);
        flatten(root.right);

        /**** 后序遍历位置 ****/
        TreeNode right = root.right;
        root.right = root.left;
        root.left = null;

        // 新右子树末端接上原来的右子树
        while (root.right != null) {
            root = root.right;
        }
        root.right = right;

    }
}
// @lc code=end

// 225/225 cases passed (0 ms)
// Your runtime beats 100 % of java submissions
// Your memory usage beats 24.43 % of java submissions (38.1 MB)
class Solution_0 {
    public void flatten(TreeNode root) {
        if (root == null) {
            return;
        }
        lastNodeAfterFlatten(root);
    }
    TreeNode lastNodeAfterFlatten(TreeNode root) {
        if (root.left != null) {
            TreeNode leftLast = lastNodeAfterFlatten(root.left);
            leftLast.right = root.right;
            root.right = root.left;
            root.left = null;
        }
        return root.right == null ? root : lastNodeAfterFlatten(root.right);
    }
}

