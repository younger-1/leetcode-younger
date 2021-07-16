// 剑指 Offer 26. 树的子结构
// https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B) {
            return false;
        }
        return oneInAnother(A, B, false);
    }

   private:
    // B in A ?
    bool oneInAnother(TreeNode* A, TreeNode* B, bool begin) {
        if (!B) {
            return true;
        } else if (!A) {
            return false;
        }
        bool res = B->val == A->val && oneInAnother(B->left, A->left, true) && oneInAnother(B->right, A->right, true);
        if (!begin) {
            res = res || oneInAnother(B, A->left, false) || oneInAnother(B, A->right, false);
        }
        return res;
    }
};

class Solution_1 {
   public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B) {
            return false;
        }
        return dfs(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

   private:
    bool dfs(TreeNode* A, TreeNode* B) {
        if (!B) {
            return true;
        }
        if (!A) {
            return false;
        }
        return A->val == B->val && dfs(A->left, B->left) && dfs(A->right, B->right);
    }
};
