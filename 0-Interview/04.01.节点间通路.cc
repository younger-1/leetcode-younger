// 面试题 04.01. 节点间通路
// https://leetcode-cn.com/problems/route-between-nodes-lcci/

#include <unordered_set>
#include <vector>

using namespace std;

// TODO: redo
class Solution {
   public:
    // n 为图中节点数
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        edge.resize(n);
        for (auto& e : graph)
            edge[e[0]].insert(e[1]);
        return dfs(start, target);
    }

   private:
    vector<unordered_set<int>> edge;
    unordered_set<int> visited;
    bool dfs(int cur, int target) {
        if (visited.count(cur))
            return false;
        visited.insert(cur);
        if (cur == target)
            return true;
        for (auto v : edge[cur]) {
            if (dfs(v, target))
                return true;
        }
        return false;
    }
};

#include <iostream>

int main() {
    vector<vector<int>> graph{{0, 1}, {1, 3}, {3, 2}, {2, 5}, {4, 5}};
    auto s = Solution();
    cout << s.findWhetherExistsPath(6, graph, 0, 5);
}
