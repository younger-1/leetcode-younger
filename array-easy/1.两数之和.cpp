/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    // 52/52 cases passed (4 ms)
    // Your runtime beats 99.77 % of cpp submissions
    // Your memory usage beats 49.69 % of cpp submissions (9.3 MB)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable;
        for (int i = 0; i < nums.size(); i++) {
            auto it = hashTable.find(target - nums[i]);
            if (hashTable.end() == it) {
                hashTable[nums[i]] = i;
            } else {
                return {it->second, i};
            }
        }
        return {};
    }
};
// @lc code=end
