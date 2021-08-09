/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 */

/**
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

// @lc code=start

// https://leetcode-cn.com/problems/path-sum-iii/solution/yi-pian-wen-zhang-jie-jue-suo-you-er-cha-smch/
class Solution_1 {
   public:
    int pathSum(TreeNode *root, int sum) {
        if (!root) {
            return 0;
        }
        dfs(root, sum);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        return res;
    }

   private:
    int res;
    void dfs(TreeNode *node, int sum) {
        if (!node) {
            return;
        }
        sum -= node->val;
        if (sum == 0) {
            res++;
        }
        dfs(node->left, sum);
        dfs(node->right, sum);
    }
};
// @lc code=end

#include <unordered_map>

using namespace std;

// 链接：https://leetcode-cn.com/problems/path-sum-iii/solution/rang-ni-miao-dong-de-hui-su-qian-zhui-he-ou6t/
class Solution {
   private:
    unordered_map<int, int> prefix;  // <前缀和，其出现次数>
    void dfs(TreeNode *root, int sum, int cur_sum, int &res) {
        if (!root)
            return;
        cur_sum += root->val;  // 更新前缀和
        // 当前路径中存在以当前节点为终点的和为sum的子路径
        if (prefix.find(cur_sum - sum) != prefix.end())
            res += prefix[cur_sum - sum];
        prefix[cur_sum]++;                    // 将当前节点加入路径
        dfs(root->left, sum, cur_sum, res);   // 在其左子树中递归寻找
        dfs(root->right, sum, cur_sum, res);  // 在其右子树中递归寻找
        prefix[cur_sum]--;                    // 回溯
    }

   public:
    int pathSum(TreeNode *root, int sum) {
        int res = 0;    // 满足条件的路径数量
        prefix[0] = 1;  // 前缀和为0的路径只有一条：哪个节点都不选
        dfs(root, sum, 0, res);
        return res;
    }
};
