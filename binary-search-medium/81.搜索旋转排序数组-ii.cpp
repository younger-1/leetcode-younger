/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */
#include <vector>

using namespace std;

// @lc code=start

// 279/279 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 12.57 % of cpp submissions (13.7 MB)
class Solution {
   public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return false;
        }
        int start = 0;
        int end = n - 1;
        int mid;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return true;
            }
            // 10111 和 1110111101 这种。此种情况下 nums[start] == nums[mid]，
            // 分不清到底是前面有序还是后面有序，此时 start++ 即可
            if (nums[start] == nums[mid]) {
                start++;
                continue;
            }
            //前半部分有序
            if (nums[start] < nums[mid]) {
                // target在前半部分
                if (nums[mid] > target && nums[start] <= target) {
                    end = mid - 1;
                } else {  //否则，去后半部分找
                    start = mid + 1;
                }
            } else {
                //后半部分有序
                // target在后半部分
                if (nums[mid] < target && nums[end] >= target) {
                    start = mid + 1;
                } else {  //否则，去后半部分找
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};

// @lc code=end
