// 剑指 Offer 10- I. 斐波那契数列
// https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/

class Solution {
   public:
    int fib(int n) {
        int mod = 1e9 + 7;
        int a = 0, b = 1;
        while (n--) {
            b %= mod;
            int tmp = b;
            b += a;
            a = tmp;
        }
        return a;
    }
};
