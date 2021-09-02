/*
 * @lc app=leetcode.cn id=787 lang=cpp
 *
 * [787] K 站中转内最便宜的航班
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start

// TODO: redo
// 链接：https://leetcode-cn.com/problems/cheapest-flights-within-k-stops/solution/k-zhan-zhong-zhuan-nei-zui-bian-yi-de-ha-abzi/
class Solution {
   private:
    static constexpr int INF = 10000 * 100 + 1;

   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // 用 f[t][i] 表示通过恰好 t 次航班，从出发城市 src 到达城市 i 需要的最小花费。
        vector<vector<int>> f(k + 2, vector<int>(n, INF));
        f[0][src] = 0;
        // k 站中转对应 k+1 次航班
        for (int t = 1; t <= k + 1; t++) {
            for (auto& flight : flights) {
                int i = flight[0], j = flight[1], cost = flight[2];
                f[t][j] = min(f[t][j], f[t - 1][i] + cost);
            }
        }
        int ans = INF;
        for (int t = 1; t <= k + 1; ++t) {
            ans = min(ans, f[t][dst]);
        }
        return (ans == INF ? -1 : ans);
    }
};
// @lc code=end

// Time out
class Solution_0 {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        res = TOP;
        n_ = n;
        vector<vector<int>> dist(n, vector<int>(n, TOP));
        for (auto f : flights) {
            dist[f[0]][f[1]] = f[2];
        }
        dfs(dist, 0, src, dst, k);
        if (res == TOP) {
            return -1;
        }
        return res;
    }

   private:
    const int TOP = 1e4 + 1;
    int res, n_;
    void dfs(vector<vector<int>>& dist, int sum, int src, int dst, int k) {
        if (src == dst) {
            res = min(res, sum);
            return;
        }
        if (k == -1) {
            return;
        }
        for (int i = 0; i < n_; i++) {
            dfs(dist, sum + dist[src][i], i, dst, k - 1);
        }
    }
};
