/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除与获得点数
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution_1 {
   private:
    int rob(vector<int> &nums) {
        int size = nums.size();
        int first = nums[0], second = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }

   public:
    int deleteAndEarn(vector<int> &nums) {
        int maxVal = 0;
        for (int val : nums) {
            maxVal = max(maxVal, val);
        }
        vector<int> sum(maxVal + 1);
        for (int val : nums) {
            sum[val] += val;
        }
        return rob(sum);
    }
};
// @lc code=end

// @DP
#include <unordered_map>
class Solution_2 {
   public:
    int deleteAndEarn(vector<int> &nums) {
        unordered_map<int, int> trans, dp;
        int maxID = 0;
        for (const int &num : nums) {
            trans[num] += num;
            maxID = max(maxID, num);
        }
        dp[0] = 0;
        dp[1] = trans[1];
        for (int i = 2; i <= maxID; ++i)
            dp[i] = max(dp[i - 2] + trans[i], dp[i - 1]);
        return dp[maxID];
    }
};
