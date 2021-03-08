/*
 * @lc app=leetcode.cn id=116 lang=java
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

// @lc code=start

// 58/58 cases passed (2 ms)
// Your runtime beats 67.57 % of java submissions
// Your memory usage beats 8.82 % of java submissions (39 MB)
class Solution {
    public Node connect(Node root) {
        if (null == root) {
            return null;
        }
        connectTwoNode(root.left, root.right);
        return root;
    }
    void connectTwoNode(Node a, Node b) {
        if (a == null || b == null) {
            return;
        }
        a.next = b;
        connectTwoNode(a.left, a.right);
        connectTwoNode(b.left, b.right);
        connectTwoNode(a.right, b.left);
    }
}
// @lc code=end

