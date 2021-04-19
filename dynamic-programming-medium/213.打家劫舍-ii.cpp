/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */
#include <vector>

using namespace std;

// @lc code=start

// 74/74 cases passed (4 ms)
// Your runtime beats 40.14 % of cpp submissions
// Your memory usage beats 39.84 % of cpp submissions (7.8 MB)
class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        return max(rob_range(nums, 0, n - 2), rob_range(nums, 1, n - 1));
    }

    int rob_range(vector<int>& nums, int start, int end) {
        int n = nums.size();
        vector<int> dp(n + 2, 0);
        // 从后往前
        for (int i = end; i >= start; i--) {
            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        }
        return dp[start];
    }
};
// @lc code=end

class Solution_1 {
   public:
    int robRange(vector<int>& nums, int start, int end) {
        // dp[i]=max(dp[i−2]+nums[i],dp[i−1])
        // 滚动数组边界条件：dp[start]=nums[start], dp[start+1]=max(nums[start],nums[start+1])
        int first = nums[start], second = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }

    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) {
            return nums[0];
        } else if (len == 2) {
            return max(nums[0], nums[1]);
        }
        return max(robRange(nums, 0, len - 2), robRange(nums, 1, len - 1));
    }
};
