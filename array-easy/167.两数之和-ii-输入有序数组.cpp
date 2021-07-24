/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int s = numbers[l] + numbers[r];
            if (s < target) {
                l++;
            } else if (s > target) {
                r--;
            } else {
                return {l + 1, r + 1};
            }
        }
        return {};
    }
};
// @lc code=end
