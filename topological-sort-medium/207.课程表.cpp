/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */
#include <queue>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses);
        vector<vector<int>> g(numCourses, vector<int>());
        for (auto v : prerequisites) {
            g[v[1]].push_back(v[0]);
            inDegree[v[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> res;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            res.push_back(u);
            for (int v : g[u]) {
                if (--inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return numCourses == res.size();
    }
};
// @lc code=end
