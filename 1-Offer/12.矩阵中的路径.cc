// 剑指 Offer 12. 矩阵中的路径
// https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/
// 注意：本题与主站 79 题相同：https://leetcode-cn.com/problems/word-search/

#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(board, word, 0, i, j, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

   private:
    bool dfs(vector<vector<char>>& board, string& word, int idx, int row, int col, vector<vector<bool>>& visited) {
        if (!in_board(board, row, col) || board[row][col] != word[idx] || visited[row][col]) {
            return false;
        }
        if (idx == word.size() - 1) {
            return true;
        }
        visited[row][col] = true;
        int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto& [i, j] : direction) {
            int r = row + i;
            int c = col + j;
            if (dfs(board, word, idx + 1, r, c, visited)) {
                return true;
            }
        }
        visited[row][col] = false;
        return false;
    }
    bool in_board(vector<vector<char>>& board, int r, int c) {
        return 0 <= r && r < board.size() && 0 <= c && c < board[0].size();
    }
};

/*
 * 修改 board 代替额外的 visited
 * 将 board[i][j] 修改为 空字符 '\0' 或 空白符 ' '，代表此元素已访问过，防止之后搜索时重复访问。
 */
class Solution_1 {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }

   private:
    int rows, cols;
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
        if (i >= rows || i < 0 || j >= cols || j < 0 || board[i][j] != word[k])
            return false;
        if (k == word.size() - 1)
            return true;
        board[i][j] = '\0';
        bool res = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) ||
                   dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i, j - 1, k + 1);
        board[i][j] = word[k];
        return res;
    }
};
