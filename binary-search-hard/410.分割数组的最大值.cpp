/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */
#include <vector>

using namespace std;

// @lc code=start

class Solution {
   public:
    int splitArray(vector<int>& nums, int m) {
        long long left = 0, right = 0;
        for (int i = 0; i != nums.size(); i += 1) {
            right += nums[i];
            if (nums[i] > left) {
                left = nums[i];
            }
        }
        while (left < right) {
            long long mid = (left + right) >> 1;
            // 为使 mid 尽可能小，check() 中 cnt<=m 保证了紧收右边界
            if (check(nums, mid, m)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool check(vector<int>& nums, int x, int m) {
        long long sum = 0;
        int cnt = 1;
        for (int i = 0; i < nums.size(); i += 1) {
            if (sum + nums[i] > x) {
                cnt += 1;
                sum = nums[i];
            } else {
                sum += nums[i];
            }
        }

        return cnt <= m;
    }
};
// @lc code=end
