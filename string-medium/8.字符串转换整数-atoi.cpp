/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
using namespace std;
#include <string>

// @lc code=start
class Solution {
   public:
    // 1082/1082 cases passed (8 ms)
    // Your runtime beats 34.19 % of cpp submissions
    // Your memory usage beats 75.62 % of cpp submissions (6.9 MB)
    int myAtoi(string str) {
        long res = 0;
        bool instr = false;
        int symbol = 1;
        for (int i = 0; i != str.size(); i++) {
            if (str[i] == ' ' && !instr) {
                continue;
            }
            if (str[i] == '-' && !instr) {
                symbol = -1;
                instr = true;
                continue;
            }
            if (str[i] == '+' && !instr) {
                instr = true;
                continue;
            }
            if (str[i] >= '0' && str[i] <= '9') {
                res = res * 10 + (str[i] - '0');
                instr = true;
                if (symbol * res > INT_MAX)
                    return INT_MAX;
                if (symbol * res < INT_MIN)
                    return INT_MIN;
                continue;
            }
            break;
        }
        return symbol * res;
    }
};
// @lc code=end
