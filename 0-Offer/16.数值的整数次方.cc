// 剑指 Offer 16. 数值的整数次方
// https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/
// 注意：本题与主站 50 题相同：https://leetcode-cn.com/problems/powx-n/

class Solution {
   public:
    double myPow(double x, int n) {
        if (x == 1) {
            return x;
        }
        long m = n;
        if (m < 0) {
            m = -m;
            x = 1 / x;
        }
        // if n==0: return 1
        double ans = 1;
        while (m) {
            if (m & 1) {
                ans *= x;
            }
            m >>= 1;
            x *= x;
        }
        return ans;
    }
};
