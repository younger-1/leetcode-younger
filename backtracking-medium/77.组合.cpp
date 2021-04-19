/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include <vector>

using namespace std;

// @lc code=start

// 27/27 cases passed (32 ms)
// Your runtime beats 36.13 % of cpp submissions
// Your memory usage beats 56.03 % of cpp submissions (9.8 MB)
class Solution {
   private:
    vector<vector<int>> res;
    void backtrace(int n, int k, int start, vector<int>& track) {
        if (track.size() == k) {
            res.push_back(track);
            return;
        }
        // 注意 i 从 start 开始递增
        for (int i = start; i <= n; i++) {
            track.push_back(i);
            backtrace(n, k, i + 1, track);
            track.pop_back();
        }
    }

   public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> track;
        backtrace(n, k, 1, track);
        return res;
    }
};
// @lc code=end
