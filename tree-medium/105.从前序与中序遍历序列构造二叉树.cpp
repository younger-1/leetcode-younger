/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mem[inorder[i]] = i;
        }
        return dfs(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

   private:
    unordered_map<int, int> mem;
    TreeNode *dfs(vector<int> &preorder, vector<int> &inorder, int pre_start, int pre_end, int in_start, int in_end) {
        if (pre_start > pre_end) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[pre_start]);
        int idx = mem[preorder[pre_start]];
        int size = idx - in_start;
        root->left = dfs(preorder, inorder, pre_start + 1, pre_start + size, in_start, idx - 1);
        root->right = dfs(preorder, inorder, pre_start + size + 1, pre_end, idx + 1, in_end);
        return root;
    }
};
// @lc code=end
