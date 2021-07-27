/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

#include <stack>
#include <vector>

using namespace std;

// @lc code=start

// TODO: redo
// 38/38 cases passed (64 ms)
// Your runtime beats 86.36 % of cpp submissions
// Your memory usage beats 62.8 % of cpp submissions (38.8 MB)
class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n, 0);
        stack<int> s;

        for (int i = 0; i < n; i++) {
            // 单调递减栈
            while (!s.empty() && T[s.top()] < T[i]) {
                res[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};
// @lc code=end
