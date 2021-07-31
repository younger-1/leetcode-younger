/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

#include <vector>

using namespace std;

// @lc code=start

// @lc code=end
#include <numeric>

class UnionFind {
   private:
    vector<int> id;

   public:
    UnionFind(int n) : id(n) { iota(id.begin(), id.end(), 0); }
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
