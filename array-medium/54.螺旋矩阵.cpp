/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start

// 22/22 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 77.89 % of cpp submissions (6.7 MB)
class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        vector<int> res;
        int i = 0, j = -1;
        while (top <= bottom && left <= right) {
            while (j < right) {
                j += 1;
                res.push_back(matrix[i][j]);
            }
            top += 1;
            if (top > bottom) {
                break;
            }

            while (i < bottom) {
                i += 1;
                res.push_back(matrix[i][j]);
            }
            right -= 1;
            if (left > right) {
                break;
            }

            while (j > left) {
                j -= 1;
                res.push_back(matrix[i][j]);
            }
            bottom -= 1;
            if (top > bottom) {
                break;
            }

            while (i > top) {
                i -= 1;
                res.push_back(matrix[i][j]);
            }
            left += 1;
            if (left > right) {
                break;
            }
        }
        return res;
    }
};
// @lc code=end

// TODO: redo
// 执行用时： 8 ms , 在所有 C++ 提交中击败了 93.68% 的用户
// 内存消耗： 9.4 MB , 在所有 C++ 提交中击败了 89.41% 的用户
class Solution_1 {
   private:
    static constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

   public:
    // 初始位置是矩阵的左上角，初始方向是向右，当路径超出界限或者进入之前访问过的位置时，顺时针旋转，进入下一个方向
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }
        int rs = matrix.size(), cs = matrix[0].size();

        int r = 0, c = 0, idx = 0;
        int total = rs * cs;
        vector<int> order(total);
        vector<vector<bool>> visited(rs, vector<bool>(cs));
        for (int i = 0; i < total; i++) {
            order[i] = matrix[r][c];
            visited[r][c] = true;
            int rr = r + directions[idx][0], cc = c + directions[idx][1];
            if (rr < 0 || rr >= rs || cc < 0 || cc >= cs || visited[rr][cc]) {
                idx += 1;
                idx %= 4;
            }
            r += directions[idx][0];
            c += directions[idx][1];
        }
        return order;
    }
};

int main() {
    Solution* s = new Solution();
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    s->spiralOrder(matrix);
}
