/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

#include <vector>

using namespace std;

// @lc code=start

/*
 * 我们考虑数组中的最后一个元素 x：在最小值右侧的元素，它们的值一定都小于等于 x；
 * 而在最小值左侧的元素，它们的值一定都大于等于 x
 */
class Solution {
   public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] < nums[r]) {
                r = m;
            } else if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                // 只忽略二分查找区间的右端点
                r -= 1;
            }
        }
        return nums[l];
    }
};
// @lc code=end
