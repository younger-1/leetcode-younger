/*
 * @lc app=leetcode.cn id=136 lang=rust
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
impl Solution {
    // 61/61 cases passed (4 ms)
    // Your runtime beats 43.84 % of rust submissions
    // Your memory usage beats 27.78 % of rust submissions (2.3 MB)
    pub fn single_number(nums: Vec<i32>) -> i32 {
        use std::collections::HashSet;
        let mut set = HashSet::new();
        nums.iter().for_each(|&x| {
            if !set.insert(x) {
                set.remove(&x);
            }
        });
        *set.iter().next().unwrap()
    }
}
// @lc code=end

impl Solution_0 {
    // 61/61 cases passed (0 ms)
    // Your runtime beats 100 % of rust submissions
    // Your memory usage beats 65.15 % of rust submissions (2.2 MB)
    pub fn single_number(nums: Vec<i32>) -> i32 {
        nums.iter().fold(0, |acc, x| acc ^ x)
    }
}
