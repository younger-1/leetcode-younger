/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
using namespace std;
#include <vector>

// @lc code=start
// 0ms 6MB
class Solution {
   public:
    int climbStairs(int n) {
        vector<int> res(n + 1, 0);

        res[0] = res[1] = 1;
        for (int i = 2; i != n + 1; i++) {
            res[i] = res[i - 1] + res[i - 2];
        }
        return res[n];
    }
};
// @lc code=end
