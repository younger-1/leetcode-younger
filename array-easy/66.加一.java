/*
 * @lc app=leetcode.cn id=66 lang=java
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
    // 111/111 cases passed (0 ms)
    // Your runtime beats 100 % of java submissions
    // Your memory usage beats 23.76 % of java submissions (37.1 MB)
    public int[] plusOne(int[] digits) {
        for (int i = digits.length - 1; i >= 0; i--) {
            digits[i] += 1;
            digits[i] %= 10;
            if (digits[i] != 0) {
                return digits;
            }
        }
        // If digits is all 9:
        digits = new int[digits.length + 1];
        digits[0] = 1;
        return digits;
    }
}
// @lc code=end

