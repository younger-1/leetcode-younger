/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */
#include <string>
#include <vector>

using namespace std;

// @lc code=start

// 600/600 cases passed (4 ms)
// Your runtime beats 50.83 % of cpp submissions
// Your memory usage beats 78.49 % of cpp submissions (5.8 MB)
// 位运算分治
class Solution {
   private:
    const uint32_t M1 = 0x55555555;  // 01010101010101010101010101010101
    const uint32_t M2 = 0x33333333;  // 00110011001100110011001100110011
    const uint32_t M4 = 0x0f0f0f0f;  // 00001111000011110000111100001111
    const uint32_t M8 = 0x00ff00ff;  // 00000000111111110000000011111111
   public:
    uint32_t reverseBits(uint32_t n) {
        n = (n & M1) << 1 | (n >> 1) & M1;
        n = (n & M2) << 2 | (n >> 2) & M2;
        n = (n & M4) << 4 | (n >> 4) & M4;
        n = (n & M8) << 8 | (n >> 8) & M8;

        return n << 16 | n >> 16;
    }
};

// @lc code=end

// 600/600 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 43.32 % of cpp submissions (5.9 MB)
// 逐位颠倒
class Solution_1 {
   public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev = 0;
        for (int i = 0; n > 0; i++) {
            // 从低位往高位枚举 n 的每一位
            rev |= (n & 1) << (31 - i);
            n >>= 1;
        }
        return rev;
    }
};
