/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    // 61/61 cases passed (32 ms)
    // Your runtime beats 96.89 % of cpp submissions
    // Your memory usage beats 36.55 % of cpp submissions (17 MB)
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for (auto n : nums)
            a ^= n;
        return a;
    }
};
// @lc code=end
