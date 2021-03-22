/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */
#include <iostream>

// @lc code=start
class Solution {
   public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while (n) {
            // n&(n-1) 去掉最低位的1
            n &= n - 1;
            ret++;
        }
        return ret;
    }
};
// @lc code=end

class Solution_1 {
   public:
    int hammingWeight(uint32_t n) {
        int ones = 0;
        while (n > 0) {
            if ((n & 1) == 1) {
                ones += 1;
            }
            n >>= 1;
        }
        return ones;
    }
};