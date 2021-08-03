/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int i = 0, j = n - 1;
        bool goon = true;
        while (goon && i < j) {
            goon = false;
            if (sorted[i] == nums[i]) {
                i++;
                goon = true;
            }
            if (sorted[j] == nums[j]) {
                j--;
                goon = true;
            }
        }
        return j == i ? 0 : j - i + 1;
    }
};
// @lc code=end

// TODO: redo
// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/solution/zui-duan-wu-xu-lian-xu-zi-shu-zu-by-leet-yhlf/
class Solution_1 {
   public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxn = INT_MIN, right = -1;
        int minn = INT_MAX, left = -1;
        for (int i = 0; i < n; i++) {
            if (maxn > nums[i]) {
                right = i;
            } else {
                maxn = nums[i];
            }
            if (minn < nums[n - i - 1]) {
                left = n - i - 1;
            } else {
                minn = nums[n - i - 1];
            }
        }
        return right == -1 ? 0 : right - left + 1;
    }
};

// https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/comments/76131
class Solution_11 {
   public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return 0;
        }
        int high = 0, low = n - 1;
        int max = nums[0], min = nums[n - 1];
        for (int i = 0; i < n; i++) {
            max = Max(max, nums[i]);
            min = Min(min, nums[n - i - 1]);
            if (nums[i] < max) {
                high = i;
            }
            if (nums[n - i - 1] > min) {
                low = n - i - 1;
            }
        }
        return high > low ? high - low + 1 : 0;
    }

   private:
    int Max(int a, int b) { return a > b ? a : b; }
    int Min(int a, int b) { return a < b ? a : b; }
};
