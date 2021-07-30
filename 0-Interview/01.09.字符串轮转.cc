// 面试题 01.09. 字符串轮转
// https://leetcode-cn.com/problems/string-rotation-lcci/

#include <string>

using namespace std;

// case: ["SzXSvSzi" "SvSziSzX"], ["ab", "ba"]
class Solution {
   public:
    bool isFlipedString(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if (n != m) {
            return false;
        } else if (n == 0) {
            return true;
        }
        int i, j, k = 0;
        while (k < n) {
            i = 0;
            while (s1[i] != s2[k]) {
                k++;
                if (k == n) {
                    return false;
                }
            }
            j = k++;
            while (i < n) {
                if (s1[i] != s2[j]) {
                    break;
                }
                i++;
                j = (j + 1) % n;
            }
            if (i == n) {
                return true;
            }
        }
        return false;
    }
};

class Solution_1 {
   public:
    bool isFlipedString(string s1, string s2) { return s1.size() == s2.size() && (s2 + s2).find(s1) != string::npos; }
};
