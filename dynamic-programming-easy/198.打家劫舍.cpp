/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include <vector>

using namespace std;

// @lc code=start

// 68/68 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 58.46 % of cpp submissions (7.6 MB)
class Solution {
   private:
    int* memo;

   public:
    int rob(vector<int>& nums) {
        memo = new int[nums.size()];
        for (int i = 0; i < nums.size(); i++) {
            memo[i] = -1;
        }
        int res = dp(nums, 0);
        delete[] memo;
        return res;
    }

    int dp(vector<int>& nums, int i) {
        if (i >= nums.size()) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        memo[i] = max(nums[i] + dp(nums, i + 2), dp(nums, i + 1));
        return memo[i];
    }
};

// @lc code=end

// 68/68 cases passed (4 ms)
// Your runtime beats 39.46 % of cpp submissions
// Your memory usage beats 65.04 % of cpp submissions (7.5 MB)
class Solution_1 {
   private:
    vector<int> memo;

   public:
    int rob(vector<int>& nums) {
        memo = vector<int>(nums.size(), -1);
        return dp(nums, nums.size() - 1);
    }
    int dp(vector<int>& nums, int i) {
        if (i < 0) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        memo[i] = max(nums[i] + dp(nums, i - 2), dp(nums, i - 1));
        return memo[i];
    }
};