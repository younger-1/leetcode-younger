// 面试题 01.06. 字符串压缩
// https://leetcode-cn.com/problems/compress-string-lcci/

#include <string>

using namespace std;

class Solution {
   public:
    string compressString(string S) {
        string ans;
        int n = S.length();
        int i = 0, j = 0;
        while (j < n) {
            if (S[i] == S[j]) {
                j++;
                continue;
            }
            ans += S[i] + to_string(j - i);
            i = j;
        }
        ans += S[i] + to_string(j - i);
        return (ans.length() < S.length()) ? ans : S;
    }
};
