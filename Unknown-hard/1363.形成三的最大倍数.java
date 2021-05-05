/*
 * @lc app=leetcode.cn id=1363 lang=java
 *
 * [1363] 形成三的最大倍数
 */

// @lc code=start

// @fail
class Solution {
    public String largestMultipleOfThree(int[] digits) {
        Arrays.sort(digits);
        StringBuilder sb = new StringBuilder(digits.length);
        for (int i = 0; i < digits.length; i++) {
            sb.insert(0, i);
        }
        String nextMax = sb.toString();
        while (nextMax.length() > 0) {
            nextMax = getNextMax(nextMax);
            if (threeMultiple(nextMax)) {
                return nextMax;
            }
        }
        return "";
    }

    boolean threeMultiple(String s) {
        int sum = 0;
        for (var ch : s) {
            sum += ch - '0';
        }
        return sum % 3 == 0;
    }
}
// @lc code=end

