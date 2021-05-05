/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */
using namespace std;
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

// @lc code=start
class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        int nums = 0;
        int height = grid.size();
        int width = grid[0].size();
        std::set<int> visited;
        for (int i = 0; i != height; i++) {
            for (int j = 0; j != width; j++) {
                //找到一个‘1’，广度优先搜索把‘1’所在的岛屿全加入已访问
                if ('1' == grid[i][j] &&
                    visited.end() == visited.find(width * i + j)) {
                    nums++;
                    std::queue<int> q;
                    q.push(width * i + j);
                    visited.insert(width * i + j);
                    while (!q.empty()) {
                        int current = q.front();
                        q.pop();
                        int row = current / width;
                        int col = current % width;
                        if (row != 0 && '1' == grid[row - 1][col])
                            if (visited.end() ==
                                visited.find(width * (row - 1) + col)) {
                                q.push(width * (row - 1) + col);
                                visited.insert(width * (row - 1) + col);
                            }
                        if (row != height - 1 && '1' == grid[row + 1][col])
                            if (visited.end() ==
                                visited.find(width * (row + 1) + col)) {
                                q.push(width * (row + 1) + col);
                                visited.insert(width * (row + 1) + col);
                            }
                        if (col != 0 && '1' == grid[row][col - 1])
                            if (visited.end() ==
                                visited.find(width * row + col - 1)) {
                                q.push(width * row + col - 1);
                                visited.insert(width * row + col - 1);
                            }
                        if (col != width - 1 && '1' == grid[row][col + 1])
                            if (visited.end() ==
                                visited.find(width * row + col + 1)) {
                                q.push(width * row + col + 1);
                                visited.insert(width * row + col + 1);
                            }
                    }
                }
            }
        }
        return nums;
    }
};
// @lc code=end
