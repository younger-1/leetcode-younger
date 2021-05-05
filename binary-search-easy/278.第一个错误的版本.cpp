/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// 0 ms 5.9 MB
class Solution {
   public:
    int firstBadVersion(int n) {
        int low = 0;
        int high = n;
        if (n == 1)
            return 1;
        while (low < high - 1) {
            int middle = low + (high - low) / 2;
            if (isBadVersion(middle)) {
                high = middle;
            } else {
                low = middle;
            }
        }
        return high;
    }
};
// @lc code=end
