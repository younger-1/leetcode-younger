/*
 * @lc app=leetcode.cn id=1221 lang=cpp
 *
 * [1221] 分割平衡字符串
 */
#include <string>

using namespace std;

// @lc code=start
class Solution {
   public:
    int balancedStringSplit(string s) {
        int ans = 0, L = 0, R = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') {
                L += 1;
            } else {
                R += 1;
            }
            ans += (L == R);
        }
        return ans;
    }
};

// @lc code=end

class Solution_1 {
   public:
    int balancedStringSplit(string s) {
        int ans = 0, d = 0;
        for (char& ch : s) {
            ch == 'L' ? ++d : --d;
            if (d == 0) {
                ++ans;
            }
        }
        return ans;
    }
};
