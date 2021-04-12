/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
// 229/229 cases passed (8 ms)
// Your runtime beats 89.79 % of cpp submissions
// Your memory usage beats 93.02 % of cpp submissions (10.7 MB)
class Solution {
   public:
    string largestNumber(vector<int>& nums) {
        // 对于 [4,42]，需要把 4 放在前面；
        // 对于 [4,45]，需要把 45 放在前面。
        sort(nums.begin(), nums.end(), [](int x, int y) {
            long sx = 10, sy = 10;
            while (sx <= x) {
                sx *= 10;
            }
            while (sy <= y) {
                sy *= 10;
            }
            return x * sy + y > y * sx + x;
        });
        if (nums[0] == 0) {
            return "0";
        }
        string res;
        for (int x : nums) {
            res += to_string(x);
        }
        return res;
    }
};
// @lc code=end
