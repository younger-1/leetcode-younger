/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */
#include <string>

using namespace std;

// @lc code=start
class Solution {
   public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        while (i < version1.size() || j < version2.size()) {
            int a = 0, b = 0;
            while (i < version1.size() && version1[i] != '.')
                a = a * 10 + version1[i++] - '0';
            while (j < version2.size() && version2[j] != '.')
                b = b * 10 + version2[j++] - '0';
            if (a > b)
                return 1;
            else if (a < b)
                return -1;
            // 跳过点号
            i++;
            j++;
        }
        return 0;
    }
};

// @lc code=end
