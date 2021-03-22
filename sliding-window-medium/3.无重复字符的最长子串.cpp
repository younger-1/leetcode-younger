/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start

// 987/987 cases passed (20 ms)
// Your runtime beats 68.37 % of cpp submissions
// Your memory usage beats 66.32 % of cpp submissions (8.1 MB)
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int left = 0, right = 0;
        int res = 0;
        while (right < s.length()) {
            char c = s[right];
            right += 1;
            window[c] += 1;

            // nice
            while (window[c] > 1) {
                char d = s[left];
                left += 1;
                window[d] -= 1;
            }

            res = max(res, right - left);
        }
        return res;
    }

    int lengthOfLongestSubstring_2(string s) {
        unordered_map<char, int> window;
        int len = 0;
        int n = s.size();
        int l = 0, r = 0;
        while (r < n) {
            char c = s[r];
            if (window.find(c) != window.end()) {
                char d = s[l];
                window[d]--;
                if (window[d] == 0)
                    window.erase(d);
                l++;
            }
            window[c]++;
            r++;
        }
        return r - l;
    }
};
// @lc code=end

#include <iostream>
int main() {
    Solution s = Solution();
    cout << s.lengthOfLongestSubstring("bbbbb");
}