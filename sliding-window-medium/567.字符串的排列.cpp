/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start

// 103/103 cases passed (28 ms)
// Your runtime beats 18.4 % of cpp submissions
// Your memory usage beats 22.8 % of cpp submissions (7.4 MB)
class Solution {
   public:
    bool checkInclusion(string t, string s) {
        unordered_map<char, int> need, window;
        for (char c : t) {
            need[c] += 1;
        }
        int left = 0, right = 0, valid = 0;
        while (right < s.length()) {
            char c = s[right];
            right += 1;
            if (need.find(c) != need.end()) {
                window[c] += 1;
                if (window[c] == need[c]) {
                    valid += 1;
                }
            }

            while (right - left >= t.length()) {
                if (valid == need.size()) {
                    return true;
                }
                char d = s[left];
                left += 1;
                if (need.find(d) != need.end()) {
                    if (window[d] == need[d]) {
                        valid -= 1;
                    }
                    window[d] -= 1;
                }
            }
        }
        return false;
    }
};
// @lc code=end
