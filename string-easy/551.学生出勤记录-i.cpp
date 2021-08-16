/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 */

#include <string>

using namespace std;

// @lc code=start

// 作者：klaxxi
// 链接：https://leetcode-cn.com/problems/student-attendance-record-i/solution/cpp-yi-xing-by-klaxi-3/
class Solution {
   public:
    bool checkRecord(string s) { return s.find('A', s.find('A') + 1) == -1 && s.find("LLL") == -1; }
};

// @lc code=end
