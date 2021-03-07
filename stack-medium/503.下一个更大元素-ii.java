/*
 * @lc app=leetcode.cn id=503 lang=java
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start

// 224/224 cases passed (7 ms)
// Your runtime beats 92.45 % of java submissions
// Your memory usage beats 39.06 % of java submissions (40.3 MB)
class Solution {
    /* 单调栈 Monotonic stack */
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        Arrays.fill(res, -1);
        // Java's stack: peek, pop, push. They all operate on the first element of the inner deque
        Deque<Integer> stack = new LinkedList<>();
        for (int i = 0; i < 2 * n; i++) {
            while (!stack.isEmpty() && nums[stack.peek()] < nums[i % n]) {
                res[stack.pop()] = nums[i % n];
            }
            stack.push(i % n);
        }
        return res;
    }
}
// @lc code=end

