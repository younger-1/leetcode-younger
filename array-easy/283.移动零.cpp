/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    // 21/21 cases passed (4 ms)
    // Your runtime beats 97.63 % of cpp submissions
    // Your memory usage beats 80.92 % of cpp submissions (8.8 MB)
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[left] = nums[i];
                left++;
            }
        }
        for (int i = left; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
// @lc code=end
