/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */
#include <string>
#include <vector>

using namespace std;

// @lc code=start

// 30/30 cases passed (24 ms)
// Your runtime beats 48.36 % of cpp submissions
// Your memory usage beats 60.52 % of cpp submissions (11.7 MB)
class Solution {
   private:
    vector<vector<int>> res;
    // 回溯
    void dfs(const vector<vector<int>>& graph, int start, vector<int>& path) {
        path.push_back(start);
        int n = graph.size();
        if (start == n - 1) {
            res.push_back(path);
            path.pop_back();
            return;
        }
        for (int neighbor : graph[start]) {
            dfs(graph, neighbor, path);
        }
        path.pop_back();
    }

   public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        dfs(graph, 0, path);
        return res;
    }
};
// @lc code=end

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/all-paths-from-source-to-target/solution/suo-you-ke-neng-de-lu-jing-by-leetcode-s-iyoh/
class Solution_1 {
   public:
    vector<vector<int>> ans;
    vector<int> stk;

    void dfs(vector<vector<int>>& graph, int x, int n) {
        if (x == n) {
            ans.push_back(stk);
            return;
        }
        for (auto& y : graph[x]) {
            stk.push_back(y);
            dfs(graph, y, n);
            stk.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        stk.push_back(0);
        dfs(graph, 0, graph.size() - 1);
        return ans;
    }
};
