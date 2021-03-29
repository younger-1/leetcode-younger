/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */
#include <vector>

using namespace std;

// @lc code=start

// 32/32 cases passed (8 ms)
// Your runtime beats 88.47 % of cpp submissions
// Your memory usage beats 55.77 % of cpp submissions (9.8 MB)
class Solution {
   public:
    vector<int> singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int n : nums) {
            ret ^= n;
        }

        // 1100^1011 = 0111
        // 0111+1 = 1000
        // 当 ret 为 INT_MIN 时，会溢出
        // int diff_bit = (ret ^ (ret - 1)) + 1;

        int diff_bit = 1;
        while ((diff_bit & ret) == 0) {
            diff_bit <<= 1;
        }

        int foo = 0, bar = 0;
        for (int n : nums) {
            if (n & diff_bit) {
                foo ^= n;
            } else {
                bar ^= n;
            }
        }
        return {foo, bar};
    }
};
// @lc code=end
