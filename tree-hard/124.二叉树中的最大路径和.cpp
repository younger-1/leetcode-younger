/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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

#include <cmath>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    int maxPathSum(TreeNode *root) {
        vector<int> res;
        oneSide(root);
        return ans;
    }

   private:
    int ans = INT_MIN;
    int oneSide(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int left = max(0, oneSide(root->left));
        int right = max(0, oneSide(root->right));
        ans = max(ans, left + right + root->val);
        return max(left, right) + root->val;
    }
};
// @lc code=end
