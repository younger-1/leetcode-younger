/*
 * @lc app=leetcode.cn id=1736 lang=cpp
 *
 * [1736] 替换隐藏数字得到的最晚时间
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
   public:
    string maximumTime(string time) {
        for (int i = 0; i < 5; i++) {
            if (time[i] != '?') {
                continue;
            }
            if (i == 0) {
                if (time[1] - '0' > 3 && time[1] - '0' <= 9) {
                    time[0] = '1';
                } else {
                    time[0] = '2';
                }
            }
            if (i == 1) {
                if (time[0] == '2') {
                    time[1] = '3';
                } else {
                    time[1] = '9';
                }
            }
            if (i == 3) {
                time[3] = '5';
            }
            if (i == 4) {
                time[4] = '9';
            }
        }
        return time;
    }
};
// @lc code=end
