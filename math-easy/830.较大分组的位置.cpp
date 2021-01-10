/*
 * @lc app=leetcode.cn id=830 lang=cpp
 *
 * [830] 较大分组的位置
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    // 202/202 cases passed (0 ms)
    // Your runtime beats 100 % of cpp submissions
    // Your memory usage beats 76.09 % of cpp submissions (7.6 MB)

    // 202/202 cases passed (8 ms)
    // Your runtime beats 44.35 % of cpp submissions
    // Your memory usage beats 81.32 % of cpp submissions (7.5 MB)
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> result;
        for (int l = 0, r = 0; r < s.size(); l = r) {
            while (r < s.size() && s[l] == s[r])
                ++r;
            if (r - l >= 3)
                result.push_back({l, r - 1});
        }
        return result;
    }
};

// @lc code=end

class Solution_0 {
   public:
    // 202/202 cases passed (4 ms)
    // Your runtime beats 87.43 % of cpp submissions
    // Your memory usage beats 46.75 % of cpp submissions (7.6 MB)
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> result;
        int n = s.size();
        int num = 1;
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || s[i] != s[i + 1]) {
                if (num >= 3) {
                    result.push_back({i - num + 1, i});
                }
                num = 1;
            } else {
                num++;
            }
        }
        return result;
    }
};

class Solution_1 {
   public:
    // 202/202 cases passed (4 ms)
    // Your runtime beats 87.43 % of cpp submissions
    // Your memory usage beats 63.88 % of cpp submissions (7.6 MB)
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        int left = 0, right = 1;
        while (right < s.length()) {
            // * `string`访问越界了，这个方法c++能过测试，但java过不了
            while (s[left] == s[right]) {
                right++;
            }
            if (right - left >= 3) {
                res.push_back({left, right - 1});
            }
            left = right;
            right++;
        }
        return res;
    }
};