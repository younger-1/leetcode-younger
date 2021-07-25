// 剑指 Offer 36. 二叉搜索树与双向链表
// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/
// 注意：本题与主站 426
// 题相同：https://leetcode-cn.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/

/*
 * Definition for a Node.
 */

class Node {
   public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution_0 {
   public:
    Node* treeToDoublyList(Node* root) {
        if (!root) {
            return nullptr;
        }
        if (root->left == nullptr && root->right == nullptr) {
            root->left = root;
            root->right = root;
            return root;
        }

        Node* a = root;
        if (root->left) {
            a = treeToDoublyList(root->left);
            // a_end<->root
            a->left->right = root;
            root->left = a->left;
        }

        Node* b = new Node(0, root, nullptr);
        Node* rr = root->right;
        if (root->right) {
            b = treeToDoublyList(root->right);
        }

        // a<->b_end
        a->left = b->left;
        b->left->right = a;

        if (rr) {
            // root<->b
            root->right = b;
            b->left = root;
        }

        return a;
    }
};

class Solution_01 {
   public:
    Node* treeToDoublyList(Node* root) {
        if (!root) {
            return nullptr;
        }

        Node *a = root, *a_end = root;
        if (root->left) {
            a = treeToDoublyList(root->left);
            a_end = a->left;
        }

        Node *b = root, *b_end = root;
        if (root->right) {
            b = treeToDoublyList(root->right);
            b_end = b->left;
        }

        // 1
        a_end->right = root;
        b->left = root;

        // 2
        root->right = b;
        root->left = a_end;

        // 3
        b_end->right = a;
        a->left = b_end;

        return a;
    }
};
