/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
   public:
    int countDigitOne(int n) {
        int ans = 0;
        long k = 1;
        while (k <= n) {
            ans += n / (10 * k) * k + min(k, max(0L, n % (10 * k) - k + 1));
            k *= 10;
        }
        return ans;
    }
};
// @lc code=end

class Solution_1 {
   public:
    int countDigitOne(int n) {
        long num = n, i = 1, s = 0;

        while (num)  //分别计算个、十、百......千位上1出现的次数，再求和。
        {
            if (num % 10 == 0)
                s += (num / 10) * i;

            if (num % 10 == 1)
                s += (num / 10) * i + (n % i) + 1;

            if (num % 10 > 1)
                s += (num / 10) * i + i;

            num /= 10;
            i *= 10;
        }
        return s;
    }
};
