/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

#include <string>

using namespace std;

// @lc code=start

// 79/79 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 80.94 % of cpp submissions (6.7 MB)
class Solution {
   public:
    // 暴力匹配，时间复杂度 O(MN)
    int strStr(string txt, string pat) {
        int M = pat.length();
        int N = txt.length();
        for (int i = 0; i <= N - M; i++) {
            int j = 0;
            for (; j < M; j++) {
                if (pat[j] != txt[i + j])
                    break;
            }
            // pat 全都匹配了
            if (j == M)
                return i;
        }
        // txt 中不存在 pat 子串
        return -1;
    }
};
// @lc code=end
