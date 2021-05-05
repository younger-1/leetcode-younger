/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 */

using namespace std;
#include <string>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
// 20ms 23MB
// @递归
class Solution {
   public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r) {
        if (r < l)
            return NULL;
        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, l, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, r);
        return root;
    }
};

// @lc code=end

// fail
class Solution0 {
   public:
    int dfs_inorder(TreeNode* node, int levels, int k, vector<int>& nums) {
        if (levels == 1) {
            if (k == nums.size())
                return k;
            node->val = nums[k];
            return k + 1;
        }
        if (k < nums.size()) {
            TreeNode* left_tree = new TreeNode(-1);
            node->left = left_tree;
            k = dfs_inorder(node->left, levels - 1, k, nums);
        }
        node->val = nums[k];

        if (k == nums.size()) {
            return k;
        }
        k++;

        if (k < nums.size()) {
            TreeNode* right_tree = new TreeNode(-1);
            node->right = right_tree;
            k = dfs_inorder(node->right, levels - 1, k, nums);
        }

        return k;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int levels = 0;
        int len = nums.size();
        while (len > 0) {
            len >> 1;
            levels++;
        }
        TreeNode* middle = new TreeNode(nums[0]);
        int k = 1;
        for (int i = 1; i != levels + 1; i++) {
            TreeNode* temp = new TreeNode(nums[k]);
            temp->left = middle;
            middle = temp;
            TreeNode* right_tree = new TreeNode(-1);
            middle->right = right_tree;
            k = dfs_inorder(right_tree, i, k + 1, nums);
        }
    }
};