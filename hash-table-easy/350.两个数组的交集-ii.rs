/*
 * @lc app=leetcode.cn id=350 lang=rust
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
impl Solution {
    // 61/61 cases passed (0 ms)
    // Your runtime beats 100 % of rust submissions
    // Your memory usage beats 38.46 % of rust submissions (2.1 MB)
    pub fn intersect(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        use std::collections::HashMap;
        let mut count_map = HashMap::new();
        for i in nums1.iter() {
            let count = count_map.entry(i).or_insert(0);
            *count += 1
        }
        let mut res = vec![];
        for i in nums2.iter() {
            if let Some(count) = count_map.get_mut(i) {
                if *count == 0 {
                    continue;
                }
                *count -= 1;
                res.push(*i);
            }
        }
        res
    }
}
// @lc code=end
