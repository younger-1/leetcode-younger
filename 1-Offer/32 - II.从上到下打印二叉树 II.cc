// 剑指 Offer 32 - II. 从上到下打印二叉树 II
// https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> level;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            level.clear();
            while (size--) {
                TreeNode* n = q.front();
                q.pop();
                if (!n) {
                    continue;
                }
                level.push_back(n->val);
                q.push(n->left);
                q.push(n->right);
            }
            if (!level.empty())
                ans.push_back(level);
        }
        return ans;
    }
};
