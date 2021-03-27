/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132模式
 */
#include <cmath>
#include <stack>
#include <vector>

using namespace std;

// @lc code=start

// 101/101 cases passed (16 ms)
// Your runtime beats 69.77 % of cpp submissions
// Your memory usage beats 53.25 % of cpp submissions (13.4 MB)
class Solution_1 {
   public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> candidate_k;
        int max_k = INT_MIN;

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < max_k) {
                return true;
            }
            while (!candidate_k.empty() && nums[i] > candidate_k.top()) {
                max_k = candidate_k.top();
                candidate_k.pop();
            }
            candidate_k.push(nums[i]);
        }
        return false;
    }
};

// @lc code=end