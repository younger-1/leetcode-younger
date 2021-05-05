/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

#include <vector>

using namespace std;

// @lc code=start

// 96/96 cases passed (116 ms)
// Your runtime beats 61.23 % of cpp submissions
// Your memory usage beats 31.71 % of cpp submissions (63.3 MB)
class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        vector<int> st;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.back()] > heights[i]) {
                int cur = st.back();
                st.pop_back();
                int left = st.back();
                int right = i - 1;
                ans = max(ans, (right - left) * heights[cur]);
            }
            st.push_back(i);
        }
        return ans;
    }
};
// @lc code=end

#include <stack>
class Solution_1 {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);

        stack<int> mono_stack;
        for (int i = 0; i < n; ++i) {
            while (!mono_stack.empty() &&
                   heights[mono_stack.top()] >= heights[i]) {
                mono_stack.pop();
            }
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
            mono_stack.push(i);
        }

        mono_stack = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!mono_stack.empty() &&
                   heights[mono_stack.top()] >= heights[i]) {
                mono_stack.pop();
            }
            right[i] = (mono_stack.empty() ? n : mono_stack.top());
            mono_stack.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};