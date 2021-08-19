/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include <climits>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int lo = INT_MAX;
        for (int p : prices) {
            if (p < lo) {
                lo = p;
            } else {
                ans = max(ans, p - lo);
            }
        }
        return ans;
    }
};

// @lc code=end
