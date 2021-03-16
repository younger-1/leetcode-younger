/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start

// 20/20 cases passed (4 ms)
// Your runtime beats 33.31 % of cpp submissions
// Your memory usage beats 51.89 % of cpp submissions (6.5 MB)
class Solution {
   private:
    static constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

   public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int row, col = 0;
        int index = 0;
        int total = n * n;
        int i = 1;
        while (i <= total) {
            res[row][col] = i;
            i += 1;
            int _row = row + directions[index][0];
            int _col = col + directions[index][1];
            if (_row < 0 || _row >= n || _col < 0 || _col >= n || res[_row][_col] != 0) {
                // 顺时针旋转至下一个方向
                index = (index + 1) % 4;
            }
            row += directions[index][0];
            col += directions[index][1];
        }
        return res;
    }
};

// @lc code=end

int main() {
    Solution* s = new Solution();
    auto v = s->generateMatrix(3);
    for (auto vv : v) {
        for (auto i : vv) {
            cout << i << " ";
        }
    }
}
