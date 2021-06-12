/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start

// 执行用时： 296 ms , 在所有 C++ 提交中击败了 18.66% 的用户
// 内存消耗： 8.9 MB , 在所有 C++ 提交中击败了 36.65% 的用户
class Solution {
   public:
    int numSquares(int n) {
        vector<int> f(n + 1, INT_MAX);
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                f[i] = min(f[i], f[i - j * j] + 1);
            }
            // cout << f[i] << endl;
        }
        return f[n];
    }
};
// @lc code=end

int main() {
    auto s = Solution();
    cout << s.numSquares(12);
}