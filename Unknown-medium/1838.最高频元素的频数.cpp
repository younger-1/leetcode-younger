/*
 * @lc app=leetcode.cn id=1838 lang=cpp
 *
 * [1838] 最高频元素的频数
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start

// @sliding-window
class Solution {
   public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, right = 0, ans = 0;
        // sum 为窗口内元素和
        long sum = 0;
        while (right < n) {
            while ((long)(right - left) * nums[right] - sum > k) {
                sum -= nums[left++];
            }
            sum += nums[right++];
            ans = max(ans, (right - left));
        }
        return ans;
    }
};
// @lc code=end

class Solution_1 {
   public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // total 为窗口内所需提高的数之和
        long long total = 0;
        int l = 0, res = 1;
        for (int r = 1; r < n; ++r) {
            total += (long long)(nums[r] - nums[r - 1]) * (r - l);
            while (total > k) {
                total -= nums[r] - nums[l];
                ++l;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
