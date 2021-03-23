/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */
#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start

// 45/45 cases passed (164 ms)
// Your runtime beats 76.74 % of cpp submissions
// Your memory usage beats 65.72 % of cpp submissions (34.1 MB)
class Solution {
   public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
        int right = points[0][1];
        int res = 1;
        for (auto& point : points) {
            if (point[0] <= right) {
                continue;
            }
            right = point[1];
            res++;
        }

        return res;
    }
};
// @lc code=end
