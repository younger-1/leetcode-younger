/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

#include <vector>

using namespace std;

// @lc code=start

// TODO: redo
class Solution_1 {
   public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }

        int ans = 0, t = 0;
        int d = nums[1] - nums[0];

        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i - 1] == d) {
                t++;
            } else {
                t = 0;
                d = nums[i] - nums[i - 1];
            }
            ans += t;
        }
        return ans;
    }
};
// @lc code=end

class Solution_2 {
   public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), l = 0, ans = 0;
        for (int i = 2; i < n; i++)
            nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2] ? ans += ++l : l = 0;
        return ans;
    }
};

#include <numeric>

class Solution_3 {
   public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        // dp[i]表示从nums[0]到nums[i]且以nums[i]为结尾的等差数列子数组的数量
        vector<int> dp(n);
        for (int i = 2; i < n; i++) {
            dp[i] = nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2] ? dp[i - 1] + 1 : 0;
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
