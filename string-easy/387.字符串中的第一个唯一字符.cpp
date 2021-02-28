/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */
#include <string>

using namespace std;

// @lc code=start
class Solution {
   public:
    // 104/104 cases passed (16 ms)
    // Your runtime beats 99.38 % of cpp submissions
    // Your memory usage beats 94.78 % of cpp submissions (10.4 MB)
    int firstUniqChar(string s) {
        int count[26]{0};
        int n = s.size();
        for (int i = 0; i != n; i++) {
            count[s[i] - 'a']++;
        }
        for (int i = 0; i != n; i++) {
            if (count[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end
