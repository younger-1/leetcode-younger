/*
 * @lc app=leetcode.cn id=789 lang=cpp
 *
 * [789] 逃脱阻碍者
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        vector<int> source(2);
        int distance = dist(source, target);
        for (auto& ghost : ghosts) {
            int ghostDistance = dist(ghost, target);
            if (ghostDistance <= distance) {
                return false;
            }
        }
        return true;
    }

   private:
    int dist(vector<int>& point1, vector<int>& point2) {
        return abs(point1[0] - point2[0]) + abs(point1[1] - point2[1]);
    }
};
// @lc code=end
