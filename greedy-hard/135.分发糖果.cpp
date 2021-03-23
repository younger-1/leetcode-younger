/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */
#include <numeric>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        for (int i = 1; i < n; i++) {
            // 右比左高
            if (ratings[i - 1] < ratings[i]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            // 左比右高
            if (ratings[i + 1] < ratings[i]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
// @lc code=end
