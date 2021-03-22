/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */
#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start

// 21/21 cases passed (32 ms)
// Your runtime beats 87.95 % of cpp submissions
// Your memory usage beats 99.15 % of cpp submissions (16.9 MB)
class Solution {
   public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0;
        int j = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                i += 1;
            }
            j += 1;
        }
        return i;
    }
};
// @lc code=end
