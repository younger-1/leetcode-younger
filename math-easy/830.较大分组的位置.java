/*
 * @lc app=leetcode.cn id=830 lang=java
 *
 * [830] 较大分组的位置
 */

// @lc code=start

// @lc code=end

// 202/202 cases passed (2 ms)
// Your runtime beats 47.08 % of java submissions
// Your memory usage beats 95.69 % of java submissions (38.3 MB)
class Solution_0 {
    public List<List<Integer>> largeGroupPositions(String s) {
        List<List<Integer>> res = new ArrayList<>();
        int left = 0, right = 0;
        while (right <= s.length()) {
            if (right != s.length() && s.charAt(left) == s.charAt(right)) {
                right++;
            } else {
                if (right - left >= 3) {
                    res.add(List.of(left, right - 1));
                }
                left = right;
                // 避免 right 等于 length 时陷入死循环
                right++;
            }
        }
        return res;
    }
}


// 202/202 cases passed (2 ms)
// Your runtime beats 47.08 % of java submissions
// Your memory usage beats 93.88 % of java submissions (38.3 MB)
class Solution_1 {
    public List<List<Integer>> largeGroupPositions(String s) {
        List<List<Integer>> res = new ArrayList<>();
        for (int left = 0, right = 0; right <= s.length(); right++) {
            if (right == s.length() || s.charAt(left) != s.charAt(right)) {
                if (right - left >= 3) {
                    res.add(List.of(left, right - 1));
                }
                left = right;
            }
        }
        return res;
    }
}