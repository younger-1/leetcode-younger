// 剑指 Offer 19. 正则表达式匹配
// https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/

#include <string>

using namespace std;

class Solution {
   public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        if (n == 0 && m == 0) {
            return true;
        }
        if (n != 0 && m == 0) {
            return false;
        }
        int i = 0, idx = 0;
        if (n == 0) {
            while (idx < m) {
                int state = get_state(p, idx);
                if (state != 0) {
                    return false;
                }
                idx += 2;
            }
        }
        int skip = 0;
        while (i < n && idx < m) {
            int state = get_state(p, idx);
            if (p[idx] == s[i] || p[idx] == '.') {
                i++;
                idx += state;
                skip = (state == 0) ? skip + 1 : 0;
                continue;
            } else if (state == 0) {
                idx += 2;
                continue;
            }
            if (skip && p[idx] == s[i - 1]) {
                idx += 1;
                continue;
            }
            return false;
        }

        while (idx < m) {
            int state = get_state(p, idx);
            if (state == 0) {
                idx += 2;
            } else if (p[idx] == s[i - 1] && skip) {
                idx += 1;
            } else if (p[idx] == '.' && skip) {
                idx += 1;
                skip -= 1;
            } else {
                return false;
            }
        }

        return i == n && idx == m;
    }

   private:
    int get_state(string& s, int idx) {
        if (idx == s.length() - 1) {
            return 1;
        }
        return s[idx + 1] == '*' ? 0 : 1;
    }
};

#include <iostream>
int main() {
    Solution sol = Solution();
    // string s = "ab", p = "c*a*b*";
    // string s = "aaa", p = "a*a";
    // string s = "aaa", p = "ab*a*c*a";
    // string s = "aaa", p = "aaaa";
    // string s = "a", p = "ab*a";
    // string s = "a", p = ".*..a*";
    // string s = "bbbba", p = ".*a*a";
    // string s = "bbbbab", p = ".*a*a";
    // string s = "ab", p = ".*";
    // string s = "ab", p = ".*..";
    // string s = "", p = ".*a";
    // string s = "", p = ".*";
    string s = "asdfasdfasdfas", p = ".*asdf.*asdf.*asdf.*s";

    cout << sol.isMatch(s, p);
}
