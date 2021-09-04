/*
 * @lc app=leetcode.cn id=1928 lang=cpp
 *
 * [1928] 规定时间内到达终点的最小花费
 */

#include <climits>
#include <vector>

using namespace std;

// @lc code=start

// TODO: redo
// like [787] K 站中转内最便宜的航班
class Solution {
   private:
    const int MAX = 1000 * 1000 + 1;

   public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<int>> f(maxTime + 1, vector<int>(n + 1, MAX));
        f[0][0] = passingFees[0];
        for (int t = 1; t <= maxTime; t++) {
            for (auto& edge : edges) {
                int i = edge[0], j = edge[1], cost = edge[2];
                if (cost <= t) {
                    f[t][i] = min(f[t][i], f[t - cost][j] + passingFees[i]);
                    f[t][j] = min(f[t][j], f[t - cost][i] + passingFees[j]);
                }
            }
        }
        int ans = MAX;
        for (int t = 1; t <= maxTime; t++) {
            ans = min(ans, f[t][n - 1]);
        }
        return ans == MAX ? -1 : ans;
    }
};

// @lc code=end
