/*
 * @lc app=leetcode.cn id=1713 lang=cpp
 *
 * [1713] 得到子序列的最少操作次数
 */

#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start

// TODO: redo
// @greedy @binary-search
class Solution {
   public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        // 将 target 中的元素转换成下标
        // 【最长公共子序列】问题变为求 arr 转换成 target 中的下标后的【最长递增子序列】
        unordered_map<int, int> pos;
        for (int i = 0; i < n; ++i) {
            pos[target[i]] = i;
        }
        vector<int> d;
        for (int val : arr) {
            if (pos.count(val)) {
                int idx = pos[val];
                auto it = lower_bound(d.begin(), d.end(), idx);
                if (it != d.end()) {
                    *it = idx;
                } else {
                    d.push_back(idx);
                }
            }
        }
        return n - d.size();
    }
};

// @lc code=end

// Time out
// From [1143] 最长公共子序列
class Solution_0 {
   public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        int m = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (target[i - 1] == arr[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return n - dp[n][m];
    }
};
