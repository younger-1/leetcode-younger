/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

#include <queue>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start

// 4ms 11.7MB
class Solution {
   public:
    // BFS
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        queue<TreeNode *> q{{root}};
        if (nullptr == root)
            return res;
        while (false == q.empty()) {
            vector<int> elem;
            int len = q.size();
            // or: for(int i = q.size(); i>0; i--)
            for (int i = 0; i != len; i++) {
                TreeNode *tmp = q.front();
                q.pop();
                if (tmp->left != nullptr)  // 等价于：if(tmp->left)
                    q.push(tmp->left);
                if (tmp->right != nullptr)
                    q.push(tmp->right);
                elem.push_back(tmp->val);
            }
            res.push_back(elem);
        }
        return res;
    }
};
// @lc code=end
