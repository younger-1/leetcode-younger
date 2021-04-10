/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */
#include <vector>

using namespace std;

// @lc code=start

// 1013/1013 cases passed (4 ms)
// Your runtime beats 40.99 % of cpp submissions
// Your memory usage beats 67.37 % of cpp submissions (5.8 MB)
class Solution {
   public:
    bool isUgly(int n) {
        if (n <= 0) {
            return false;
        }
        vector<int> factors{2, 3, 5};
        for (int factor : factors) {
            while (n % factor == 0) {
                n /= factor;
            }
        }
        return n == 1;
    }
};
// @lc code=end
