/*
 * @lc app=leetcode.cn id=863 lang=java
 *
 * [863] 二叉树中所有距离为 K 的结点
 */

/*
 * Definition for a binary tree node.
 */

public class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

// @lc code=start

// TODO: redo
class Solution {

    // 用map记录每个节点的父节点
    private Map<TreeNode, TreeNode> parents = new HashMap<>();

    private Set<TreeNode> used = new HashSet<>();

    // 找到目标节点后以目标节点为开始位置向三个方向蔓延
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        find(root, null, target);
        List<Integer> res = new LinkedList<>();
        dfs(target, res, K);
        return res;
    }

    private void find(TreeNode root, TreeNode parent, TreeNode target) {
        if (null == root) {
            return;
        }

        parents.put(root, parent);
        find(root.left, root, target);
        find(root.right, root, target);
    }

    private void dfs(TreeNode root, List<Integer> collector, int distance) {
        if (root != null && !used.contains(root)) {
            // 标记为已访问
            used.add(root);
            if (distance <= 0) {
                collector.add(root.val);
                return;
            }
            dfs(root.left, collector, distance - 1);
            dfs(root.right, collector, distance - 1);
            dfs(parents.get(root), collector, distance - 1);
        }
    }
}
// @lc code=end
