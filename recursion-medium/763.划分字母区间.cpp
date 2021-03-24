/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */
#include <string>
#include <vector>

using namespace std;

// @lc code=start

// 116/116 cases passed (4 ms)
// Your runtime beats 70.86 % of cpp submissions
// Your memory usage beats 91.31 % of cpp submissions (6.4 MB)
class Solution {
   public:
    vector<int> partitionLabels(string S) {
        int n = S.size();
        int lastIndex[26];
        for (int i = 0; i < n; i++) {
            lastIndex[S[i] - 'a'] = i;
        }
        vector<int> res;
        int start = 0, end = 0;
        for (int i = 0; i < n; i++) {
            end = max(end, lastIndex[S[i] - 'a']);
            if (i == end) {
                res.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return res;
    }
};
// @lc code=end
