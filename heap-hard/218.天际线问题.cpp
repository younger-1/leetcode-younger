/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

// @lc code=start

// 40/40 cases passed (32 ms)
// Your runtime beats 87.34 % of cpp submissions
// Your memory usage beats 81.24 % of cpp submissions (14.2 MB)
class Solution_1 {
   public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> xhs;
        multiset<int> heights;
        vector<vector<int>> res;

        // 1、将每一个建筑分成“两个部分”，例如:[2,9,10]可以转换成[2-10] [9,10]，我们用负值来表示左边界
        for (auto& b : buildings) {
            xhs.push_back({b[0], -b[2]});
            xhs.push_back({b[1], b[2]});
        }

        // 2、排序
        sort(xhs.begin(), xhs.end());
        // 保证地面的天际线能找到
        heights.insert(0);

        // 3、遍历
        int pre = 0, curHighest = 0;
        for (auto xh : xhs) {
            if (xh.second < 0) {
                heights.insert(-xh.second);
            } else {
                heights.erase(heights.find(xh.second));
            }
            curHighest = *heights.rbegin();
            if (curHighest != pre) {
                res.push_back({xh.first, curHighest});
                pre = curHighest;
            }
        }
        return res;
    }
};
// @lc code=end
