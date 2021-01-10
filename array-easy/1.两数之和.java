/*
 * @lc app=leetcode.cn id=1 lang=java
 *
 * [1] 两数之和
 */


// @lc code=start
class Solution {
// 52/52 cases passed (0 ms)
// Your runtime beats 100 % of java submissions
// Your memory usage beats 60.46 % of java submissions (38.6 MB)
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> table = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++) {
            if(table.containsKey(target - nums[i])) {
                return new int[]{ table.get(target - nums[i]), i };
            }
            table.put(nums[i], i);
        }
        return null;
    }
}
// @lc code=end

