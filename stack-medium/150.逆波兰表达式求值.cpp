/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

#include <stack>
#include <string>
#include <vector>

using namespace std;

// @lc code=start

// 执行用时： 8 ms , 在所有 C++ 提交中击败了 95.72% 的用户
// 内存消耗： 11.7 MB , 在所有 C++ 提交中击败了 12.55% 的用户
class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto token : tokens) {
            if (token == "+") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a + b);
            } else if (token == "-") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b - a);
            } else if (token == "*") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a * b);
            } else if (token == "/") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b / a);
            } else {
                int x = stoi(token);
                s.push(x);
            }
        }
        return s.top();
    }
};
// @lc code=end
