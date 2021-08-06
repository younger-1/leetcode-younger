/*
 * @lc app=leetcode.cn id=847 lang=cpp
 *
 * [847] 访问所有节点的最短路径
 */

#include <queue>
#include <tuple>
#include <vector>

using namespace std;

// @lc code=start

// TODO: redo
// 状态压缩 + 广度优先搜索
// https://leetcode-cn.com/problems/shortest-path-visiting-all-nodes/solution/fang-wen-suo-you-jie-dian-de-zui-duan-lu-mqc2/
class Solution_1 {
   public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        // id, bit(状态压缩), dist
        queue<tuple<int, int, int>> q;
        vector<vector<bool>> seen(n, vector<bool>(1 << n));
        for (int i = 0; i < n; i++) {
            q.emplace(i, 1 << i, 0);
            seen[i][1 << i] = true;
        }
        int ans = 0;
        while (!q.empty()) {
            auto [id, bit, dist] = q.front();
            q.pop();
            if (bit == (1 << n) - 1) {
                ans = dist;
                break;
            }
            for (int v : graph[id]) {
                // 异或：重复访问的点无影响
                // 更改点v状态为 1
                int bit_new = bit | (1 << v);
                if (!seen[v][bit_new]) {
                    seen[v][bit_new] = true;
                    q.emplace(v, bit_new, dist + 1);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

class Solution_11 {
   public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        // id, bit(状态压缩), dist
        queue<tuple<int, int, int>> q;
        vector<vector<bool>> seen(n, vector<bool>(1 << n));
        for (int i = 0; i < n; i++) {
            q.emplace(i, 1 << i, 0);
        }
        int ans = 0;
        while (!q.empty()) {
            auto [id, bit, dist] = q.front();
            q.pop();
            // --- 效率低些 ---
            if (seen[id][bit]) {
                continue;
            }
            seen[id][bit] = true;
            // ---------------
            if (bit == (1 << n) - 1) {
                ans = dist;
                break;
            }
            for (int v : graph[id]) {
                // 异或：重复访问的点无影响
                // 更改点v状态为 1
                int bit_new = bit | (1 << v);
                q.emplace(v, bit_new, dist + 1);
            }
        }
        return ans;
    }
};

// 预处理点对间最短路 + 状态压缩动态规划
