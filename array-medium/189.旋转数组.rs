/*
 * @lc app=leetcode.cn id=189 lang=rust
 *
 * [189] 旋转数组
 */

// @lc code=start
impl Solution {
    // 执行用时： 0 ms , 在所有 Rust 提交中击败了 100.00% 的用户
    // 内存消耗： 2.1 MB , 在所有 Rust 提交中击败了 82.11% 的用户
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let k = k as usize % nums.len();
        nums.rotate_right(k);
    }
}
// @lc code=end
