/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution_0 {
   public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j >= i + 1; j--) {
                if (nums[j] > nums[i]) {
                    swap(nums[j], nums[i]);
                    std::reverse(std::begin(nums) + i + 1, std::end(nums));
                    return;
                }
            }
        }
        std::reverse(std::begin(nums), std::end(nums));
    }
};
// @lc code=end

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-by-leetcode-solution/
class Solution_1 {
   public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
