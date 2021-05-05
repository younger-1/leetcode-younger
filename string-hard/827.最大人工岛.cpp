/*
 * @lc app=leetcode.cn id=827 lang=cpp
 *
 * [827] 最大人工岛
 */
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
struct UnionFind {
    vector<int> nodes, sizes;
    int maxsize = 0;
    UnionFind(int size) : nodes(size), sizes(size, 1) { iota(nodes.begin(), nodes.end(), 0); }
    int find(int node) {
        if (nodes[node] != node)
            return nodes[node] = find(nodes[node]);
        else
            return nodes[node];
    }
    int merge(int node1, int node2) {
        int f1 = find(node1), f2 = find(node2);
        if (f1 == f2)
            return false;
        if (sizes[f1] > sizes[f2])
            swap(f1, f2);
        maxsize = max(maxsize, sizes[f2] += sizes[f1]);
        nodes[f1] = f2;
        return true;
    }
};

class Solution {
   public:
#define node(x, y) ((x)*n + (y))
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        UnionFind uf(m * n);
        int island_maxsize = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (!grid[i][j])
                    continue;
                island_maxsize = 1;
                if (i + 1 < m && grid[i + 1][j])
                    uf.merge(node(i, j), node(i + 1, j));
                if (j + 1 < n && grid[i][j + 1])
                    uf.merge(node(i, j), node(i, j + 1));
            }

        int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        island_maxsize = max(island_maxsize, uf.maxsize);
        unordered_map<int, int> neighbor;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (grid[i][j])
                    continue;
                for (auto& d : dirs) {
                    int nx = i + d[0], ny = j + d[1];
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || !grid[nx][ny])
                        continue;
                    int fa = uf.find(node(nx, ny));
                    neighbor[fa] = uf.sizes[fa];
                }
                int sumsize = 1;
                for (auto [com, size] : neighbor)
                    sumsize += size;
                island_maxsize = max(sumsize, island_maxsize);
                neighbor.clear();
            }

        return island_maxsize;
    }
};
// @lc code=end
