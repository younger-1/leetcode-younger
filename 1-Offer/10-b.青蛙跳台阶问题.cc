// 剑指 Offer 10- II. 青蛙跳台阶问题
// https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/

#include <vector>

using namespace std;

class Solution {
   public:
    int numWays(int n) {
        int mod = 1e9 + 7;
        vector<int> dp(n + 1, 1);
        for (int i = 2; i < n + 1; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        }
        return dp[n];
    }
};