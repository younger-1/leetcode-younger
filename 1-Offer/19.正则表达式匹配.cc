// 剑指 Offer 19. 正则表达式匹配
// https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/

#include <string>
#include <vector>

using namespace std;

// Wrong
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

// TODO: redo
// @recursion
class Solution_1 {
   public:
    bool isMatch(string s, string p) {
        if (p.empty())
            return s.empty();
        bool first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');
        if (p.size() >= 2 && p[1] == '*')
            // *前字符重复>=1次 || *前字符重复0次（不出现）
            return (first_match && isMatch(s.substr(1), p)) || isMatch(s, p.substr(2));
        else
            return first_match && isMatch(s.substr(1), p.substr(1));
    }
};

// @DP
// https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/solution/zheng-ze-biao-da-shi-pi-pei-by-leetcode-s3jgn/
class Solution_2 {
   public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j - 1)) {
                        f[i][j] |= f[i - 1][j];
                    }
                } else {
                    if (matches(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }
};

#include <iostream>
int main() {
    auto sol = Solution_1();
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
