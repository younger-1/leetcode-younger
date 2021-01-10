/*
 * @lc app=leetcode.cn id=830 lang=rust
 *
 * [830] 较大分组的位置
 */

// @lc code=start
impl Solution {
    // 202/202 cases passed (0 ms)
    // Your runtime beats 100 % of rust submissions
    // Your memory usage beats 74.32 % of rust submissions (2 MB)
    pub fn large_group_positions(s: String) -> Vec<Vec<i32>> {
        let s = s.into_bytes();
        let mut res = vec![];
        let (mut left, mut right) = (0, 0);
        while right < s.len() {
            while right < s.len() && s[left] == s[right] {
                right += 1;
            }
            if left + 3 <= right {
                res.push(vec![left as i32, right as i32 - 1]);
            }
            left = right;
        }
        res
    }
}
// @lc code=end

impl Solution_0 {
    // 202/202 cases passed (0 ms)
    // Your runtime beats 100 % of rust submissions
    // Your memory usage beats 94.59 % of rust submissions (1.9 MB)
    pub fn large_group_positions(s: String) -> Vec<Vec<i32>> {
        (1..=s.len())
            .fold((vec![], 0usize), |(mut acc, pre), i| {
                if i == s.len() || s.as_bytes()[i] != s.as_bytes()[i - 1] {
                    if i - pre >= 3 {
                        acc.push(vec![pre as i32, i as i32 - 1])
                    }
                    (acc, i)
                } else {
                    (acc, pre)
                }
            })
            .0
    }
}
