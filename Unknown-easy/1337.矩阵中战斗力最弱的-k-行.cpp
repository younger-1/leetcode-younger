/*
 * @lc app=leetcode.cn id=1337 lang=cpp
 *
 * [1337] 矩阵中战斗力最弱的 K 行
 */

// @lc code=start
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<int> force(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j]) {
                    force[i]++;
                }
            }
        }
        priority_queue<pair<int, int>> arm;
        for (int i = 0; i < n; i++) {
            arm.push({-force[i], -i});
        }
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            ans[i] = -arm.top().second;
            arm.pop();
        }
        return ans;
    }
};
// @lc code=end

// @binary-search
class Solution_1 {
   public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<pair<int, int>> power;
        for (int i = 0; i < m; ++i) {
            int l = 0, r = n - 1, pos = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (mat[i][mid] == 0) {
                    r = mid - 1;
                } else {
                    pos = mid;
                    l = mid + 1;
                }
            }
            power.emplace_back(pos + 1, i);
        }

        priority_queue q(greater<pair<int, int>>(), move(power));
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};
