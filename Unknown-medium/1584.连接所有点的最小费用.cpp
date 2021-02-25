/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class DisjointSetUnion {
   private:
    vector<int> father, size;
    int n;

   public:
    DisjointSetUnion(int _n) {
        n = _n;
        size.resize(n, 1);
        father.resize(n);
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
    }

    int find(int x) { return father[x] == x ? x : father[x] = find(father[x]); }

    bool unionSet(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            return false;
        }
        if (size[fx] < size[fy]) {
            swap(fx, fy);
        }
        size[fx] += size[fy];
        father[fy] = fx;
        return true;
    }
};

struct Edge {
    int len, x, y;
    Edge(int len, int x, int y) : len(len), x(x), y(y) {}
};

class Solution {
   public:
    // 72/72 cases passed (612 ms)
    // Your runtime beats 32.35 % of cpp submissions
    // Your memory usage beats 46.79 % of cpp submissions (56.8 MB)
    int minCostConnectPoints(vector<vector<int>>& points) {
        auto dist = [&](int x, int y) -> int {
            return abs(points[x][0] - points[y][0]) +
                   abs(points[x][1] - points[y][1]);
        };
        int n = points.size();
        DisjointSetUnion dsu(n);
        vector<Edge> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                edges.emplace_back(dist(i, j), i, j);
            }
        }
        sort(edges.begin(), edges.end(),
             [](Edge a, Edge b) -> int { return a.len < b.len; });
        int ret = 0, num = 0;
        for (auto& [len, x, y] : edges) {
            if (dsu.unionSet(x, y)) {
                ret += len;
                num++;
                if (num == n - 1) {
                    break;
                }
            }
        }
        return ret;
    }
};
// @lc code=end
