/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */

#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start

// TODO: redo
class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> preSum{{0, 1}};
        int sum = 0, res = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            res += preSum[sum - k];
            preSum[sum]++;
        }
        return res;
    }
};
// @lc code=end
