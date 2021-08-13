// 剑指 Offer 04. 二维数组中的查找
// https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/

#include <vector>
using namespace std;

// TODO: redo
class Solution {
   public:
    // 线性查找: 站在右上角看。这个矩阵其实就像是一个Binary Search Tree
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0, col = m - 1;
        while (row < n && col >= 0) {
            int num = matrix[row][col];
            if (num == target) {
                return true;
            } else if (num < target) {
                row += 1;
            } else {
                col -= 1;
            }
        }
        return false;
    }
};
