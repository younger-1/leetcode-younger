/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
    vector<vector<int>> res;
    vector<int> combine;

   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0);
        return res;
    }

    void dfs(vector<int>& candidates, int target, int idx) {
        if (idx == candidates.size()) {
            return;
        }
        if (target == 0) {
            res.emplace_back(combine);
            return;
        }
        // idx+1，直接跳过，没有选择和撤销
        dfs(candidates, target, idx + 1);
        // 选择当前数
        if (target - candidates[idx] >= 0) {
            // 做选择
            combine.emplace_back(candidates[idx]);
            // idx 不变, 能够继续选择 idx
            dfs(candidates, target - candidates[idx], idx);
            // 撤销选择
            combine.pop_back();
        }
    }
};
// @lc code=end
