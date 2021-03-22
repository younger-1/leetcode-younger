/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */
#include <vector>

using namespace std;

// @lc code=start

// 164/164 cases passed (12 ms)
// Your runtime beats 94.42 % of cpp submissions
// Your memory usage beats 71.67 % of cpp submissions (12.9 MB)
class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int col_0 = false;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                col_0 = true;
            }
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // 从最后一行开始，避免清除第一行的标记
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
            if (col_0) {
                matrix[i][0] = 0;
            }
        }
    }
};
// @lc code=end
