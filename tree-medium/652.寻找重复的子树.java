/*
 * @lc app=leetcode.cn id=652 lang=java
 *
 * [652] 寻找重复的子树
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

// 175/175 cases passed (27 ms)
// Your runtime beats 51.23 % of java submissions
// Your memory usage beats 46.03 % of java submissions (43.4 MB)
class Solution {
    HashMap<String, Integer> map = new HashMap<>();
    List<TreeNode> res = new LinkedList<>();

    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        traverse(root);
        return res;
    }

    String traverse(TreeNode root) {
        if (root == null) {
            return "#";
        }
        String left = traverse(root.left);
        String right = traverse(root.right);

        String subTree = left + ',' + right + ',' + root.val;

        int freq = map.getOrDefault(subTree, 0);
        if (freq == 1) {
            res.add(root);
        }

        map.put(subTree, freq + 1);

        return subTree;
    }
}
// @lc code=end

// fail
class Solution_0 {
    List<TreeNode> subtrees = new ArrayList<>();
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        isDupTree(root);
        return result;
    }
    boolean isDupTree(TreeNode root) {

        boolean left, right = false, false;
        if (isDupTree(root.left)) {
            left = true;
        }
        if (isDupTree(root.right)) {
            right = true;
        }

        if (left && right) {
            this.subtrees.add(root);
            return true;
        }
        return false
    }
}

