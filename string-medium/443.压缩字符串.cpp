/*
 * @lc app=leetcode.cn id=443 lang=cpp
 *
 * [443] 压缩字符串
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start

// TODO: redo
// @two-pointer
class Solution {
   public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int len = 0;
        for (int i = 0, cnt = 1; i < n; i++, cnt++) {
            if (i + 1 == chars.size() || chars[i] != chars[i + 1]) {
                chars[len++] = chars[i];
                if (cnt > 1) {
                    for (char ch : to_string(cnt)) {
                        chars[len++] = ch;
                    }
                }
                cnt = 0;
            }
        }
        return len;
    }
};
// @lc code=end

int main() {
    auto s = Solution();
    vector<char> cs{'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int ans = s.compress(cs);
    for (int i = 0; i < ans; i++) {
        cout << cs[i] << ' ';
    }
}
