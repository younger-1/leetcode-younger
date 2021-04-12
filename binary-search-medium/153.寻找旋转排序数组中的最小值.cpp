/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

#include <vector>

using namespace std;

// @lc code=start

// 150/150 cases passed (8 ms)
// Your runtime beats 28.31 % of cpp submissions
// Your memory usage beats 95.46 % of cpp submissions (9.8 MB)
class Solution {
   public:
    int findMin(vector<int>& nums) {
        /*
        1 2 3 4 5
        2 3 4 5 1
        5 1 2 3 4
         */
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] < nums[r]) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return nums[l];
    }
};
// @lc code=end
