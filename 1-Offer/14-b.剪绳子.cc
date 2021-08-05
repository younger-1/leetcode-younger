// 剑指 Offer 14- II. 剪绳子 II
// https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof/
// 答案需要取模 1e9+7（1000000007）

class Solution {
    int mod = 1'000'000'007;

   public:
    int cuttingRope(int n) {
        if (n <= 3) {
            return n - 1;
        }
        long res = 1;
        while (n > 4) {
            res *= 3;
            res %= mod;
            n -= 3;
        }
        return (res * n) % mod;
    }
};
