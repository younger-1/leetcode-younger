/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start

// 266/266 cases passed (32 ms)
// Your runtime beats 54.81 % of cpp submissions
// Your memory usage beats 80 % of cpp submissions (7.6 MB)
class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t) {
            need[c]++;
        }

        // 记录最小覆盖子串的起始索引及长度
        int start = 0, len = INT_MAX;
        int left = 0, right = 0;
        int valid = 0;
        while (right < s.size()) {
            char c = s[right];
            right += 1;
            // 进行窗口内数据的一系列更新
            if (need.find(c) != need.end()) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid += 1;
                }
            }

            while (valid == need.size()) {
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }

                char d = s[left];
                left += 1;
                // 进行窗口内数据的一系列更新
                if (need.find(d) != need.end()) {
                    if (window[d] == need[d]) {
                        valid -= 1;
                    }
                    window[d]--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
// @lc code=end
