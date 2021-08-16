// 剑指 Offer 46. 把数字翻译成字符串
// https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/

#include <vector>

using namespace std;

// @DP
class Solution {
   public:
    int translateNum(int num) {
        if (num == 0) {
            return 1;
        }
        vector<int> nums;
        while (num) {
            nums.push_back(num % 10);
            num /= 10;
        }
        int n = nums.size();
        vector<int> dp(n + 1);
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1];
            if (nums[i - 1] == 1 || nums[i - 1] == 2 && nums[i - 2] <= 5) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};

// @DFS
// https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/solution/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-by-leetcode-sol/434965
class Solution_1 {
   public:
    int translateNum(int num) { return f(num); }

    int f(int num) {
        if (num < 10) {
            return 1;
        }
        if (num % 100 < 26 && num % 100 > 9) {
            return f(num / 10) + f(num / 100);
        } else {
            return f(num / 10);
        }
    }
};
