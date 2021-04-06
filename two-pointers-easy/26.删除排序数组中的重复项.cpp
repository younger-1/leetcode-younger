/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */
#include <vector>

using namespace std;

// @lc code=start

// 161/161 cases passed (4 ms)
// Your runtime beats 99.03 % of cpp submissions
// Your memory usage beats 56.12 % of cpp submissions (13.3 MB)
class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return n;
        int slow = 1, fast = 1;
        while (fast < n) {
            if (nums[slow - 1] != nums[fast]) {
                nums[slow] = nums[fast];
                slow += 1;
            }
            fast += 1;
        }
        return slow;
    }
};
// @lc code=end

class Solution_1 {
   public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return n;
        int slow = 0;
        for (int fast = 1; fast < n; fast++) {
            if (nums[slow] != nums[fast]) {
                nums[++slow] = nums[fast];
            }
        }
        return slow + 1;
    }
};
