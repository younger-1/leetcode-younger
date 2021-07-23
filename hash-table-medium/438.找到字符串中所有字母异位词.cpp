/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
// 36/36 cases passed (20 ms)
// Your runtime beats 62.58 % of cpp submissions
// Your memory usage beats 85.79 % of cpp submissions (8.3 MB)
class Solution {
   public:
    vector<int> findAnagrams(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t) {
            need[c] += 1;
        }
        int left = 0, right = 0;
        int valid = 0;
        vector<int> res;
        while (right < s.length()) {
            char c = s[right];
            right += 1;
            if (need.count(c)) {
                window[c] += 1;
                if (need[c] == window[c]) {
                    valid += 1;
                }
            }
            while (valid == need.size()) {
                if (right - left == t.length()) {
                    res.push_back(left);
                }
                char d = s[left];
                left += 1;
                if (need.count(d)) {
                    if (need[d] == window[d]) {
                        valid -= 1;
                    }
                    window[d] -= 1;
                }
            }
        }

        return res;
    }
};

// @lc code=end

class Solution_1 {
   public:
    vector<int> findAnagrams(string s, string t) {
        unordered_map<char, int> need, window;
        int start = 0, minlen = INT_MAX, match = 0;
        for (auto c : t) {
            need[c] += 1;
        }
        int left = 0, right = 0;
        int n = s.size(), m = t.size();
        vector<int> res;

        while (right < n) {
            if (window[s[right]] < need[s[right]]) {
                match++;
            }
            window[s[right]]++;
            right++;

            while (match == m) {
                if (right - left == t.length()) {
                    res.push_back(left);
                }
                if (window[s[left]] <= need[s[left]]) {
                    match--;
                }
                window[s[left]]--;
                left++;
            }
        }
        return res;
    }
};

#include <iostream>
int main() {
    auto s = Solution_1();
    string a = "cadbac", b = "abc";
    auto res = s.findAnagrams(a, b);
    for (auto n : res) {
        cout << n << " ";
    }
}
