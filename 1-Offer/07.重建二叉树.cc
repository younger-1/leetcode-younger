// 剑指 Offer 07. 重建二叉树
// https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/

/*
 * Definition for a binary tree node.
 */

#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
对于任意一颗树而言，前序遍历的形式总是
    [ 根节点, [左子树的前序遍历结果], [右子树的前序遍历结果] ]
即根节点总是前序遍历中的第一个节点。
而中序遍历的形式总是
    [ [左子树的中序遍历结果], 根节点, [右子树的中序遍历结果] ]
 */
// @DFS
class Solution {
   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        // 构造哈希映射，帮助我们快速定位根节点
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }
        return build(preorder, 0, n - 1, inorder, 0, n - 1);
    }

   private:
    unordered_map<int, int> index;
    TreeNode* build(vector<int>& preorder, int pre_start, int pre_end, vector<int>& inorder, int in_start, int in_end) {
        // 递归终止条件
        if (pre_start > pre_end) {
            return nullptr;
        }
        int mid_val = preorder[pre_start];
        int idx = index[mid_val];
        int left_size = idx - in_start;
        TreeNode* root = new TreeNode(mid_val);
        root->left = build(preorder, pre_start + 1, pre_start + left_size, inorder, in_start, idx - 1);
        root->right = build(preorder, pre_start + left_size + 1, pre_end, inorder, idx + 1, in_end);
        return root;
    }
};

#include <stack>

// TODO: redo
// @iteration @stack
class Solution_1 {
   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (!preorder.size()) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> stk;
        stk.push(root);
        int inorderIndex = 0;
        for (int i = 1; i < preorder.size(); ++i) {
            int preorderVal = preorder[i];
            TreeNode* node = stk.top();
            if (node->val != inorder[inorderIndex]) {
                node->left = new TreeNode(preorderVal);
                stk.push(node->left);
            } else {
                while (!stk.empty() && stk.top()->val == inorder[inorderIndex]) {
                    node = stk.top();
                    stk.pop();
                    ++inorderIndex;
                }
                node->right = new TreeNode(preorderVal);
                stk.push(node->right);
            }
        }
        return root;
    }
};
