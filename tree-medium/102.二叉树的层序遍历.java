/*
 * @lc app=leetcode.cn id=102 lang=java
 *
 * [102] 二叉树的层序遍历
 */

/**
 * Definition for a binary tree node.
 */
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

// @lc code=start

// 34/34 cases passed (1 ms)
// Your runtime beats 94.44 % of java submissions
// Your memory usage beats 93.47 % of java submissions (38.4 MB)
class Solution {
    // DFS
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if (root == null) {
            return res;
        }
        this.dfs(root, 0, res);
        return res;
    }
    private void dfs(TreeNode root, int level, List<List<Integer>> res) {
        if (null == root) {
            return;
        }
        if (res.size() < level + 1) {
            res.add(new ArrayList<Integer>());
        }
        res.get(level).add(root.val);
        this.dfs(root.left, level + 1, res); 
        this.dfs(root.right, level + 1, res); 
    }
}
// @lc code=end

// 34/34 cases passed (1 ms)
// Your runtime beats 94.44 % of java submissions
// Your memory usage beats 22.37 % of java submissions (38.8 MB)
class Solution_0 {
    // BFS
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if (root == null) {
            return res;
        }
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            List<Integer> level = new ArrayList<Integer>();
            int currentLevelSize = queue.size();
            for (int i = 0; i < currentLevelSize; i++) {
                TreeNode node = queue.poll();
                level.add(node.val);
                if (node.left != null) {
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                }
            }
            res.add(level);
        }
        return res;
    }
}

