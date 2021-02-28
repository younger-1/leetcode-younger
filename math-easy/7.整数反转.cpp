/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
#include <cmath>
// @lc code=start
class Solution {
   public:
    // 1032/1032 cases passed (0 ms)
    // Your runtime beats 100 % of cpp submissions
    // Your memory usage beats 73.29 % of cpp submissions (5.8 MB)
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) {
                return 0;
            }
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) {
                return 0;
            }
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
// @lc code=end
