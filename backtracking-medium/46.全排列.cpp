/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include <vector>

using namespace std;

// @lc code=start

// 25/25 cases passed (4 ms)
// Your runtime beats 70.42 % of cpp submissions
// Your memory usage beats 87.63 % of cpp submissions (7.4 MB)
class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrace(res, nums, 0);
        return res;
    }
    void backtrace(vector<vector<int>>& res, vector<int>& path, int first) {
        if (first == path.size()) {
            // note: emplace_back, return
            res.emplace_back(path);
            return;
        }
        for (int i = first; i < path.size(); i += 1) {
            swap(path[i], path[first]);
            backtrace(res, path, first + 1);
            swap(path[i], path[first]);
        }
    }
};
// @lc code=end
