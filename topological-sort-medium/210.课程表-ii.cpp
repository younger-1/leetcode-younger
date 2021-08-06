/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

#include <queue>
#include <vector>

using namespace std;

// @lc code=start

// @topological-sort
class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> inDegree(numCourses);
        for (auto& v : prerequisites) {
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
            int x = q.front();
            q.pop();
            res.push_back(x);
            for (int y : g[x]) {
                inDegree[y]--;
                if (inDegree[y] == 0) {
                    q.push(y);
                }
            }
        }
        if (numCourses != res.size()) {
            return {};
        }
        return res;
    }
};
// @lc code=end

int main() {
    auto s = Solution();
    vector<vector<int>> v{{1, 0}};
    s.findOrder(2, v);
}
