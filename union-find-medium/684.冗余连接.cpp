/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
   private:
    vector<int> parent;

   public:
    int Find(int idx) {
        if (parent[idx] != idx) {
            parent[idx] = Find(parent[idx]);
        }
        return parent[idx];
    }

    void Union(int a, int b) { parent[Find(a)] = Find(b); }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
        for (auto& edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            if (Find(node1) != Find(node2)) {
                Union(node1, node2);
            } else {
                return edge;
            }
        }
        return vector<int>{};
    }
};
// @lc code=end

#include <numeric>

class UnionFind {
   private:
    vector<int> id;

   public:
    UnionFind(int n) : id(n) {
        // iota函数可以把数组初始化为0到n-1
        iota(id.begin(), id.end(), 0);
    }
    int find(int x) {
        if (x != id[x]) {
            id[x] = find(id[x]);
        }
        return id[x];
    }
    void connect(int a, int b) { id[find(a)] = find(b); }
};

class Solution_1 {
   public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n + 1);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            if (uf.find(u) == uf.find(v)) {
                return e;
            }
            uf.connect(u, v);
        }
        return {};
    }
};
