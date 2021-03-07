/*
 * @lc app=leetcode.cn id=496 lang=java
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start

// 15/15 cases passed (5 ms)
// Your runtime beats 82.74 % of java submissions
// Your memory usage beats 19.53 % of java submissions (38.8 MB)
class Solution {
    /* 单调栈 Monotonic stack */
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Deque<Integer> stack = new LinkedList<Integer>();
        // 先对 nums2 中的每一个元素，求出其下一个更大的元素。将这一对值放入哈希映射（HashMap）中
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums2.length; i++) {
            while (!stack.isEmpty() && stack.peek() < nums2[i]) {
                map.put(stack.pop(), nums2[i]);
            }
            stack.push(nums2[i]);
        }
        while (!stack.isEmpty()) {
            map.put(stack.pop(), -1);
        }
        int[] res = new int[nums1.length];
        for (int i = 0; i < nums1.length; i++) {
            res[i] = map.get(nums1[i]);
        }
        return res;
    }
}

// @lc code=end
