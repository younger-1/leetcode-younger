/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

#include <string>

using namespace std;

// @lc code=start

// 98/98 cases passed (12 ms)
// Your runtime beats 95.08 % of cpp submissions
// Your memory usage beats 99.85 % of cpp submissions (8.8 MB)
class Solution {
   public:
    // 原地算法
    string removeDuplicates(string S) {
        int top = 0;
        for (char ch : S) {
            if (top == 0 || S[top - 1] != ch) {
                S[top] = ch;
                top += 1;
            } else {
                top -= 1;
            }
        }
        S.resize(top);
        return S;
    }
};
// @lc code=end
