/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

#include <stack>
#include <vector>

using namespace std;

// @lc code=start

// @lc code=end

// O(n^2)
// https://leetcode-cn.com/problems/0ynMMM/comments/1074690
// https://leetcode-cn.com/problems/0ynMMM/solution/xiang-xi-shuo-shuo-ru-he-cong-bao-li-fa-gusww/
// 执行用时：100 ms, 在所有 C++ 提交中击败了84.31% 的用户
// 内存消耗：59.9 MB, 在所有 C++ 提交中击败了96.08% 的用户
class Solution_1 {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (heights[i] * n <= ans) {
                continue;
            }
            int left = i, right = i;
            while (left >= 1 && heights[left - 1] >= heights[i]) {
                left--;
            }
            while (right <= n - 2 && heights[right + 1] >= heights[i]) {
                right++;
            }
            ans = max(ans, heights[i] * (right - left + 1));
        }

        return ans;
    }
};

// @monotonic-stack
class Solution_2 {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);

        stack<int> mono_stack;
        for (int i = 0; i < n; ++i) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                mono_stack.pop();
            }
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
            mono_stack.push(i);
        }

        mono_stack = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
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

// TODO: redo
// @monotonic-stack
// https://www.geeksforgeeks.org/largest-rectangle-under-histogram/
// 执行用时：88 ms, 在所有 C++ 提交中击败了94.12% 的用户
// 内存消耗：61.9 MB, 在所有 C++ 提交中击败了68.63% 的用户
class Solution_3 {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        stack<int> s;
        // 2 8 6 5 2
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[i] < heights[s.top()]) {
                int tp = s.top();
                s.pop();
                // 'i' is 'right index' for the top and element
                // before top in stack is 'left index'
                int right = i, left = s.empty() ? 0 : s.top() + 1;
                ans = max(ans, heights[tp] * (right - left));
            }
            s.push(i);
        }
        while (!s.empty()) {
            int tp = s.top();
            s.pop();
            ans = max(ans, heights[tp] * (s.empty() ? n : (n - s.top() - 1)));
        }
        return ans;
    }
};

// TODO: redo
// @monotonic-stack
// https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/84-by-ikaruga/
// https://leetcode-cn.com/problems/largest-rectangle-in-histogram/comments/419232
class Solution_4 {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        vector<int> st;
        // 让栈底至少存在一个元素
        heights.insert(heights.begin(), 0);
        // 让所有元素出栈
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.back()] > heights[i]) {
                int cur = st.back();
                st.pop_back();
                int left = st.back() + 1;
                int right = i;
                ans = max(ans, (right - left) * heights[cur]);
            }
            st.push_back(i);
        }
        return ans;
    }
};
