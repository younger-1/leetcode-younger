// 剑指 Offer II 001. 整数除法
// https://leetcode-cn.com/problems/xoh6Oh/

#include <cmath>

// Time out
class Solution {
   public:
    int divide(int a, int b) {
        if (a == 0) {
            return 0;
        }
        if (a == INT_MIN && b == -1) {
            return INT_MAX;
        }
        if (a == INT_MIN && b == 1) {
            return INT_MIN;
        }
        // [7,3]=2 [7,-3]=-2 [-7,3]=-2 [-7,-3]=2
        // [-2147483648,-1]
        // [+2147483647,3]
        bool flag = a > 0 && b > 0 || a < 0 && b < 0;
        long aa = a, bb = b;
        aa = aa > 0 ? aa : -aa;
        bb = bb > 0 ? bb : -bb;
        int res = 0;
        while (aa >= bb) {
            aa -= bb;
            res++;
        }
        return flag ? res : -res;
    }
};

// TODO: redo
// 链接：https://leetcode-cn.com/problems/xoh6Oh/solution/cwei-yun-suan-by-kotori-5-qwu6/
class Solution_1 {
   public:
    int divide(int a, int b) {
        if (a == 0)
            return 0;
        if (a == INT_MIN && b == -1)
            return INT_MAX;
        if (a == INT_MIN && b == 1)
            return INT_MIN;

        bool sign = (a > 0) ^ (b > 0);
        long aa = abs(a);
        long bb = abs(b);
        int ans = 0;

        while (aa >= bb) {
            int i = 0;
            while (aa >= bb << i) {
                ++i;
            }
            aa -= (bb << (i - 1));
            ans += (1 << (i - 1));
        }
        return sign ? -ans : ans;
    }
};
