/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

#include <stack>
#include <string>

using namespace std;

// @lc code=start

// 39/39 cases passed (4 ms)
// Your runtime beats 99.53 % of cpp submissions
// Your memory usage beats 75.27 % of cpp submissions (7.8 MB)
class Solution {
   public:
    int calculate(string s) {
        stack<int> ops;
        ops.push(1);
        int sign = 1;

        int ret = 0;
        int n = s.length();
        int i = 0;
        while (i < n) {
            if (s[i] == ' ') {
                i += 1;
            } else if (s[i] == '+') {
                sign = ops.top();
                i += 1;
            } else if (s[i] == '-') {
                sign = -ops.top();
                i += 1;
            } else if (s[i] == '(') {
                ops.push(sign);
                i += 1;
            } else if (s[i] == ')') {
                ops.pop();
                i += 1;
            } else {
                long num = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + s[i] - '0';
                    i += 1;
                }
                ret += sign * num;
            }
        }
        return ret;
    }
};
// @lc code=end
