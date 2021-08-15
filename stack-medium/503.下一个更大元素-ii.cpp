/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

#include <stack>
#include <vector>

using namespace std;

// @lc code=start

// Wrong
class Solution {
   public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> s;
        // 从后往前
        for (int i = n - 1; i >= 0; i--) {
            // 单调递减栈
            while (!s.empty() && nums[i] >= s.top()) {
                s.pop();
            }
            res[i] = s.empty() ? -1 : s.top();
            s.push(nums[i]);
        }
        return res;
    }
};

// @lc code=end

// TODO: redo
// @monotonic-stack
// 224/224 cases passed (44 ms)
// Your runtime beats 58.49 % of cpp submissions
// Your memory usage beats 68.14 % of cpp submissions (22.4 MB)
class Solution_1 {
   public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> s;
        for (int i = 0; i < 2 * n - 1; i++) {
            while (!s.empty() && nums[s.top()] < nums[i % n]) {
                res[s.top()] = nums[i % n];
                s.pop();
            }
            s.push(i % n);
        }
        return res;
    }
};

#include <iostream>

int main() {
    auto s = Solution_1();
    // vector<int> nums{1, 2, 1};
    // vector<int> nums{5, 3, 4};
    vector<int> nums{3, -2, -1};
    auto ans = s.nextGreaterElements(nums);
    for (int i : ans) {
        cout << i << " ";
    }
}
