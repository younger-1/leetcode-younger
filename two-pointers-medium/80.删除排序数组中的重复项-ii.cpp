/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        /*
Testcase
[1]
Answer
[1,0]
         */
        if (n <= 2) {
            return n;
        }

        int i = 2, j = 2;
        while (j < n) {
            if (nums[i - 2] != nums[j]) {
                nums[i] = nums[j];
                i += 1;
            }
            j += 1;
        }
        return i;
    }
};
// @lc code=end
