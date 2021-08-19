// 剑指 Offer 58 - I. 翻转单词顺序
// https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/
// 注意：本题与主站 151 题相同：https://leetcode-cn.com/problems/reverse-words-in-a-string/

#include <sstream>
#include <string>
#include <vector>

using namespace std;

// 执行用时： 4 ms , 在所有 C++ 提交中击败了 89.56% 的用户
// 内存消耗： 9.2 MB , 在所有 C++ 提交中击败了 21.85% 的用户
class Solution_0 {
   public:
    string reverseWords(string s) {
        int n = s.length();
        vector<string> v;
        int start = 0, end = 0;
        while (end != n) {
            while (start < n && s[start] == ' ') {
                start++;
            }
            if (start == n) {
                break;
            }
            end = s.find(' ', start);
            if (end == -1) {
                end = n;
            }
            v.push_back(s.substr(start, end - start));
            start = end;
        }
        // s == "" || s == "  "
        if (v.empty()) {
            return "";
        }

        string ans;
        for (int i = v.size() - 1; i > 0; i--) {
            ans += v[i] + " ";
        }
        return ans += v[0];
    }
};

class Solution_1 {
   public:
    string reverseWords(string s) {
        string res, temp;
        stringstream ss(s);
        while (ss >> temp) {
            res = temp + " " + res;
        }
        res.pop_back();
        return res;
    }
};
