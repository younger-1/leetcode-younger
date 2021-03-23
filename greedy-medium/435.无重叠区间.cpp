/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */
#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start

// 18/18 cases passed (16 ms)
// Your runtime beats 91.9 % of cpp submissions
// Your memory usage beats 86.1 % of cpp submissions (9 MB)
class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
        int n = intervals.size();
        int res = 0;
        int prev = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < prev) {
                res += 1;
            } else {
                prev = intervals[i][1];
            }
        }

        return res;
    }
};
// @lc code=end
