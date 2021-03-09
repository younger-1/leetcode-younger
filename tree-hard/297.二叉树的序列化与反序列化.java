/*
 * @lc app=leetcode.cn id=297 lang=java
 *
 * [297] 二叉树的序列化与反序列化
 */

/**
 * Definition for a binary tree node.
 */

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));


// @lc code=start

// 52/52 cases passed (18 ms)
// Your runtime beats 60.82 % of java submissions
// Your memory usage beats 96.74 % of java submissions (39.7 MB)
public class Codec {

    final String NULL = "#"; 
    final String SEP = ","; 
    
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root == null) {
            return "";
        }
        StringBuilder sb = new StringBuilder();
        // BFS, 层序遍历
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while (!q.isEmpty()) {
            TreeNode cur = q.poll();
            if (cur == null) {
                sb.append(NULL).append(SEP);
                continue;
            }
            sb.append(cur.val).append(SEP);
            q.offer(cur.left);
            q.offer(cur.right);
        }
        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data.isEmpty()) {
            return null;
        }
        String[] nodes = data.split(SEP);
        TreeNode root = new TreeNode(Integer.parseInt(nodes[0]));
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        int i = 1;
        while (i < nodes.length) {
            TreeNode parent = q.poll();

            String left = nodes[i];
            i += 1;
            if (!left.equals(NULL)) {
                parent.left = new TreeNode(Integer.parseInt(left));
                q.offer(parent.left);
            } else {
                parent.left = null;
            }

            String right = nodes[i];
            i += 1;
            if (!right.equals(NULL)) {
                parent.right = new TreeNode(Integer.parseInt(right));
                q.offer(parent.right);
            } else {
                parent.right = null;
            }
        }
        return root;
    }

}
// @lc code=end

// 52/52 cases passed (8 ms)
// Your runtime beats 97.66 % of java submissions
// Your memory usage beats 94.97 % of java submissions (39.8 MB)
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        serialize(root, sb);
        return sb.toString();
    }

    final String NULL = "#"; 
    final String SEP = ","; 
    /* helper func */
    void serialize(TreeNode root, StringBuilder sb) {
        if (root == null) {
            sb.append(NULL).append(SEP);
            return;
        }
        // 前序遍历, 后序遍历皆可
        sb.append(root.val).append(SEP);

        serialize(root.left, sb);
        serialize(root.right, sb);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String[] nodes = data.split(SEP);
        return deserialize(nodes);
    }

    /* helper func */
    int start = 0;
    TreeNode deserialize(String[] nodes) {
        if (start > nodes.length - 1) {
            return null;
        }
        if (nodes[start].equals(NULL)) {
            start += 1;
            return null;
        }
        int val = Integer.parseInt(nodes[start]);
        start += 1;
        TreeNode node = new TreeNode(val);
        node.left = deserialize(nodes);
        node.right = deserialize(nodes);
        return node;
    }

    // Or:
    // public TreeNode deserialize(String data) {
    //     LinkedList<String> nodes = new LinkedList<String>();
    //     for (String s : data.split(SEP)) {
    //         nodes.addLast(s);
    //     }
    //     return deserialize(nodes);
    // }

    // TreeNode deserialize(LinkedList<String> nodes) {
    //     if (nodes.isEmpty()) return null;
    //     String first = nodes.removeFirst();
    //     if (first.equals(NULL)) return null;
    //     TreeNode root = new TreeNode(Integer.parseInt(first));
    //     root.left = deserialize(nodes);
    //     root.right = deserialize(nodes);
    //     return root;
    // }
}


