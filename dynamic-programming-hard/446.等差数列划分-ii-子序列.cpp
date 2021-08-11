/*
 * @lc app=leetcode.cn id=446 lang=cpp
 *
 * [446] 等差数列划分 II - 子序列
 */

#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start

// TODO: redo
// @DP
class Solution {
   public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        // 考虑至少有两个元素的等差子序列，下文将其称作弱等差子序列
        // 定义状态 f[i][d] 表示尾项为 nums[i]，公差为 d 的弱等差子序列的个数
        // 公差的范围很大，将状态转移数组 f 的第二维用哈希表代替
        vector<unordered_map<long, int>> f(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long d = 1L * nums[i] - nums[j];
                auto it = f[j].find(d);
                int cnt = it == f[j].end() ? 0 : it->second;
                ans += cnt;
                // f[i][d](弱等差的数目) = f[j][d](真等差的数目) + 1(假等差的数目)
                f[i][d] += cnt + 1;
            }
        }
        return ans;
    }
};

// @lc code=end
