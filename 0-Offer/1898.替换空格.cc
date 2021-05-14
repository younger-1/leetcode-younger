// 剑指 Offer 05. 替换空格
// https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/

#include <string>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string t;
        for (char c : s) {
            if (c == ' ') {
                t += "%20";
                // t.push_back('%');
                // t.push_back('2');
                // t.push_back('0');
            } else {
                t += c;
                // t.push_back(c);
            }
        }
        return t;
    }
};
