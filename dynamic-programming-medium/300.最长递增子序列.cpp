/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

#include <cmath>
#include <vector>

using namespace std;

// @lc code=start

// @greedy @binary-search
// 54/54 cases passed (8 ms)
// Your runtime beats 95.81 % of cpp submissions
// Your memory usage beats 93.13 % of cpp submissions (10.1 MB)
class Solution {
   public:
    // 二分查找
    // 最长递增子序列和一种叫做 patience game 的纸牌游戏有关
    int lengthOfLIS(vector<int>& nums) {
        int top[nums.size()];
        int piles = 0;
        for (int i = 0; i < nums.size(); i++) {
            int poker = nums[i];
            int left = 0, right = piles;
            while (left < right) {
                int mid = (left + right) / 2;
                if (top[mid] >= poker) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            if (left == piles) {
                piles += 1;
            }
            top[left] = poker;
        }
        return piles;
    }
};
// @lc code=end

// 54/54 cases passed (408 ms)
// Your runtime beats 14.05 % of cpp submissions
// Your memory usage beats 34.15 % of cpp submissions (10.3 MB)
class Solution_1 {
   public:
    // DP
    int lengthOfLIS(vector<int>& nums) {
        // dp[i] 表示以 nums[i] 这个数结尾的最长递增子序列的长度
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j <= i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < dp.size(); i++) {
            res = max(res, dp[i]);
        }
        return res;
    }
};
