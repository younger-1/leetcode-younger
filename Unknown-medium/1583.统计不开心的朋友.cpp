/*
 * @lc app=leetcode.cn id=1583 lang=cpp
 *
 * [1583] 统计不开心的朋友
 */

#include <vector>

using namespace std;

// @lc code=start

// TODO: redo
// @simulation
class Solution {
   public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<vector<int>> order(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                // j 为距离，越小越亲密
                order[i][preferences[i][j]] = j;
            }
        }

        vector<int> match(n);
        for (const auto& pr : pairs) {
            match[pr[0]] = pr[1];
            match[pr[1]] = pr[0];
        }

        int ans = 0;
        for (int x = 0; x < n; x++) {
            int y = match[x];
            int dist = order[x][y];
            for (int i = 0; i < dist; i++) {
                // order[x][u] < dist
                int u = preferences[x][i];
                int v = match[u];
                if (order[u][x] < order[u][v]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
