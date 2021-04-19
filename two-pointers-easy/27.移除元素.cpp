/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include <vector>

using namespace std;

// @lc code=start

// 113/113 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 84.14 % of cpp submissions (8.4 MB)
class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int left = 0, right = 0;
        while (right < n) {
            if (nums[right] != val) {
                nums[left] = nums[right];
                left += 1;
            }
            right += 1;
        }
        return left;
    }
};
// @lc code=end
