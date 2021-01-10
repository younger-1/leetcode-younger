/*
 * @lc app=leetcode.cn id=1 lang=rust
 *
 * [1] 两数之和
 */

// @lc code=start
impl Solution {
    // 52/52 cases passed (0 ms)
    // Your runtime beats 100 % of rust submissions
    // Your memory usage beats 79.6 % of rust submissions (2 MB)

    /// ```
    /// use leetcode::0001_two_numbers::Solution;
    ///
    /// assert_eq!(Solution::two_sum(vec![2, 7, 11 ,15], 9), vec![0, 1]);
    /// ```
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        use std::collections::HashMap;

        let mut table = HashMap::new();
        for (i, &num) in nums.iter().enumerate() {
            if let Some(&position) = table.get(&(target - nums[i])) {
                return vec![position as i32, i as i32];
            }
            table.insert(num, i);
        }
        vec![]
    }
}
// @lc code=end
