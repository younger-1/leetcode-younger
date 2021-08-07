// 面试题 04.06. 后继者
// https://leetcode-cn.com/problems/successor-lcci/

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution_0 {
   public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root || target) {
            return root;
        }
        inorderSuccessor(root->left, p);
        if (ok) {
            if (!target) {
                target = root;
            }
            return target;
        }
        if (root == p) {
            ok = true;
        }
        inorderSuccessor(root->right, p);
        return target;
    }

   private:
    TreeNode* target = nullptr;
    bool ok = false;
};

// TODO: redo
class Solution_1 {
   public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == nullptr)
            return nullptr;
        TreeNode* res = inorderSuccessor(root->left, p);
        if (res != nullptr)
            return res;
        // 遇到第一个大于 p->val 的即可返回
        if (root->val > p->val)
            return root;
        return inorderSuccessor(root->right, p);
    }
};

class Solution_2 {
   public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == nullptr) {
            return nullptr;
        }
        // 当前节点值小于等于目标值，那么当前目标值的后继者必然在右子树
        if (p->val >= root->val) {
            return inorderSuccessor(root->right, p);
        }
        // 否则结果有可能是当前节点，或者在当前节点的左子树中
        // 那么先去左子树找一下试试，找不到的话返回当前节点即是结果
        TreeNode* node = inorderSuccessor(root->left, p);
        return node ? node : root;
    }
};
