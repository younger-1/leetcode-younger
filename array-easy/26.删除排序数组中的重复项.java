/*
 * @lc app=leetcode.cn id=26 lang=java
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start

// 单指针
class Solution {
    // 161/161 cases passed (1 ms)
    // Your runtime beats 80.06 % of java submissions
    // Your memory usage beats 55.6 % of java submissions (40.3 MB)
    public int removeDuplicates(int[] nums) {
        int cur = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] != nums[i + 1]) {
                cur += 1;
                nums[cur] = nums[i + 1];
            }
        }
        return cur + 1;
    }
}
// @lc code=end

