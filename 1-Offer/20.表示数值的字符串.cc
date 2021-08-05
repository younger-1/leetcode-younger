// 剑指 Offer 20. 表示数值的字符串
// https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/

#include <string>

using namespace std;

class Solution {
   public:
    bool isNumber(string s) {
        if (s.length() == 0) {
            return false;
        }
        auto [begin, end] = trim(s);
        s = s.substr(begin, end - begin);
        // '.': ok if appear once and before e/E
        // 'e': ok if appear once and after number
        // '+/-': ok if in begin or after e/E
        bool num_flag = false, dot_flag = false, e_flag = false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                num_flag = true;
            } else if (s[i] == '.' && !dot_flag && !e_flag) {
                dot_flag = true;
            } else if ((s[i] == 'e' || s[i] == 'E') && !e_flag && num_flag) {
                e_flag = true;
                // 为了避免 123e 为数字
                num_flag = false;
            } else if ((s[i] == '+' || s[i] == '-') && (i == 0 || (s[i - 1] == 'e' || s[i - 1] == 'E'))) {
            } else {
                return false;
            }
        }
        return num_flag;
    }

   private:
    pair<int, int> trim(string& s) {
        int n = s.length();
        int begin = 0;
        while (begin < n && s[begin] == ' ') {
            begin++;
        }
        // for (int i = 0; i < n; i++) {
        //     if (s[i] != ' ') {
        //         begin = i;
        //         break;
        //     }
        // }
        int end = n;
        while (end > 0 && s[end - 1] == ' ') {
            end--;
        }
        // for (int i = n - 1; i >= 0; i--) {
        //     if (s[i] != ' ') {
        //         end = i + 1;
        //         break;
        //     }
        // }
        return {begin, end};
    }
};
