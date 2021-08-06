/*
 * @lc app=leetcode.cn id=802 lang=cpp
 *
 * [802] 找到最终的安全状态
 */

#include <unordered_set>
#include <vector>

using namespace std;

// @lc code=start

// Wrong: [[1,2],[],[1]]
class Solution_0 {
   public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            unordered_set<int> visi{i};
            if (odd(i, graph, visi)) {
                res.push_back(i);
            }
        }
        return res;
    }

   private:
    bool odd(int id, vector<vector<int>>& graph, unordered_set<int> visi) {
        int m = graph[id].size();
        for (int i = 0; i < m; i++) {
            if (visi.count(graph[id][i])) {
                return false;
            }
            visi.insert(graph[id][i]);
            if (!odd(graph[id][i], graph, visi)) {
                return false;
            }
        }
        return true;
    }
};

// @lc code=end

#include <functional>

// 深度优先搜索 + 三色标记法
// https://leetcode-cn.com/problems/find-eventual-safe-states/solution/zhao-dao-zui-zhong-de-an-quan-zhuang-tai-yzfz/
class Solution_1 {
   public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n);

        function<bool(int)> safe = [&](int x) {
            if (color[x] > 0) {
                return color[x] == 2;
            }
            color[x] = 1;
            for (int y : graph[x]) {
                if (!safe(y)) {
                    return false;
                }
            }
            color[x] = 2;
            return true;
        };

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (safe(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

#include <queue>

// TODO: redo
// @topological-sort
class Solution_2 {
   public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        // 反图，邻接表存储
        vector<vector<int>> rg(n);
        vector<int> inDeg(n);
        for (int x = 0; x < n; ++x) {
            for (int y : graph[x]) {
                rg[y].push_back(x);
            }
            // 原数组记录的节点出度，在反图中就是入度
            inDeg[x] = graph[x].size();
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int y = q.front();
            q.pop();
            for (int x : rg[y]) {
                if (--inDeg[x] == 0) {
                    q.push(x);
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (inDeg[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
