// 剑指 Offer 32 - III. 从上到下打印二叉树 III
// https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/

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
        int id = 0;
        while (!q.empty()) {
            int size = q.size();
            level.clear();
            while (size--) {
                TreeNode* n = q.front();
                q.pop();
                if (!n) {
                    continue;
                }
                if ((id & 1) == 0) {
                    level.push_back(n->val);
                } else {
                    level.insert(level.begin(), n->val);
                }
                q.push(n->left);
                q.push(n->right);
            }
            if (!level.empty()) {
                ans.push_back(level);
            }
            id++;
        }
        return ans;
    }
};
