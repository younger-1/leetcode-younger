/*
 * @lc app=leetcode.cn id=987 lang=cpp
 *
 * [987] 二叉树的垂序遍历
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

#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

// @lc code=start

// TODO: redo
// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/vertical-order-traversal-of-a-binary-tree/solution/er-cha-shu-de-chui-xu-bian-li-by-leetcod-clsh/
class Solution {
   public:
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        vector<tuple<int, int, int>> nodes;

        function<void(TreeNode *, int, int)> dfs = [&](TreeNode *node, int row, int col) {
            if (!node) {
                return;
            }
            nodes.emplace_back(col, row, node->val);
            dfs(node->left, row + 1, col - 1);
            dfs(node->right, row + 1, col + 1);
        };

        dfs(root, 0, 0);
        sort(nodes.begin(), nodes.end());
        vector<vector<int>> ans;
        int lastcol = INT_MIN;
        for (const auto &[col, row, value] : nodes) {
            if (col != lastcol) {
                lastcol = col;
                ans.emplace_back();
            }
            ans.back().push_back(value);
        }
        return ans;
    }
};

// @lc code=end

// 链接：https://leetcode-cn.com/problems/vertical-order-traversal-of-a-binary-tree/solution/987-er-cha-shu-de-chui-xu-bian-li-c-jie-5xqdx/

#include <map>
#include <queue>

class Solution_1 {
   public:
    map<int, priority_queue<tuple<int, int, int>>> ss;
    vector<vector<int>> ans;

    void dfs(int x, int y, TreeNode *root) {
        if (!root)
            return;
        ss[y].push({-x, -y, -root->val});
        dfs(x + 1, y - 1, root->left);
        dfs(x + 1, y + 1, root->right);
        return;
    }

    vector<vector<int>> verticalTraversal(TreeNode *root) {
        if (!root)
            return ans;
        dfs(0, 0, root);
        for (auto &[x, y] : ss) {
            ans.push_back(vector<int>());
            while (!y.empty()) {
                ans.back().push_back(-get<2>(y.top()));
                y.pop();
            }
        }
        return ans;
    }
};

// Wrong
class Solution_0 {
   public:
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        idx = 0;
        dfs(root);
        return ans;
    }
    int idx;
    vector<vector<int>> ans;
    void dfs(TreeNode *root) {
        if (root == nullptr) {
            if (idx < 0) {
                idx = -1;
            }
            return;
        }
        idx--;
        dfs(root->left);
        idx++;
        if (ans.size() < idx + 1) {
            ans.push_back(vector<int>());
        }
        ans[idx].push_back(root->val);
        idx++;
        dfs(root->right);
        idx--;
    }
};
